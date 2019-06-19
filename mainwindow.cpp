#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#include "settings.h"
#include "about.h"

#include <QDebug>
#include <QPaintEngine>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    poli = nullptr;
    coupler = nullptr;
    ui->graphicsView->setScene(new QGraphicsScene(ui->graphicsView));
    ui->graphicsView->setMatrix(QMatrix(1,0,0,-1,0,0));

    timer = new QTimer(this);
    timer->setInterval(5);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));
    update();
    draw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    fourBarLinkage.setSize(ui->doubleSpinBox->value(),
                           ui->doubleSpinBox_2->value(),
                           ui->doubleSpinBox_3->value(),
                           ui->doubleSpinBox_4->value());

}

void MainWindow::draw()
{
    draw(ui->horizontalSlider->value());
}

void MainWindow::draw(double ang)
{
    auto theta2 = ang;
    FourBarLinkage::Configuration conf;
    if (ui->radioButton->isChecked()){
        conf = FourBarLinkage::Configuration::open;
    } else {
        conf = FourBarLinkage::Configuration::close;
    }
    QVector<QPointF> R = fourBarLinkage.getPositions(theta2, conf);

    auto l5 = ui->doubleSpinBox_5->value();
    auto beta = ui->doubleSpinBox_6->value()*M_PI/180.0;
    auto theta3 = std::atan2((R[2]-R[1]).y(), (R[2]-R[1]).x());

    QPointF P(l5*std::cos(beta+theta3), l5*std::sin(beta+theta3));
    P = P + R[1];

    auto scene = ui->graphicsView->scene();
    if (poli == nullptr) {
        poli = scene->addPolygon(QPolygonF(R));

        circleA = scene->addEllipse(-5,-5 , 10,10);
        circleB = scene->addEllipse(-5,-5 , 10,10);
        circleO2 = scene->addEllipse(-5,-5 , 10,10);
        circleO4 = scene->addEllipse(-5,-5 , 10,10);
        circleP = scene->addEllipse(-5,-5 , 10,10);

        textA = scene->addText("A");
        textA->setMatrix(QMatrix(1,0,0,-1,0,0));
        textB = scene->addText("B");
        textB->setMatrix(QMatrix(1,0,0,-1,0,0));
        textO2 = scene->addText("O2");
        textO2->setMatrix(QMatrix(1,0,0,-1,0,0));
        textO4 = scene->addText("O4");
        textO4->setMatrix(QMatrix(1,0,0,-1,0,0));
        textP = scene->addText("P");
        textP->setMatrix(QMatrix(1,0,0,-1,0,0));
    }
    poli->setPolygon(QPolygonF(R));
    circleA->setPos(R[1]);
    circleB->setPos(R[2]);
    circleO2->setPos(R[0]);
    circleO4->setPos(R[3]);
    circleP->setPos(P);
    textA->setPos(R[1]);
    textB->setPos(R[2]);
    textO2->setPos(R[0]);
    textO4->setPos(R[3]);
    textP->setPos(P);

    if (ui->doubleSpinBox_5->value() == 0.0) {
        textP->setVisible(false);
        circleP->setVisible(false);
    } else {
        textP->setVisible(true);
        circleP->setVisible(true);
    }

    ui->statusBar->showMessage("theta2:"+QString::number(ang));
}

void MainWindow::nextStep()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+1);
    if(ui->horizontalSlider->value() >= 360)
        ui->horizontalSlider->setValue(0);
    draw();
}

void MainWindow::on_actionUpdate_triggered()
{
    update();
    ui->label_5->setText("Grashof type: "+fourBarLinkage.typeToString(fourBarLinkage.getType()));
    draw();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    draw(position);
    ui->lineEdit->setText(QString::number(position));
}

void MainWindow::on_doubleSpinBox_valueChanged(double/* arg1*/)
{
    update();
    draw();
}

void MainWindow::on_actionPlay_triggered()
{
    timer->start();
}

void MainWindow::on_actionStop_triggered()
{
    timer->stop();
}

void MainWindow::on_actionSettings_triggered()
{
    auto s = new Settings;
    s->setVisible(true);
}

void MainWindow::on_actionAbout_triggered()
{
    auto about = new About;
    about->setVisible(true);
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double/* arg1*/)
{
    update();
    draw();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    QVector<QPointF> points;
    auto l5 = ui->doubleSpinBox_5->value();
    auto beta = ui->doubleSpinBox_6->value()*M_PI/180.0;
    auto scene = ui->graphicsView->scene();

    FourBarLinkage::Configuration conf;
    if (ui->radioButton->isChecked()){
        conf = FourBarLinkage::Configuration::open;
    } else {
        conf = FourBarLinkage::Configuration::close;
    }

    fourBarLinkage.computeCouplerPoints(l5, beta, points, conf);

    if (coupler == nullptr) {
        coupler = scene->addPolygon(QPolygonF(points));
    } else {
        coupler->setPolygon(QPolygonF(points));
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    //ui->horizontalSlider->setValue(arg1.toInt());
}
