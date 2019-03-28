#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    minX = -0.25;
    maxX = 0.25;
    incrX = 0.05;
    // generate some data:
    vx = new std::vector<double>();
    vy = new std::vector<double>();
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      vx->push_back(i/50.0 - 1);
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      vy->push_back(x[i]*x[i]);
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->nest->addGraph();
    ui->nest->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->nest->xAxis->setLabel("x");
    ui->nest->yAxis->setLabel("y");
    // set axes ranges, so we see the data:
    ui->nest->xAxis->setRange(minX, maxX);
    ui->nest->yAxis->setRange(0, 1);
    ui->nest->replot();
}

Widget::~Widget()
{
    delete ui;
    delete vx;
    delete vy;
}

void Widget::replot(){
    QVector<double> x(int(vx->size())), y(int(vx->size()));
    for (unsigned long i = 0; i < vx->size(); i++){
      x[int(i)] = vx->at(i); // update x
      y[int(i)] = vy->at(i); // update y
    }
    // reassign data:
    ui->nest->graph(0)->setData(x, y);
    ui->nest->replot();
}

void Widget::on_move_left_clicked(){
    minX -= 0.1;
    maxX -= 0.1;
    ui->nest->xAxis->setRange(minX, maxX);
    ui->nest->yAxis->setRange(0, 1);
    ui->nest->replot();
}

void Widget::on_move_right_clicked(){
    minX += 0.1;
    maxX += 0.1;
    ui->nest->xAxis->setRange(minX, maxX);
    ui->nest->yAxis->setRange(0, 1);
    ui->nest->replot();
}

void Widget::on_pushButton_clicked()
{
    QString x = ui->lineEditX->text();
    QString y = ui->lineEditY->text();
    vx->push_back(x.toDouble());
    vy->push_back(y.toDouble());
    replot();
}
