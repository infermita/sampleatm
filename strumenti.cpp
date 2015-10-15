#include "strumenti.h"
#include "ui_strumenti.h"
#include "mainwindow.h"

Strumenti::Strumenti()
{

}

Strumenti::~Strumenti()
{
    killTimer(timerId);
    delete ui;
}

Strumenti::Strumenti(const Strumenti &t){

}
void Strumenti::setWidget(QWidget *parent)
{
    ui = new Ui::Strumenti;
    ui->setupUi(parent);

    QObject::connect(ui->exit, SIGNAL (clicked()),this, SLOT (Exit()),Qt::DirectConnection);

    //SetGauge("tensioneLinea","V",0,1000,100);
    //SetGauge("correnteLinea","A",-500,500,125);
    //SetGauge("velocita","Km/h",0,100,12.5);
    //SetGauge("tensioneBatteria","V",0,40,4);
    //SetGauge("correnteBatteria","A",0,20,2.5);

    timerId = startTimer(1000);

}
void Strumenti::Exit()
{
    MainWindow::getInstance()->setWidget(MainWindow::getInstance()->ObCondotta(),MainWindow::getInstance()->condotta());

}
/*
void Strumenti::SetGauge(QString type,QString label,float min,float max,float step){

    QcGaugeWidget *mAirspeedGauge = new QcGaugeWidget;
    QcDegreesItem *k = mAirspeedGauge->addDegrees(75);
    k->setValueRange(min,max);
    k->setStep(step);
    k->setColor(Qt::yellow);

    QcValuesItem *qc = mAirspeedGauge->addValues(85);
    qc->setValueRange(min,max);
    qc->setStep(step);
    qc->setColor(Qt::yellow);

    QcLabelItem *lb = mAirspeedGauge->addLabel(60);
    lb->setText(label);
    lb->setColor(Qt::yellow);

    QcLabelItem *lab = mAirspeedGauge->addLabel(40);
    lab->setText("0");
    lab->setColor(Qt::yellow);

    if(QString::compare(type,"tensioneLinea")==0){

        tensioneLineaAgo = mAirspeedGauge->addNeedle(60);
        tensioneLineaAgo->setLabel(lab);
        tensioneLineaAgo->setColor(Qt::red);
        tensioneLineaAgo->setValueRange(min,max);
        mAirspeedGauge->addBackground(7);

        ui->tensione_linea->addWidget(mAirspeedGauge);

    }
    if(QString::compare(type,"correnteLinea")==0){

        correnteLineaAgo = mAirspeedGauge->addNeedle(60);
        correnteLineaAgo->setLabel(lab);
        correnteLineaAgo->setColor(Qt::red);
        correnteLineaAgo->setValueRange(min,max);
        mAirspeedGauge->addBackground(7);

        ui->corrente_linea->addWidget(mAirspeedGauge);

    }
    if(QString::compare(type,"velocita")==0){

        velocitaAgo = mAirspeedGauge->addNeedle(60);
        velocitaAgo->setLabel(lab);
        velocitaAgo->setColor(Qt::red);
        velocitaAgo->setValueRange(min,max);
        mAirspeedGauge->addBackground(7);

        ui->velocita->addWidget(mAirspeedGauge);

    }
    if(QString::compare(type,"tensioneBatteria")==0){

        tensioneBatteriaAgo = mAirspeedGauge->addNeedle(60);
        tensioneBatteriaAgo->setLabel(lab);
        tensioneBatteriaAgo->setColor(Qt::red);
        tensioneBatteriaAgo->setValueRange(min,max);
        mAirspeedGauge->addBackground(7);

        ui->tensione_batteria->addWidget(mAirspeedGauge);

    }
    if(QString::compare(type,"correnteBatteria")==0){

        correnteBatteriaAgo = mAirspeedGauge->addNeedle(60);
        correnteBatteriaAgo->setLabel(lab);
        correnteBatteriaAgo->setColor(Qt::red);
        correnteBatteriaAgo->setValueRange(min,max);
        mAirspeedGauge->addBackground(7);

        ui->corrente_batteria->addWidget(mAirspeedGauge);

    }

}
*/
int Strumenti::myrand( unsigned int n, unsigned int m ){

    return qrand() % ((m + 1) - n) + n;

}

void Strumenti::timerEvent(QTimerEvent *event)
{
    ui->tensione_linea->display(myrand(500,550));
    ui->corrente_linea->display(myrand(00,10));
    ui->velocita->display(myrand(20,30));
    ui->tensione_batteria->display(myrand(16,24));
    ui->corrente_batteria->display(myrand(10,15));
    //tensioneLineaAgo->setCurrentValue(myrand(500,550));
    //correnteLineaAgo->setCurrentValue(myrand(00,10));
    //velocitaAgo->setCurrentValue(myrand(20,30));
    //tensioneBatteriaAgo->setCurrentValue(myrand(16,24));
    //correnteBatteriaAgo->setCurrentValue(myrand(10,15));
}
