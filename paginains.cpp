#include "paginains.h"

paginains::paginains(QWidget* parent):
    QWidget(parent),
    principale(new QVBoxLayout(this)),
    layoutpercampibase(new QFormLayout()),
    campicomputer(new layoutcampicomputer(this)),
    campismartablet(new layoutcampismartablet(this)),
    campifisso(new layoutcampifisso(this)),
    campiportatile(new layoutcampiportatile(this)),
    campitablet(new layoutcampitablet(this)),
    campismartphone(new layoutcampismartphone(this)),

    salvaprd(new QPushButton("Salva",this)),
    annullaprd(new QPushButton("Anulla",this)),
    bcatalogo(new QPushButton("Torna al Catalogo",this)),
    hfoot(new QHBoxLayout(this)),

    nomel(new QLabel(this)),
    nomee(new QLineEdit(this)),
    marcal(new QLabel(this)),
    marcaa(new QLineEdit(this)),
    modellol(new QLabel(this)),
    modelloo(new QLineEdit(this)),
    osl(new QLabel(this)),
    oss(new QLineEdit(this)),
    prezzobasel(new QLabel(this)),
    prezzobasee(new QLineEdit(this)),
    annodiuscital(new QLabel(this)),
    annodiuscitaa(new QLineEdit(this)),
    raml(new QLabel(this)),
    ramm(new QLineEdit(this)),
    memorial(new QLabel(this)),
    memoriaa(new QLineEdit(this)),
    contenitoreRadio(new QGroupBox(this)),
    rPc(new QRadioButton(tr("Computer"),this)),
    rSmarTablet(new QRadioButton(tr("SmarTablet"),this)),
    contenitoreRadio2(new QGroupBox(this)),
    rFisso(new QRadioButton(tr("Fisso"), this)),
    rPortatile(new QRadioButton(tr("Portatili"),this)),
    contenitoreRadio3(new QGroupBox(this)),
    rTablet(new QRadioButton(tr("Tablet"),this)),
    rSmartphone(new QRadioButton(tr("Smartphone"), this))

    /*mainviewcomputer( new QWidget(this)), //computer
    mainviewsmartablet( new QWidget(this)), //smartablet
    mainviewfisso(new QWidget(this)), //fisso
    mainviewportatile(new QWidget(this)), //portatile
    mainviewtablet(new QWidget(this)), //tablet
    mainviewsmartphone(new QWidget(this)) //smartphone*/



{
    QLabel* titolo = new QLabel("INSERISCI NUOVO PRODOTTO");
    principale->addWidget(titolo);

    layoutpercampibase->addRow("Nome: ", nomee);
    layoutpercampibase->addRow("Marca: ", marcaa);
    layoutpercampibase->addRow("Modello: ", modelloo);
    layoutpercampibase->addRow("Sistema Operativo: ", oss);
    layoutpercampibase->addRow("Prezzo Base: ", prezzobasee);
    layoutpercampibase->addRow("Anno di uscita: ", annodiuscitaa);
    layoutpercampibase->addRow("Ram: ", ramm);
    layoutpercampibase->addRow("Memoria: ", memoriaa);

    principale->addLayout(layoutpercampibase);

    principale->addWidget(contenitoreRadio);
    QGridLayout * gridradio = new QGridLayout();
    QLabel* labelradio = new QLabel("Scegli la categoria");
    gridradio->addWidget(labelradio,0,0,1,2);
    gridradio->addWidget(rPc,0,1,1,1);
    gridradio->addWidget(rSmarTablet,1,1,1,1);
    contenitoreRadio->setLayout(gridradio);

    //questo mi nasconde i campi dati di computer e smartablet
    contenitoreRadio->show();
    principale->addWidget(campicomputer);
    campicomputer->hide();
    principale->addWidget(campismartablet);
    campismartablet->hide();



    principale->addWidget(contenitoreRadio2);
    QGridLayout * gridradio1 = new QGridLayout();
    QLabel * labelradio1 = new QLabel("Scegliere il dispositivo");
    gridradio1->addWidget(labelradio1,0,0,1,2);
    gridradio1->addWidget(rFisso,0,1,1,1);
    gridradio1->addWidget(rPortatile,1,1,1,1);
    contenitoreRadio2->setLayout(gridradio1);


    contenitoreRadio2->hide();
    principale->addWidget(campifisso);
    campifisso->hide();
    principale->addWidget(campiportatile);
    campiportatile->hide();


    principale->addWidget(contenitoreRadio3);
    //QWidget *ccsmartablet = new QWidget();
    QGridLayout * gridradio2 = new QGridLayout();
    QLabel * labelradio2 = new QLabel("Scegliere il dispositivo");
    gridradio2->addWidget(labelradio2,0,0,1,2);
    gridradio2->addWidget(rTablet,0,1,1,1);
    gridradio2->addWidget(rSmartphone,1,1,1,1);
    contenitoreRadio3->setLayout(gridradio2);


    contenitoreRadio3->hide();
    principale->addWidget(campitablet);
    campitablet->hide();
    principale->addWidget(campismartphone);
    campismartphone->hide();

    //BOTTONI FINALI FOOTER
    hfoot->addWidget(salvaprd);
    hfoot->addWidget(annullaprd);
    hfoot->addWidget(bcatalogo);

    QWidget * foot=new QWidget(this);
    foot->setLayout(hfoot);
    principale->addWidget(foot);






    connect(rPc,SIGNAL(clicked()),this,SLOT(clickcomputer()));
    connect(rSmarTablet,SIGNAL(clicked()),this,SLOT(clicksmartablet()));
    connect(rFisso,SIGNAL(clicked()),this,SLOT(clickfisso()));
    connect(rPortatile,SIGNAL(clicked()),this,SLOT(clickportatile()));
    connect(rTablet,SIGNAL(clicked()),this,SLOT(clicktablet()));
    connect(rSmartphone,SIGNAL(clicked()),this,SLOT(clicksmartphone()));


}

QPushButton * paginains::salvaprodotto()const{
    return salvaprd;
}

QPushButton * paginains::annullaprodotto()const{
    return annullaprd;
}


QPushButton * paginains::getcatalogo()const{
    return bcatalogo;
}



void paginains::clickcomputer(){
      campicomputer->show();
      contenitoreRadio2->show();
      contenitoreRadio3->hide();
      campismartablet->hide();
      campitablet->hide();
      campismartphone->hide();
}

void paginains::clicksmartablet(){
    campismartablet->show();
    contenitoreRadio3->show();
    campicomputer->hide();
    campifisso->hide();
    campiportatile->hide();
    contenitoreRadio2->hide();

}

void paginains::clickfisso(){
    campifisso->show();
    campiportatile->hide();
    campismartablet->hide();
    campitablet->hide();
    campismartphone->hide();

}

void paginains::clickportatile(){
    campiportatile->show();
    contenitoreRadio2->show();
    campifisso->hide();

}

void paginains::clicktablet(){
    campitablet->show();
    campismartphone->hide();
    campicomputer->hide();
    campifisso->hide();
    campiportatile->hide();

}

void paginains::clicksmartphone(){
    campismartphone->show();
    campitablet->hide();
    campiportatile->hide();
    campifisso->hide();
    campicomputer->hide();
}
