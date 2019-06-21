#ifndef FOURBARLINKAGE_H
#define FOURBARLINKAGE_H

#include <QString>
#include <QPair>
#include <QPointF>
#include <QVector>
#include <QFile>

class FourBarLinkage
{
public:

    enum Type {
        grashof_type1 = 0x0,
        grashof_type2,
        grashof_type3
    };

    enum Configuration {
        open,
        close
    };

    FourBarLinkage();
    void setSize(double _l1, double _l2, double _l3, double _l4);
    void setCouplerSize(double _l5, double _beta);
    void setConfiguration(Configuration _conf);

    Type getType();

    QPair<double,double> compute(double theta2); //Return theta3, theta4 tuple
    QVector<QPointF> getPositions(double theta2); //returns O2 O4 A B
    void computeCouplerPoints(/*OUT*/ QVector<QPointF> &spoints_out, int points=360);

    QString typeToString(Type t);
    void serialize(QFile& file);

private:
    Configuration configuration;
    double l1;
    double l2;
    double l3;
    double l4;
    /* coupler data */
    double l5;
    double beta;
};

#endif // FOURBARLINKAGE_H
