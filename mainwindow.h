#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsPolygonItem>
#include <QTimer>
#include "fourbarlinkage.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void update();
    void draw();
    void draw(double ang);
    void nextStep();

    void on_actionUpdate_triggered();
    void on_horizontalSlider_sliderMoved(int position);
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_actionPlay_triggered();
    void on_actionStop_triggered();
    void on_actionSettings_triggered();
    void on_actionAbout_triggered();
    void on_doubleSpinBox_3_valueChanged(double arg1);
    void on_actionExit_triggered();

    void on_pushButton_clicked();//Draw couple curve


    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    FourBarLinkage fourBarLinkage;
    QGraphicsPolygonItem *poli, *coupler;
    QGraphicsEllipseItem *circleA, *circleB, *circleO2, *circleO4, *circleP;
    QGraphicsTextItem *textA, *textB, *textO2, *textO4, *textP;
    QTimer *timer;
};

#endif // MAINWINDOW_H
