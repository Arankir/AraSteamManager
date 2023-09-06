#include "categoriesmodel.h"

#include <QMimeData>
#include <QModelIndex>

CategoriesModel::CategoriesModel(Category *aCategory, QObject *parent): QAbstractItemModel(parent), rootItem_{aCategory} {
    update();
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
        if (item->size() > 0) {
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

    Category *item = getItem(index);
    if (item != nullptr) {
        if (item->count() > 0) {
            return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | QAbstractItemModel::flags(index);
        } else {
            return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEditable | QAbstractItemModel::flags(index);
        }
    } else {
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    }
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

bool CategoriesModel::insertRows(int position, const QModelIndex &parent, const QString &aTitle) {
    if (aTitle.isEmpty()) {
        return false;
    }
    if (getItem(parent)->find(aTitle) != nullptr) {
        return false;
    }
    bool success = insertRows(position, 1, parent);
    if (success) {
        setData(index(getItem(parent)->categories().count() - 1, 0, parent), aTitle);
        return true;
    }
    return false;
}

bool CategoriesModel::insertRows(int aPosition, int aCount, const QModelIndex &aParent) {
    Q_UNUSED(aCount);
    Category *parentItem = getItem(aParent);
    if (!parentItem)
        return false;

    beginInsertRows(aParent, aPosition, aPosition);
    Category *category = new Category(rootItem_->gameID(), rootItem_->gameName(), rootItem_->gameIcon(), false);
    bool success = parentItem->addCategory(category);
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

    if (Category *parent = parentItem->parent()) {
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

bool CategoriesModel::removeColumns(int position, int count, const QModelIndex &parent) {
    Q_UNUSED(position);
    Q_UNUSED(count);
    Q_UNUSED(parent);
    return false;
}

bool CategoriesModel::removeRows(int position, int count, const QModelIndex &parent) {
    Q_UNUSED(count);
    Category *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    QList<Category*> categories = parentItem->categories();
    if (categories.count() > position) {
        Category *childItem = categories.at(position);
        beginRemoveRows(parent, position, position);
        parentItem->removeCategory(childItem->title(), true);
        endRemoveRows();
        parentItem->root()->save();
        return true;
    } else {
        qWarning() << "error categories size is " << QString::number(categories.size()) << ", find " << QString::number(position);
        return false;
    }
}

bool CategoriesModel::removeAllCategories(const QModelIndex &aParent) {
    while (getItem(aParent)->categories().count() > 0) {
        removeAllCategories(index(0, 0, aParent));
    }
    if (getItem(aParent)->categories().count() == 0) {
        removeRows(aParent.row(), 1, parent(aParent));
        return true;
    }
    return true;
}

bool CategoriesModel::removeAllCategories() {
    QModelIndex index = parent(this->index(0, 0));
    while (getItem(index)->categories().count() > 0) {
        removeAllCategories(this->index(0, 0, index));
    }
    return true;
}

bool CategoriesModel::saveCategories() {
    return rootItem_->save();
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
    if (role != Qt::EditRole && role != Qt::DisplayRole && role != Qt::CheckStateRole)
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
            QList<Category*> cat = item->parent()->categories();
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

//    qDebug() << row << parent.isValid() << parent.row() << rowCount(QModelIndex()) << beginRow;

    QByteArray encoded = data->text().toUtf8();
    QDataStream stream(&encoded, QIODevice::ReadOnly);
    while (!stream.atEnd()) {
        int oldRow, oldCol;
        QStringList path;
        stream >> oldRow >> oldCol >> path;

        Category *category = rootItem_->root()->find(path);
        if (category) {
            Category *categoryNewParent = getItem(parent);
            QList<Category*> newParentCategories = categoryNewParent->categories();
            bool isEqualTitle = std::any_of(newParentCategories.begin(),
                                         newParentCategories.end(),
                                         [=](Category *lCategory) {
                                            return lCategory->title() == category->title() && lCategory != category;
                                         });
            if (isEqualTitle) {
                emit s_error(tr("У одной категории не может быть 2 подкатегории с одинаковым именем!"));
            } else {
                QModelIndex index = createIndex(getRowFromParent(category->parent()), oldCol, category->parent());
//                qDebug() << index << getItem(index) << getItem(index)->title() << oldRow;
//                qDebug() << parent << getItem(parent) << getItem(parent)->title() << beginRow;
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

void CategoriesModel::setGame(const SGame &aGame) {
    rootItem_->setGame(aGame);
    update();
}

void CategoriesModel::update() {
    rootItem_->update();
}
