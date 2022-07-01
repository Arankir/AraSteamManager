#include "categoriesmodel.h"
#include "subWidgets/items/categoryitem.h"

#include <QMimeData>
#include <QModelIndex>

CategoriesModel::CategoriesModel(Category *aCategory, QObject *parent): QAbstractItemModel(parent), rootItem_{aCategory} {
    updateData(aCategory);
}

CategoriesModel::~CategoriesModel() {
    delete rootItem_;
}

int CategoriesModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 1;
}

QVariant CategoriesModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole && role != Qt::CheckStateRole)
        return QVariant();

    Category *item = getItem(index);

    switch (static_cast<Qt::ItemDataRole>(role)) {
    case Qt::DisplayRole: {
        return item->title();
    }
    case Qt::CheckStateRole: {
        if (item->categories().size() > 0) {
            if (isChecked_.find(item) != isChecked_.end()) {
                return Qt::Checked;
            } else {
                return Qt::Unchecked;
            }
        } else {
            return QVariant();
        }
    }
    default: {
        return QVariant();
    }
    }
}

Qt::ItemFlags CategoriesModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;

    auto item = getItem(index);
    if (item != nullptr) {
        if (item->count() > 0) {
            return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | QAbstractItemModel::flags(index);
        }
    } else {
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    }

    return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

Qt::DropActions CategoriesModel::supportedDropActions() const {
    return Qt::CopyAction | Qt::MoveAction;
}

Category *CategoriesModel::getItem(const QModelIndex &index) const {
    if (index.isValid()) {
        Category *item = static_cast<Category*>(index.internalPointer());
        if (item) {
            return item;
        }
        return rootItem_;
    }
    return rootItem_;
}

QVariant CategoriesModel::headerData(int section, Qt::Orientation orientation, int role) const {
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(role);
    return QVariant();
}

QModelIndex CategoriesModel::index(int row, int column, const QModelIndex &parent) const {
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    Category *parentItem = getItem(parent);
    if (!parentItem)
        return QModelIndex();

    QList<Category*> categories = parentItem->categories();
    if (categories.size() > row) {
        Category *childItem = categories.at(row);
        if (childItem)
            return createIndex(row, column, childItem);
        return QModelIndex();
    } else {
        qWarning() << QString("error categories size is %1, find %2").arg(QString::number(categories.size()), QString::number(row));
        return QModelIndex();
    }

}

bool CategoriesModel::insertColumns(int position, int columns, const QModelIndex &parent) {
    Q_UNUSED(position);
    Q_UNUSED(columns);
    Q_UNUSED(parent);
    return false;
}

bool CategoriesModel::insertRows(int position, int columns, const QModelIndex &parent) {
    Q_UNUSED(columns);
    Category *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    beginInsertRows(parent, position, position);
    const bool success = parentItem->addCategory(new Category(rootItem_->gameID(), rootItem_->gameName()));
    endInsertRows();

    return success;
}

QModelIndex CategoriesModel::parent(const QModelIndex &index) const {
    if (!index.isValid())
        return QModelIndex();

    Category *childItem = getItem(index);
    Category *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == rootItem_ || parentItem == nullptr)
        return QModelIndex();

    if (auto parent = parentItem->parent()) {
        return createIndex(parent->categories().indexOf(const_cast<Category*>(parentItem)), 0, parentItem);
    } else {
        return QModelIndex();
    }
}

int getRowFromParent(Category *aCategory) {
    if (aCategory->parent()) {
        return aCategory->parent()->getIndex(aCategory);
    } else {
        return -1;
    }
}

bool CategoriesModel::removeColumns(int position, int columns, const QModelIndex &parent) {
    Q_UNUSED(position);
    Q_UNUSED(columns);
    Q_UNUSED(parent);
    return false;
}

bool CategoriesModel::removeRows(int position, int columns, const QModelIndex &parent) {
    Q_UNUSED(columns);
    Category *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    QList<Category*> categories = parentItem->categories();
    if (categories.size() > position) {
        Category *childItem = categories.at(position);
        beginRemoveRows(parent, position, position);
        parentItem->removeCategory(childItem->title());
        endRemoveRows();
        return true;
    } else {
        qWarning() << "error categories size is " << QString::number(categories.size()) << ", find " << QString::number(position);
        return false;
    }
}

bool CategoriesModel::removeCategory(Category *aCategory) {
    QStringList path = aCategory->getPathFromRoot();
    if (!rootItem_->find(path)) {
        emit s_error(tr("Попытка удалить категорию не из текущей модели"));
        return false;
    }
    int rowFromParent = getRowFromParent(aCategory);
    if (rowFromParent > -1) {
        int rowParent = getRowFromParent(aCategory->parent());
        QModelIndex index;
        if (rowParent == -1) {
            index = index(0, 0);
        } else {
            index = createIndex(rowParent, 0, aCategory->parent());
        }
        beginRemoveRows(index, rowFromParent, rowFromParent);
        auto cat = aCategory->parent();
        qDebug() << *cat;
        if (aCategory->root()->removeCategory(path)) {
            delete aCategory;
            qDebug() << *cat;
            endRemoveRows();
            return true;
        } else {
            endRemoveRows();
            return false;
        }
    } else {
        return false;
    }
}

