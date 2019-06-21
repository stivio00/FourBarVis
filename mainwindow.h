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

    //Open/Save Handlers
    void save_file(const QString& file);
    void open_file(const QString& file);

    //Actions Control
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

    //Configuration control
    void on_radioButton_toggled(bool checked);
    void on_doubleSpinBox_5_valueChanged(const QString &arg1);
    void on_doubleSpinBox_6_valueChanged(const QString &arg1);
    void on_doubleSpinBox_valueChanged(const QString &arg1);
    void on_doubleSpinBox_2_valueChanged(const QString &arg1);
    void on_doubleSpinBox_3_valueChanged(const QString &arg1);
    void on_doubleSpinBox_4_valueChanged(const QString &arg1);

    //Open/Save Controls
    void on_actionSave_triggered();
    void on_actionOpen_triggered();

    //Speed Controls
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_3_editingFinished();

    //Zoom control
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    FourBarLinkage fourBarLinkage;
    QGraphicsPolygonItem *poli, *coupler;
    QGraphicsEllipseItem *circleA, *circleB, *circleO2, *circleO4, *circleP;
    QGraphicsTextItem *textA, *textB, *textO2, *textO4, *textP;
    QTimer *timer;
    double delta_theta2;
    double zoom;
};

#endif // MAINWINDOW_H
