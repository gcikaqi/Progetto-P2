#ifndef VIEWLISTAPRODOTTI_H
#define VIEWLISTAPRODOTTI_H

#include <QListWidget>
#include <QScrollBar>
#include "elementilistaprodotti.h"

#include "computer.h"
#include "smartablet.h"
#include "fisso.h"
#include "portatile.h"
#include "tablet.h"
#include "smartphone.h"



class viewlistaprodotti: public QListWidget
{
    Q_OBJECT
private:
    QWidget* parent;
public:
    viewlistaprodotti(QWidget* = NULL);
    void aggiungiItem(itembase *);//aggiungere un item passando il puntatore di quell oggetto
    elementilistaprodotti* itemCorrente() const;//da aggiungere item corrente
};


#endif // VIEWLISTAPRODOTTI_H
