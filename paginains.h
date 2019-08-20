#ifndef PAGINAINS_H
#define PAGINAINS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QFormLayout>
#include "layoutcampicomputer.h"
#include "layoutcampismartablet.h"
#include "layoutcampifisso.h"
#include "layoutcampiportatile.h"
#include "layoutcampitablet.h"
#include "layoutcampismartphone.h"


class paginains: public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout * principale;
    QFormLayout * layoutpercampibase;
    layoutcampicomputer * campicomputer;
    layoutcampismartablet * campismartablet;
    layoutcampifisso * campifisso;
    layoutcampiportatile * campiportatile;
    layoutcampitablet * campitablet;
    layoutcampismartphone * campismartphone;

    QPushButton * salvaprd; //bottone SALVA
    QPushButton * annullaprd; //bottone ANULLA
    QPushButton * bcatalogo; //bottone torna al catalago
    QHBoxLayout * hfoot; //horizontali

    //nome
    QLabel * nomel;
    QLineEdit * nomee;
    //marca
    QLabel * marcal;
    QLineEdit * marcaa;
    //modello
    QLabel * modellol;
    QLineEdit * modelloo;
    //os
    QLabel * osl;
    QLineEdit * oss;
    //prezzo base
    QLabel * prezzobasel;
    QLineEdit * prezzobasee;
    //anno di uscita
    QLabel * annodiuscital;
    QLineEdit * annodiuscitaa;
    //ram
    QLabel * raml;
    QLineEdit * ramm;
    //memoria
    QLabel * memorial;
    QLineEdit * memoriaa;

    //radiobutton categoria
    QGroupBox * contenitoreRadio;
    QRadioButton * rPc;
    QRadioButton * rSmarTablet;

    //radiobutton2
    QGroupBox * contenitoreRadio2;
    QRadioButton * rFisso;
    QRadioButton * rPortatile;

    //radiobutton3
    QGroupBox * contenitoreRadio3;
    QRadioButton * rTablet;
    QRadioButton * rSmartphone;




public slots:
    void clickcomputer();
    void clicksmartablet();
    void clickfisso();
    void clickportatile();
    void clicktablet();
    void clicksmartphone();

public:
    paginains(QWidget * parent);
    QPushButton * salvaprodotto()const;
    QPushButton * annullaprodotto() const;
    QPushButton * getcatalogo()const;

};

#endif // PAGINAINS_H
