#include "viewlistaprodotti.h"

viewlistaprodotti::viewlistaprodotti(QWidget* p) :
    parent(p)
{
    //per inserire immagine
    //setIconSize(QSize(150,150));
    //addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
    addScrollBarWidget(new QScrollBar(parent),Qt::AlignRight);
}

void viewlistaprodotti::aggiungiItem(itembase * dispositivo){
    elementilistaprodotti * oggetto = new elementilistaprodotti(parent, dispositivo);
    addItem(oggetto);
}

//oggetto corrente nella lista
elementilistaprodotti * viewlistaprodotti::itemCorrente() const{
    return static_cast<elementilistaprodotti*>(QListWidget::currentItem());
}

