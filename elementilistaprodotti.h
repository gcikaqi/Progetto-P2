#ifndef ELEMENTILISTAPRODOTTI_H
#define ELEMENTILISTAPRODOTTI_H

#include <QListWidgetItem>
#include<QPushButton>


#include "computer.h"
#include "smartablet.h"
#include "fisso.h"
#include "portatile.h"
#include "tablet.h"
#include "smartphone.h"


class elementilistaprodotti : public QListWidgetItem
{
private:
    QWidget* parent;//puntatore a qwidget che sarà il mio widget per inserire i dati
    itembase* oggetto;//puntatore polimorfo al mio oggetto
public:
    elementilistaprodotti(QWidget*, itembase* = NULL);//costrtuttore
    itembase* prelevaItem() const;//serve per prendere il mio item da inserire poi
    void update();
};


#endif // ELEMENTILISTAPRODOTTI_H
