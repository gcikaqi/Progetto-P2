#include "catalogo.h"

catalogo::catalogo(QWidget* parent):
    QWidget(parent),
    tutto(new QHBoxLayout(this)),
    tuttiprodotti(new  QPushButton("Visualizza tutti i prodotti",this)),

    lhorizontalbottoni(new QHBoxLayout(this)),

    bottonefissi(new QPushButton("Computer Fissi",this)),
    bottoneportatili(new QPushButton("Computer Portatili",this)),
    bottonetablet(new QPushButton("Tablet",this)),
    bottonesmartphone(new QPushButton("Smartphone",this)),
    listadavis(new viewlistaprodotti(this)),
    lfinale(new QVBoxLayout(this)),
    hfoot(new QHBoxLayout(this)),
    hfootvisualizza(new QHBoxLayout(this)),
    inserisci(new QPushButton("Inserisci", this)),
    modifica(new QPushButton("Modifica",this)),
    elimina(new QPushButton("Elimina",this)),
    cerca(new QPushButton("Cerca",this))


{

    QWidget * a = new QWidget(this);
    tutto->addWidget(tuttiprodotti);
    a->setLayout(tutto);

    lhorizontalbottoni->addWidget(bottonefissi);
    lhorizontalbottoni->addWidget(bottoneportatili);
    lhorizontalbottoni->addWidget(bottonetablet);
    lhorizontalbottoni->addWidget(bottonesmartphone);

    QWidget * wbott = new QWidget(this);
    wbott->setLayout(lhorizontalbottoni);

    QHBoxLayout* lhorizonatlvisualizza=new QHBoxLayout;
    lhorizonatlvisualizza->addWidget(listadavis);

    QWidget * wvis = new QWidget(this);
    wvis->setLayout(lhorizonatlvisualizza);

    //layout finale
    lfinale->addWidget(a);
    lfinale->addWidget(wbott);
    lfinale->addWidget(wvis);


    hfoot->addWidget(inserisci);
    hfoot->addWidget(modifica);
    hfoot->addWidget(elimina);
    hfoot->addWidget(cerca);

    QWidget * foot=new QWidget(this);
    foot->setLayout(hfoot);

    lfinale->addWidget(foot);



    setLayout(lfinale);



}

QPushButton* catalogo::getbottoneins()const{
    return inserisci;
}
QPushButton* catalogo::gettuttiprodotti()const{
    return tuttiprodotti;
}
viewlistaprodotti * catalogo::getLista() const{
    return listadavis;
}
