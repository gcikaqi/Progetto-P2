#ifndef LAYOUTCAMPIFISSO_H
#define LAYOUTCAMPIFISSO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>


class layoutcampifisso : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampifisso;
    QCheckBox * tastiera;
public:
    layoutcampifisso(QWidget * parent);
};

#endif // LAYOUTCAMPIFISSO_H
