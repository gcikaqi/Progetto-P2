#ifndef LAYOUTCAMPISMARTPHONE_H
#define LAYOUTCAMPISMARTPHONE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>


class layoutcampismartphone : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampismartphone;
    QCheckBox * memoria_espandibile;
    QCheckBox * dual_sim;
public:
    layoutcampismartphone(QWidget * parent);
};

#endif // LAYOUTCAMPISMARTPHONE_H
