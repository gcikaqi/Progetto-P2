#ifndef LAYOUTCAMPICOMPUTER_H
#define LAYOUTCAMPICOMPUTER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>


class layoutcampicomputer : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampicomputer;
    QCheckBox * schedavideoo;
    QLineEdit * schedavideonomee;
public:
    layoutcampicomputer(QWidget * parent);

};

#endif // LAYOUTCAMPICOMPUTER_H
