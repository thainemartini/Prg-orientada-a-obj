#include "analisepot.h"
#include "ui_analisepot.h"
#include <QFileDialog>
#include <QtCore>
#include <QDebug>
#include <QDir>
//#include "xlsxdocument.h"


//int X1,X2,X3,X4,X5,X6,X7,Y1,Y2,Y3,Y4,Y5,Y6,Y7;

AnalisePot::AnalisePot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnalisePot)


{
    ui->setupUi(this);

    connect(ui->M1,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->M2,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->M3,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->M4,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->M5,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->M6,SIGNAL(released()),this,SLOT(binary_button_pressed()));
    connect(ui->TEMP,SIGNAL(released()),this,SLOT(binary_button_pressed()));

    ui->M1->setCheckable(true);
    ui->M2->setCheckable(true);
    ui->M3->setCheckable(true);
    ui->M4->setCheckable(true);
    ui->M5->setCheckable(true);
    ui->M6->setCheckable(true);
    ui->TEMP->setCheckable(true);

    ui->customplot->addGraph();
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
   // ui->customplot->graph(0)->setData(x,y);
    ui->customplot->yAxis2->setVisible(true);
    ui->customplot->xAxis->setLabel("Tempo");
    ui->customplot->yAxis->setLabel("Corrente");
    ui->customplot->yAxis2->setLabel("Temperatura");
    ui->customplot->xAxis->setRange(0,6000);
    ui->customplot->yAxis->setRange(0,200);
    ui->customplot->yAxis2->setRange(0,200);

    ui->customplot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectPlottables);
}

AnalisePot::~AnalisePot()
{
    delete ui;
}


void AnalisePot::binary_button_pressed()
{
    QPushButton * button =(QPushButton*)sender();
    button -> setChecked(true);
}


void AnalisePot::on_ENTER_released()
{

    if (ui->M1->isChecked())
    {

       ui->M1->setChecked(false);

    }
    if (ui->M2->isChecked())
    {

        ui->M2->setChecked(false);

    }
    else if (ui->M3->isChecked())
    {
        ui->M3->setChecked(false);

    }
    else if (ui->M4->isChecked())
    {
        ui->M4->setChecked(false);

    }
    else if (ui->M5->isChecked())
    {
        ui->M5->setChecked(false);

    }
    else if (ui->M6->isChecked())
    {
        ui->M6->setChecked(false);

    }
    else if (ui->TEMP->isChecked())
    {
        ui->TEMP->setChecked(false);

    }

    if ((ui->M1->isChecked()) || (ui->M2->isChecked()) ||(ui->M3->isChecked()) || (ui->M4->isChecked()) ||(ui->M5->isChecked()) ||(ui->M6->isChecked()) ||(ui->TEMP->isChecked()))
    {
        ui->M1->setChecked(false);
        ui->M2->setChecked(false);
        ui->M3->setChecked(false);
        ui->M4->setChecked(false);
        ui->M5->setChecked(false);
        ui->M6->setChecked(false);
        ui->TEMP->setChecked(false);
    }

}