bool CategoriesModel::removeAllCategories() {
    QModelIndex index = createIndex(0, 0, rootItem_);
    beginRemoveRows(index, 0, rootItem_->countCategories() - 1);
    rootItem_->deleteAllCategories();
    endRemoveRows();
    return true;
}

bool CategoriesModel::saveCategories() {
    return rootItem_->save();
}

bool CategoriesModel::insertCategory(Category *aCategory, const QStringList &aList) {
    Category *parent = rootItem_->find(aList);
    if (parent) {
        QModelIndex index = createIndex(getRowFromParent(parent), 0, parent);
        beginInsertRows(index, parent->categories().size(), parent->categories().size());
        aCategory->setParent(parent);
        endInsertRows();
        return true;
    } else {
        return false;
    }
}

int CategoriesModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid() && parent.column() > 0)
        return 0;

    const Category *parentItem = getItem(parent);

    if (parentItem) {
        return parentItem ? parentItem->categories().count() : 0;
    } else {
        return 0;
    }
}

bool CategoriesModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role != Qt::EditRole && role != Qt::DisplayRole && role != Qt::CheckStateRole) //Вылетает если драгндропнуть межну категориями
        return false;
    Category *item = getItem(index);
    bool result = false;
    switch (static_cast<Qt::ItemDataRole>(role)) {
    case Qt::EditRole: {
        if (value.toString().isEmpty()) {
            emit s_error(tr("У категории должно быть название!"));
            return false;
        }
        if (item->parent() != nullptr) {
            auto cat = item->parent()->categories();
            auto iterator = std::find_if(cat.begin(),
                                         cat.end(),
                                         [=](Category *lChild) {
                                            return lChild->title() == value.toString();
                                         });
            if (iterator != cat.end()) {
                emit s_error(tr("Категория с таким названием уже сужествует!"));
                return false;
            }
        }
        item->setTitle(value.toString());
        result = item->root()->save();
        break;
    }
    case Qt::CheckStateRole: {
        if (isChecked_.find(item) != isChecked_.end()) {
            isChecked_.remove(item);
        } else {
            isChecked_.insert(item);
        }
        result = true;
        emit s_checkStateChanged(item, value.toBool());
        break;
    }
    default: {
        result = false;
    }
    }

    if (result)
        emit dataChanged(index, index);

    return result;
}

bool CategoriesModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false;
}

// Filling datas for moved objects
QMimeData *CategoriesModel::mimeData(const QModelIndexList &indexes) const {
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    for(const QModelIndex &index: indexes) {
        stream << index.row() << index.column() << getItem(index)->getPathFromRoot();
    }
    QMimeData* mimeData = QAbstractItemModel::mimeData(indexes);
    mimeData->setText(QString::fromUtf8(data));
    return mimeData;
}

bool CategoriesModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) {
    if(!canDropMimeData(data, action, row, column, parent))
        return false;

    if (action == Qt::IgnoreAction)
        return true;

    int beginRow;
    if (row != -1)
        beginRow = row;
    else if (parent.isValid())
        beginRow = parent.row();
    else
        beginRow = rowCount(QModelIndex());

    qDebug() << row << parent.isValid() << parent.row() << rowCount(QModelIndex()) << beginRow;

    QByteArray encoded = data->text().toUtf8();
    QDataStream stream(&encoded, QIODevice::ReadOnly);
    while (!stream.atEnd()) {
        int oldRow, oldCol;
        QStringList path;
        stream >> oldRow >> oldCol >> path;

        auto category = rootItem_->root()->find(path);
        if (category) {
            auto categoryNewParent = getItem(parent);
            auto newParentCategories = categoryNewParent->categories();
            bool isEqualTitle = std::any_of(newParentCategories.begin(),
                                         newParentCategories.end(),
                                         [=](Category *lCategory) {
                                            return lCategory->title() == category->title() && lCategory != category;
                                         });
            if (isEqualTitle) {
                emit s_error(tr("У одной категории не может быть 2 подкатегории с одинаковым именем!"));
            } else {
                QModelIndex index = createIndex(getRowFromParent(category->parent()), oldCol, category->parent());
                qDebug() << index << getItem(index) << getItem(index)->title() << oldRow;
                qDebug() << parent << getItem(parent) << getItem(parent)->title() << beginRow;
                if (index != parent || oldRow != beginRow) {
                    beginMoveRows(index, oldRow, oldRow, parent, beginRow);
                    category->setParent(categoryNewParent);
                    categoryNewParent->changeCategoryIndex(category->title(), beginRow);
                    endMoveRows();
                }
            }
        }
    }
    return false;
}

void CategoriesModel::updateData(Category *parent) {
    parent->update();
}
