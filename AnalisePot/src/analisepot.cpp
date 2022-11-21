#include "analisepot.h"
#include "ui_analisepot.h"

AnalisePot::AnalisePot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnalisePot)
{
    ui->setupUi(this);

    ui->customplot->addGraph();
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customplot->yAxis2->setVisible(true);
    ui->customplot->xAxis->setLabel("tempo");
    ui->customplot->yAxis->setLabel("corrente");
    ui->customplot->yAxis2->setLabel("temperatura");
    ui->customplot->xAxis->setRange(0,6000);
    ui->customplot->yAxis->setRange(0,200);
    ui->customplot->yAxis2->setRange(0,200);

    ui->customplot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectPlottables);
}

AnalisePot::~AnalisePot()
{
    delete ui;
}

