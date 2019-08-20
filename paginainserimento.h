#ifndef PAGINAINSERIMENTO_H
#define PAGINAINSERIMENTO_H
#include "QWidget"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>

class paginainserimento: public QWidget
{
Q_OBJECT
private:
    QHBoxLayout *ins;
    QVBoxLayout *s;
    QVBoxLayout *d;
    QPushButton *ciao;
public:
    paginainserimento(QWidget *parent);

};

#endif // PAGINAINSERIMENTO_H
