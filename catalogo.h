#ifndef CATALOGO_H
#define CATALOGO_H
#include "QWidget"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include "viewlistaprodotti.h"
#include "elementilistaprodotti.h"


class catalogo: public QWidget
{
Q_OBJECT
private:
    //bottone tutti i prodotti
     QHBoxLayout * tutto;
     QPushButton * tuttiprodotti;

    //ciò che vedo
     viewlistaprodotti * listadavis;

    //layout finale
     QVBoxLayout * lfinale;

     //prodotti
     QHBoxLayout * lhorizontalbottoni;
     //QHBoxLayout * lhorizonatlvisualizza;
     QPushButton * bottonefissi;
     QPushButton * bottoneportatili;
     QPushButton * bottonetablet;
     QPushButton * bottonesmartphone;

     //footer
     QHBoxLayout * hfoot;
     QHBoxLayout * hfootvisualizza;
     QPushButton * modifica;
     QPushButton * elimina;
     QPushButton * inserisci;
     QPushButton * cerca;
public:
    catalogo(QWidget* parent);
    QPushButton* getbottoneins() const;
    QPushButton* gettuttiprodotti() const;
    viewlistaprodotti * getLista() const;

};

#endif // CATALOGO_H
