#include "fourbarlinkage.h"
#include <cmath>
#include <algorithm>

#include <QDebug>
#include <QList>

FourBarLinkage::FourBarLinkage()
{

}

void FourBarLinkage::setSize(double _l1, double _l2, double _l3, double _l4)
{
    this->l1 = _l1;
    this->l2 = _l2;
    this->l3 = _l3;
    this->l4 = _l4;
}

FourBarLinkage::Type FourBarLinkage::getType()
{
    QList<double> l{l1,l2,l3,l4};
    std::sort(l.begin(), l.end());
    double S = l.at(0);
    double L = l.at(3);
    double P = l.at(1);
    double Q = l.at(2);
    if (S+L < P+Q)
        return Type::grashof_type1;
    else if (S+L > P+Q)
        return Type::grashof_type2;
    else
        return Type::grashof_type3;
}

QPair<double, double> FourBarLinkage::compute(double theta2, Configuration conf)
{
    auto a = l2;
    auto b = l3;
    auto c = l4;
    auto d = l1;

    auto k1 = d/a;
    auto k2 = d/c;
    auto k3 = (a*a - b*b + c*c + d*d)/(2*a*c);
    auto A = (1.0 - k2) * std::cos(theta2) - k1 + k3;
    auto B = -2.0*std::sin(theta2);
    auto C= k1 -(k2+1)*std::cos(theta2) + k3;

    auto k4 = d/b;
    auto k5 = (c*c - d*d - a*a - b*b)/(2.0*a*b);
    auto D = (1+k4)*std::cos(theta2) - k1 + k5;
    auto E = C;
    auto F = k1 + (k4-1)*std::cos(theta2) + k5;

    double theta3, theta4;
    if (conf == Configuration::open) {
        theta4 = 2.0 * std::atan((-B-std::sqrt(B*B-4.0*A*C)) / (2.0*A));
        theta3 = 2.0 * std::atan((-E-std::sqrt(E*E-4.0*D*F)) / (2.0*D));
    } else if (conf == Configuration::close) {
        theta4 = 2.0 * std::atan((-B+std::sqrt(B*B-4.0*A*C)) / (2.0*A));
        theta3 = 2.0 * std::atan((-E+std::sqrt(E*E-4.0*D*F)) / (2.0*D));
    }

    //qDebug() << "theta4 grad" << theta4*180.0/3.1416;
    return QPair<double,double>(theta4,theta3);
}

QVector<QPointF> FourBarLinkage::getPositions(double theta2)
{
    theta2 = theta2*3.1416/180.0;
    auto thetas = compute(theta2); //needs a rad argument
    //auto theta3 = thetas.second;
    auto theta4 = thetas.first;

    using namespace std;

    QPointF O2 {0.0 ,0.0};
    QPointF O4 {l4, 0.0};
    QPointF A {l2 * cos(theta2), l2 * sin(theta2)};
    QPointF B {l4 * cos(theta4), l4 * sin(theta4)};
    return QVector<QPointF> {O2,A,B+O4,O4};
}

QString FourBarLinkage::typeToString(FourBarLinkage::Type t)
{
    if (t == Type::grashof_type1)
        return "GRASHOF CLASS I";
    else if (t == Type::grashof_type2)
        return "GRASHOF CLASS II";
    else
        return "GRASHOF CLASS III";

}

void FourBarLinkage::computeCouplerPoints(double l5, double beta, QVector<QPointF> &points_out, int points)
{
    /* non-entraant function */
    QVector<QPointF> R;
    points_out.resize(points);
    double theta3, theta2 = 0.0;

    for (int i = 0; i < 360; i++) {
        R = getPositions(theta2);
        theta3 = std::atan2((R[2]-R[1]).y(), (R[2]-R[1]).x());
        points_out[i] = QPointF(l5*std::cos(beta+theta3), l5*std::sin(beta+theta3)) + R[1];
        theta2 += 1.0;
        //qDebug() << i << " theta2:" << theta2 << " PointP: "<< points_out[i];
    }
}

void FourBarLinkage::safe_file(QString path)
{

}

void FourBarLinkage::load_file(QString path)
{

}

