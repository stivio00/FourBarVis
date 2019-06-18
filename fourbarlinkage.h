#ifndef FOURBARLINKAGE_H
#define FOURBARLINKAGE_H

#include <QString>
#include <QPair>
#include <QPointF>
#include <QVector>

class FourBarLinkage
{
public:

    enum Type {
        grashof_type1 = 0x0,
        grashof_type2,
        grashof_type3
    };

    FourBarLinkage();
    void setSize(double _l1, double _l2, double _l3, double _l4);
    Type getType();

    QPair<double,double> compute(double theta2); //Return theta3, theta4 tuple
    QVector<QPointF> getPositions(double theta2); //returns O2 O4 A B
    QString typeToString(Type t);
    void computeCouplerPoints(double l5, double beta, /*OUT*/ QVector<QPointF> &spoints_out, int points=360);

    void safe_file(QString path);
    void load_file(QString path);

private:
    double l1;
    double l2;
    double l3;
    double l4;
};

#endif // FOURBARLINKAGE_H
