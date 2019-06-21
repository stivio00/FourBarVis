#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#include "settings.h"
#include "about.h"

#include <QDebug>
#include <QPaintEngine>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    delta_theta2 = 1.0;
    zoom = 1.0;
    ui->setupUi(this);
    poli = nullptr;
    coupler = nullptr;
    ui->graphicsView->setScene(new QGraphicsScene(ui->graphicsView));
    ui->graphicsView->setMatrix(QMatrix(1,0,0,-1,0,0));
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
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
    fourBarLinkage.setSize(ui->doubleSpinBox->value(), //l1
                           ui->doubleSpinBox_2->value(),//l2
                           ui->doubleSpinBox_3->value(),//l3
                           ui->doubleSpinBox_4->value());//l4
    fourBarLinkage.setCouplerSize(ui->doubleSpinBox_5->value(),
                                  ui->doubleSpinBox_6->value()*M_PI/180.0);
    if (ui->radioButton->isChecked()){
        fourBarLinkage.setConfiguration(FourBarLinkage::Configuration::open);
    } else {
        fourBarLinkage.setConfiguration(FourBarLinkage::Configuration::close);
    }
    ui->label_5->setText("Grashof type: "+fourBarLinkage.typeToString(fourBarLinkage.getType()));
    ui->statusBar->showMessage("UPDATED");
}

void MainWindow::draw()
{
    draw(ui->horizontalSlider->value());
}

void MainWindow::draw(double ang)
{
    auto theta2 = ang;
    QVector<QPointF> R = fourBarLinkage.getPositions(theta2);

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

    ui->statusBar->showMessage("Ready");
}

void MainWindow::nextStep()
{
    ui->horizontalSlider->setValue(ui->horizontalSlider->value()+static_cast<int>(delta_theta2));
    if(ui->horizontalSlider->value() >= 360.0)
        ui->horizontalSlider->setValue(0);
    draw();
}

void MainWindow::save_file(const QString& file_name)
{
    QFile file(file_name);
    file.open(QFile::OpenModeFlag::WriteOnly);
    fourBarLinkage.serialize(file);
    file.flush();
    file.close();
}

void MainWindow::open_file(const QString& file_name)
{
    QFile file(file_name);
    file.open(QFile::OpenModeFlag::ReadOnly);
    QString in = QString::fromLatin1(file.readAll());
    auto list = in.split(",");
    qDebug() << list;
    ui->doubleSpinBox->setValue(list.at(0).toDouble());
    ui->doubleSpinBox_2->setValue(list.at(1).toDouble());
    ui->doubleSpinBox_3->setValue(list.at(2).toDouble());
    ui->doubleSpinBox_4->setValue(list.at(3).toDouble());
    ui->doubleSpinBox_5->setValue(list.at(4).toDouble());
    ui->doubleSpinBox_6->setValue(list.at(5).toDouble());
    file.close();
    qDebug()<<"OPEN ME";
}

void MainWindow::on_actionUpdate_triggered()
{
    update();
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
    update();
    auto scene = ui->graphicsView->scene();
    fourBarLinkage.computeCouplerPoints(points);

    if (coupler == nullptr) {
        coupler = scene->addPolygon(QPolygonF(points));
    } else {
        coupler->setPolygon(QPolygonF(points));
    }
}


void MainWindow::on_lineEdit_textChanged(const QString& /*&arg1*/)
{
    //ui->horizontalSlider->setValue(arg1.toInt());
}



void MainWindow::on_radioButton_toggled(bool /*checked*/)
{
    update();
    draw();
}

void MainWindow::on_doubleSpinBox_5_valueChanged(const QString &/*arg1*/)
{
    update();
    draw();
}

void MainWindow::on_doubleSpinBox_6_valueChanged(const QString &/*arg1*/)
{
    update();
    draw();
}

void MainWindow::on_doubleSpinBox_valueChanged(const QString &/*arg1*/)
{
    update();
    draw();
}

void MainWindow::on_doubleSpinBox_2_valueChanged(const QString &/*arg1*/)
{
    update();
}

void MainWindow::on_doubleSpinBox_3_valueChanged(const QString &/*arg1*/)
{
    update();
    draw();
}

void MainWindow::on_doubleSpinBox_4_valueChanged(const QString &/*arg1*/)
{
    update();
    draw();
}

void MainWindow::on_actionSave_triggered()
{

    QFileDialog dialog;
    dialog.setAcceptMode(QFileDialog::AcceptMode::AcceptSave);
    connect(&dialog, &QFileDialog::fileSelected,this, &MainWindow::save_file);
    dialog.exec();
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::FileMode::ExistingFiles);
    dialog.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);
    connect(&dialog, &QFileDialog::fileSelected,this, &MainWindow::open_file);
    dialog.exec();
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    delta_theta2 = ui->lineEdit_2->text().toDouble();
    ui->label_12->setText("speed: "+QString::number(delta_theta2/(timer->interval())*1000)+" grad/s");
}

void MainWindow::on_lineEdit_3_editingFinished()
{
    timer->setInterval(ui->lineEdit_3->text().toInt());
    ui->label_12->setText("speed: "+QString::number(delta_theta2/(timer->interval())*1000)+" grad/s");
}

void MainWindow::on_pushButton_2_clicked()
{
    zoom += 0.05;
    QMatrix s(zoom,0,0,-zoom,0,0);
    ui->graphicsView->setMatrix(s);
}

void MainWindow::on_pushButton_3_clicked()
{
    zoom -= 0.05;
    QMatrix s(zoom,0,0,-zoom,0,0);
    ui->graphicsView->setMatrix(s);
}

void MainWindow::on_pushButton_4_clicked()
{
    zoom = 1;
    QMatrix s(zoom,0,0,-zoom,0,0);
    ui->graphicsView->setMatrix(s);
    //ui->graphicsView->scene()->clear();
    //poli = nullptr;
}
