#ifndef LAYOUTCAMPITABLET_H
#define LAYOUTCAMPITABLET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>


class layoutcampitablet : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampitablet;
    QCheckBox * schedasim;
    QCheckBox * auricolari;
public:
    layoutcampitablet(QWidget * parent);
};

#endif // LAYOUTCAMPITABLET_H
