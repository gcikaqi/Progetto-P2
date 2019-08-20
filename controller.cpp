#include "controller.h"
using std::cout;

controller::controller(QWidget *parent):
    QWidget(parent),
    layoutprincipale(new QVBoxLayout(this)),
    paginacatalogo(new catalogo(this)),
    paginainserisci(new paginains(this)),
    file(QFileDialog::getOpenFileName(this, tr("Scegli FIle"), ":/Progetto/SalvataggioDati", "File XML(*.xml)"))//prova per model sistemare

{
    mod=(new model(file.toStdString()));//prova per model sistemare
    //carico i dati nel model
    mod->setNuovoPercorso(file.toStdString());
    mod->caricamento();



    layoutprincipale->addWidget(paginacatalogo);
    layoutprincipale->addWidget(paginainserisci);

    paginacatalogo->show();
    //tutte le altre nascoste
    paginainserisci->hide();


    //connect bottone catalogo
    connect(paginacatalogo->gettuttiprodotti(),SIGNAL(clicked()),this,SLOT(caricaDatiCatalogo()));

    //connect bottone inserimento
    connect(paginacatalogo->getbottoneins(),SIGNAL(clicked()),this,SLOT(pressioneinserisci()));
    connect(paginainserisci->getcatalogo(),SIGNAL(clicked()),this,SLOT(pressionecatalogoins()));

    setLayout(layoutprincipale);
}

/*//funzione signal per salvere i dati
void controller::pressioneSalva(){
    if(file!=""){
        mod->salvataggio();
        QMessageBox::warning(this, "Esito positivo!", "Salvataggio riuscito");
    }else{
        QMessageBox::warning(this, "Esito negativo!", "Non è presente il file di salvataggio e caricamento dati");
    }
}*/

//funzione signal per chiudere il programma
/*void controller::chiudiProgramma(){
    QApplication::quit();
}*/

//funnzione public slot carica dati
void controller::caricaDatiCatalogo(){
    cout<<"entrato";
    if(file!=""){//se il mio file non è vuoto
        paginacatalogo->getLista()->clear();//la  mia lista è derivata da qlistwidget posso usare il metodo derivato clear per pilure la lista prec
            container<itembase*>::constiterator citini = mod->mcbegin();
            container<itembase*>::constiterator citfine = mod->mcend();
            for(; citini != citfine ; ++citini){
                 cout<<"aaaaaaaa";
                 paginacatalogo->getLista()->aggiungiItem(*citini);
            }

        }
        else{
            cout<<"file non caricato";
        }
        /*
        if(paginacatalogo->getInfoBottoneVirtuale() == true) {//se ho premuto il tasto bottone virtuale
            container<itembase*>::constiterator citini = mod->mcbegin();
            container<itembase*>::constiterator citfine = mod->mcend();
            for(; citini != citfine ; ++citini){
                if( (*citini)->getTipo() == "virtualgame" )
                    paginacatalogo->getLista()->aggiungiItem(*citini);
            }
            paginacatalogo->setFalseBottoneVirtuale();//setto a false il booleano nel negozio
        }
        if(paginacatalogo->getInfoBottoneCarte() == true) {//se ho premuto il tasto bottone carte
            container<itembase*>::constiterator citini = mod->mcbegin();
            container<itembase*>::constiterator citfine = mod->mcend();
            for(; citini != citfine ; ++citini){
                if( (*citini)->getTipo() == "cardgame" )
                    paginacatalogo->getLista()->aggiungiItem(*citini);
            }
            paginacatalogo->setFalseBottoneCarte();//setto a false il booleano nel negozio
        }
        if(negl->getInfoBottoneTutte() == true) {//se ho premuto il tasto bottone tutto il negozio
            container<itembase*>::constiterator citini = mod->mcbegin();
            container<itembase*>::constiterator citfine = mod->mcend();
            for(; citini != citfine ; ++citini){
                    paginacatalogo->getLista()->aggiungiItem(*citini);
            }
            paginacatalogo->setFalseBottoneTutte();//setto a false il booleano nel negozio
        }*/
    }
    /*paginacatalogo->getBottoneElimina()->setEnabled(false);
    paginacatalogo->getBottoneModifica()->setEnabled(false);
*/




//funziona modifica
/*void controller::pressioneModifica() {
    listaditem * provM = NULL;
    itembase * modM = NULL;
    provM = cat->getLista()->itemCorrente();
    modM = provM->prelevaItem();
    //string tipoogg = modM->getTipo();
    paginamodifica * pm = new paginamodifica(cat,modM,mod,this);
    //pm->resize(200, pm->height());
    pm->resize(this->width(),this->height());
    pm->show();
    this->setDisabled(true);

}*/


//funzione di ins oggetto
/*void controller::avviaIns() {
    if(file!=""){
        itembase * provvisorio = pagins->creazioneOggIns();//creo oggetto da inserire per poi andare a inserire
        if(provvisorio == NULL){
            QMessageBox::warning(this, "Attenzione!", "Inserisci dati validi");
        }else{
            mod->getlista()->PushEnd(provvisorio);
            QMessageBox::warning(this, "Esito positivo!", "Oggetto inserito");
            mod->salvataggio();
            mod->setNuovoPercorso(file.toStdString());
            mod->caricamento();
            pagins->pulisciLine();
        }
    }else{
        QMessageBox::warning(this, "Esito negativo!", "Non sono stati caricati i dati");
    }
}*/


void controller::pressioneinserisci(){
    paginacatalogo->hide();
    paginainserisci->show();
}

void controller::pressionecatalogoins(){
    paginacatalogo->show();
    paginainserisci->hide();
}
