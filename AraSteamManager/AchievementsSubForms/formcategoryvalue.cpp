#include "formcategoryvalue.h"
#include "ui_formcategoryvalue_2.h"

//Добавить проверку на то, что такая ачивка уже есть  и  убрать удаление элемента если кидаешь его на другий элемент
FormCategoryValue::FormCategoryValue(QWidget *parent): QWidget(parent), ui(new Ui::FormCategoryValue) {
    ui->setupUi(this);
    ui->ListViewValue->setModel(new QStandardItemModel());
    ui->ListViewValue->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->ListViewValue->setDefaultDropAction(Qt::DropAction::MoveAction);
    ui->ListViewValue->setDragEnabled(true);
    ui->ListViewValue->setAcceptDrops(true);
    ui->ListViewValue->setDropIndicatorShown(true);
    ui->ListViewValue->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->ListViewValue->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ListViewValue->setWordWrap(true);

    connect(ui->ListViewValue, &QListView::customContextMenuRequested, this, [=](QPoint pos) {
        QModelIndex index = ui->ListViewValue->currentIndex();
        if (index.isValid()) {
            QMenu *menu = createMenu(index);
            menu->popup(ui->ListViewValue->viewport()->mapToGlobal(pos));
        }
    });

    setIcons();
}

FormCategoryValue::~FormCategoryValue() {
    delete ui;
}

void FormCategoryValue::setTitle(const QString &aTitle) {
    ui->LineEditTitle->setText(aTitle);
}

void FormCategoryValue::setAchievements(QList<SAchievement> &aAchievements, const int &aGameId) {
    int row = 0;
    QFont font(Settings::getFontDefaultName(), 9);
    QStandardItemModel *model = new QStandardItemModel();
    for (auto &achievement: aAchievements) {
        QStandardItem *item = new QStandardItem();
        item->setData(achievement.getIcon(aGameId).scaled(32, 32), Qt::DecorationRole);
        item->setText(achievement._displayName);
        item->setData(achievement._description, Qt::ToolTipRole);
        item->setData(achievement._apiName, Qt::WhatsThisRole);
        item->setFont(font);
        model->setItem(row, item);
        ++row;
    }
    ui->ListViewValue->setModel(model);
}

void FormCategoryValue::setIcons() {
    ui->ButtonReverse       ->setIcon(QIcon(Images::reverse()));
    ui->ButtonFirst         ->setIcon(QIcon(Images::first()));
    ui->ButtonBack          ->setIcon(QIcon(Images::back()));
    ui->ButtonNext          ->setIcon(QIcon(Images::next()));
    ui->ButtonLast          ->setIcon(QIcon(Images::last()));
    ui->ButtonAddVisible    ->setIcon(QIcon(Images::checkVisible()));
    ui->ButtonRemoveVisible ->setIcon(QIcon(Images::uncheckVisible()));
    ui->ButtonDelete        ->setIcon(QIcon(Images::deleteIcon()));
}

QString FormCategoryValue::getTitle() const {
    return ui->LineEditTitle->text();
}

QList<QString> FormCategoryValue::getAchievements() const {
    QList<QString> list;
    for(int i = 0; i < ui->ListViewValue->model()->rowCount(); ++i) {
        auto index = ui->ListViewValue->model()->index(i, 0);
        QString appId = ui->ListViewValue->model()->data(index, Qt::WhatsThisRole).toString();
        if (!list.contains(appId)) {
            list.append(appId);
        }
    }
    return list;
}

void FormCategoryValue::on_ButtonDelete_clicked() {
    emit s_deleteValue();
}

void FormCategoryValue::on_ButtonFirst_clicked() {
    emit s_goFirst();
}

void FormCategoryValue::on_ButtonBack_clicked() {
    emit s_goBack();
}

void FormCategoryValue::on_ButtonNext_clicked() {
    emit s_goNext();
}

void FormCategoryValue::on_ButtonLast_clicked() {
    emit s_goLast();
}

void FormCategoryValue::on_ButtonAddVisible_clicked() {

}

void FormCategoryValue::on_ButtonRemoveVisible_clicked() {

}

void FormCategoryValue::on_ButtonReverse_clicked() {

}

QMenu *FormCategoryValue::createMenu(QModelIndex aIndex) {
    Q_UNUSED(aIndex);
    //Кнопка удаления достижения
    QAction *actionDeleteAchievement = new QAction(tr("Удалить достижение"), this);
    //actionAchievements->setIcon(QIcon(Images::achievement()));

    //Кнопка удаления всех достижений
    QAction *actionDeleteAllAchievements = new QAction(tr("Удалить все достижения"), this);
    //actionDeleteAllAchievements->setIcon(QIcon(Images::deleteAll()));

    //Кнопка перемещения значения в начало
    QAction *actionMoveFirst = new QAction(tr("Переместить значение в начало"), this);
    actionMoveFirst->setIcon(QIcon(Images::first()));

    //Кнопка перемещения значения в начало
    QAction *actionMoveBack = new QAction(tr("Переместить значение назад"), this);
    actionMoveBack->setIcon(QIcon(Images::back()));

    //Кнопка перемещения значения в начало
    QAction *actionMoveNext = new QAction(tr("Переместить значение вперед"), this);
    actionMoveNext->setIcon(QIcon(Images::next()));

    //Кнопка перемещения значения в начало
    QAction *actionMoveLast = new QAction(tr("Переместить значение в конец"), this);
    actionMoveLast->setIcon(QIcon(Images::last()));

    //Кнопка удаления значения
    QAction *actionDelete = new QAction(tr("Удалить значение"), this);
    actionDelete->setIcon(QIcon(Images::deleteIcon()));

    QMenu *menu = new QMenu(this);
    menu->addAction (actionDeleteAchievement);
    menu->addAction (actionDeleteAllAchievements);
    menu->addAction (actionMoveFirst);
    menu->addAction (actionMoveBack);
    menu->addAction (actionMoveNext);
    menu->addAction (actionMoveLast);
    menu->addAction (actionDelete);

    //connect (actionDeleteAchievement,       &QAction::triggered,    this,   &FormCategoryValue_2::buttonAchievements_Clicked);
    //connect (actionDeleteAllAchievements,   &QAction::triggered,    this,   &FormCategoryValue_2::buttonFavorite_Clicked);
    connect (actionMoveFirst,               &QAction::triggered,    this,   &FormCategoryValue::on_ButtonFirst_clicked);
    connect (actionMoveBack,                &QAction::triggered,    this,   &FormCategoryValue::on_ButtonBack_clicked);
    connect (actionMoveNext,                &QAction::triggered,    this,   &FormCategoryValue::on_ButtonNext_clicked);
    connect (actionMoveLast,                &QAction::triggered,    this,   &FormCategoryValue::on_ButtonLast_clicked);
    connect (actionDelete,                  &QAction::triggered,    this,   &FormCategoryValue::on_ButtonDelete_clicked);

    return menu;
}
