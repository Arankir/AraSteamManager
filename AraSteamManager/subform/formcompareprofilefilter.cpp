#include "formcompareprofilefilter.h"
#include "ui_formcompareprofilefilter.h"

FormCompareProfileFilter::FormCompareProfileFilter(QWidget *parent) :
    QWidget(parent),ui(new Ui::FormCompareProfileFilter){
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    QString theme;
    switch(_setting.GetTheme()){
        case 1:
            theme="white";
            break;
        case 2:
            theme="black";
            break;
    }
    ui->RadioButtonAll->setIcon(QIcon("://"+theme+"/all.png"));
    ui->RadioButtonReached->setIcon(QIcon("://"+theme+"/reached.png"));
    ui->RadioButtonNotReached->setIcon(QIcon("://"+theme+"/notreached.png"));
    ui->RadioButtonAll->SetReachedType(ReachedType::all);
    ui->RadioButtonReached->SetReachedType(ReachedType::reached);
    ui->RadioButtonNotReached->SetReachedType(ReachedType::notReached);
    connect(ui->RadioButtonAll,&QRadioButtonWithData::clicked,this,&FormCompareProfileFilter::RadioButtonClick);
    connect(ui->RadioButtonReached,&QRadioButtonWithData::clicked,this,&FormCompareProfileFilter::RadioButtonClick);
    connect(ui->RadioButtonNotReached,&QRadioButtonWithData::clicked,this,&FormCompareProfileFilter::RadioButtonClick);
}

FormCompareProfileFilter::~FormCompareProfileFilter(){
    delete ui;
}
void FormCompareProfileFilter::changeEvent(QEvent *event){
    if(event->type()==QEvent::LanguageChange){
        ui->retranslateUi(this);
    }
}

void FormCompareProfileFilter::SetTitles(QString a_t1, QString a_t2, QString a_t3){
    ui->RadioButtonAll->setText(a_t1);
    ui->RadioButtonReached->setText(a_t2);
    ui->RadioButtonNotReached->setText(a_t3);
}

void FormCompareProfileFilter::SetType(ReachedType a_type){
    switch (a_type) {
    case ReachedType::all:
        ui->RadioButtonAll->setChecked(true);
        ui->RadioButtonAll->click();
        break;
    case ReachedType::reached:
        ui->RadioButtonReached->setChecked(true);
        ui->RadioButtonReached->click();
        break;
    case ReachedType::notReached:
        ui->RadioButtonNotReached->setChecked(true);
        ui->RadioButtonNotReached->click();
        break;
    default:
        break;
    }
}

void FormCompareProfileFilter::Update(){
    if(ui->RadioButtonAll->isChecked()){
        ui->RadioButtonAll->click();
    } else if(ui->RadioButtonReached->isChecked()){
        ui->RadioButtonReached->click();
    } else if(ui->RadioButtonNotReached->isChecked()){
        ui->RadioButtonNotReached->click();
    }
}

void FormCompareProfileFilter::RadioButtonClick(){
    QRadioButtonWithData *rb = static_cast<QRadioButtonWithData*>(sender());
    emit s_radioButtonChange(_name,rb->GetReachedType());
}
