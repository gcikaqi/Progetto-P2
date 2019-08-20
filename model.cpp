#include "model.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <iostream>
using std::cout;

//costruttore model
model::model(std::string p):
    lista(new container<itembase*>),
    Path(p),
    datiSalvati(true)
{}

//distruttore
model::~model(){delete lista;}

//FUNZIONI CHE RITORNANO DA QUELLE DENTRO IL CONTENITORE
//begin
container<itembase*>::Iterator model::mbegin(){
    return lista->begin();
}

//end
container<itembase*>::Iterator model::mend(){
    return lista->end();
}

//cbegin
container<itembase*>::constiterator model::mcbegin() const{
    return lista->cbegin();
}

//mcend
container<itembase*>::constiterator model::mcend() const{
    return lista->cend();
}

//melimina
container<itembase*>::Iterator model::melimina( container<itembase*>::Iterator ite ){
    return lista->erase(ite);
}
//meliminanoi
void model::meliminanoi(container<itembase *>::Iterator itel){
    lista->erasenoi(itel);
}

//getlista
container<itembase*>* model::getlista() const{
    return lista;
}

//funzione di caricamete dati da xml
void model::caricamento(){
    QFile fileSalvataggio(QString::fromStdString(Path));

    if(!fileSalvataggio.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << fileSalvataggio.errorString();
        return ;
    }

    QXmlStreamReader lettore(&fileSalvataggio);//variabile lettore
    if(lettore.readNextStartElement()){
        if(lettore.name() == "root"){
            while(lettore.readNextStartElement()){
                const QXmlStreamAttributes attributo = lettore.attributes();
                std::string nome = attributo.hasAttribute("nome") ? attributo.value("nome").toString().toStdString() : "";
                std::string marca = attributo.hasAttribute("marca") ? attributo.value("marca").toString().toStdString() : "";
                std::string modello = attributo.hasAttribute("modello") ? attributo.value("modello").toString().toStdString() : "";
                std::string os = attributo.hasAttribute("os") ? attributo.value("os").toString().toStdString() : "";
                double prezzo_base = attributo.hasAttribute("prezzo_base") ? attributo.value("prezzo_base").toDouble() : 0;
                int anno_diuscita = attributo.hasAttribute("anno_diuscita") ? attributo.value("anno_diuscita").toInt() : 0;
                int ram = attributo.hasAttribute("ram") ? attributo.value("ram").toInt() : 0;
                double memoria = attributo.hasAttribute("memoria") ? attributo.value("memoria").toDouble() : 0;

                itembase * daInserire = NULL;


                if(lettore.name() == "computerfisso"){
                    bool schedavideo = attributo.hasAttribute("schedavideo") ? attributo.value("schedavideo").toString()=="true"? true : false : false;
                    std::string scheda_vid = attributo.hasAttribute("scheda_vid") ? attributo.value("scheda_vid").toString().toStdString() : "";
                    bool tastiera = attributo.hasAttribute("tastiera") ? attributo.value("tastiera").toString()=="true"? true : false : false;

                    //chiamo costrtuttore computer fisso
                    daInserire = new fisso(nome,marca,modello,os,prezzo_base,anno_diuscita,ram, memoria,schedavideo,scheda_vid,tastiera);

                } else if(lettore.name() == "computerportatile"){
                    bool schedavideo = attributo.hasAttribute("schedavideo") ? attributo.value("schedavideo").toString()=="true"? true : false : false;
                    std::string scheda_vid = attributo.hasAttribute("scheda_vid") ? attributo.value("scheda_vid").toString().toStdString() : "";
                    double durata_batteria = attributo.hasAttribute("durata_batteria") ? attributo.value("durata_batteria").toDouble() : 0;
                    bool schermo_touch = attributo.hasAttribute("schermo_touch") ? attributo.value("schermo_touch").toString()=="true"? true: false : false;
                    double dim_schermo = attributo.hasAttribute("dim_schermo") ? attributo.value("dim_schermo").toDouble() : 0;

                    //costruttore computer portatile
                    daInserire = new portatile(nome,marca,modello,os,prezzo_base,anno_diuscita,ram, memoria,schedavideo,scheda_vid,durata_batteria,schermo_touch,dim_schermo);
                }

                if(lettore.name() == "tablet"){
                   double duratta_batteria = attributo.hasAttribute("duratta_batteria") ? attributo.value("duratta_batteria").toDouble() : 0;
                   bool fotocamerafrontale = attributo.hasAttribute("fotocamerafrontale") ? attributo.value("fotocamerafrontale").toString()=="true"? true : false : false;
                   int megapixel = attributo.hasAttribute("megapixel") ? attributo.value("megapixel").toInt() : 0;
                   double dim_schermo = attributo.hasAttribute("dim_schermo") ? attributo.value("dim_schermo").toDouble() : 0;
                   bool schedasim = attributo.hasAttribute("schedasim") ? attributo.value("schedasim").toString()=="true"? true : false : false;
                   bool auricolari = attributo.hasAttribute("auricolari") ? attributo.value("auricolari").toString()=="true"? true : false : false;

                   //chiamo costrtuttore tablet
                    daInserire = new tablet(nome,marca,modello,os,prezzo_base,anno_diuscita,ram, memoria,duratta_batteria,fotocamerafrontale,megapixel,dim_schermo, schedasim, auricolari);

                }else if(lettore.name() == "smartphone"){
                    double duratta_batteria = attributo.hasAttribute("duratta_batteria") ? attributo.value("duratta_batteria").toDouble() : 0;
                    bool fotocamerafrontale = attributo.hasAttribute("fotocamerafrontale") ? attributo.value("fotocamerafrontale").toString()=="true"? true : false : false;
                    int megapixel = attributo.hasAttribute("megapixel") ? attributo.value("megapixel").toInt() : 0;
                    double dim_schermo = attributo.hasAttribute("dim_schermo") ? attributo.value("dim_schermo").toDouble() : 0;
                    bool memoria_espandibile = attributo.hasAttribute("memoria_espandibile") ? attributo.value("memoria_espandibile").toString()=="true"? true: false : false;
                    bool dual_sim = attributo.hasAttribute("dual_sim") ? attributo.value("dual_sim").toString()=="true"? true: false : false;

                    //costruttore smartphone
                    daInserire = new smartphone(nome,marca,modello,os,prezzo_base,anno_diuscita,ram, memoria,duratta_batteria,fotocamerafrontale,megapixel,dim_schermo,memoria_espandibile,dual_sim);

                }

                if(daInserire!=NULL)//chiamo la mia pushback
                    //lista->insertBack(daInserire);
                    lista->PushEnd(daInserire);

                if(!lettore.isEndDocument())//elemento dopo
                    lettore.skipCurrentElement();
            }
        }
    }
    datiSalvati=true;
    fileSalvataggio.close();
}

//salvataggio dei dati nel file xml
void model::salvataggio(){
    QSaveFile file(QString::fromStdString(Path));

    if(!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter lettore(&file);

    lettore.setAutoFormatting(true); // Per leggibilità del file XML
    lettore.writeStartDocument();  // Scrive le intestazioni XML
    lettore.writeComment("!!!Non modificate");

    lettore.writeStartElement("root");

    container<itembase*>::constiterator it = mcbegin();
    //auto it = mcbegin();//iteratore automatico e lo setto a inizio del mio contenitore
    while(it != mcend()){
        const itembase* daSalvare = *it;
        QString tipologiaOgg = QString::fromStdString(daSalvare->getTipo());
        /*controllo del gettipo*/
        if(tipologiaOgg == "computer")//per computer
            tipologiaOgg = "fisso";
            tipologiaOgg = "portatile";
            if(tipologiaOgg == "fisso"){
                tipologiaOgg = "fisso";
            }else if(tipologiaOgg == "portatile"){
                tipologiaOgg = "portatile";
            }
        if(tipologiaOgg == "smartablet")//per smartablet
            tipologiaOgg = "tablet";
            tipologiaOgg = "smartphone";
            if(tipologiaOgg == "tablet"){
                tipologiaOgg = "tablet";
            }else if(tipologiaOgg == "smartphone"){
                tipologiaOgg = "smartphone";
            }

        lettore.writeEmptyElement(tipologiaOgg);
        lettore.writeAttribute("nome", QString::fromStdString(daSalvare->getNome()));
        lettore.writeAttribute("marca", QString::fromStdString(daSalvare->getMarca()));
        lettore.writeAttribute("modello", QString::fromStdString(daSalvare->getModello()));
        lettore.writeAttribute("os", QString::fromStdString(daSalvare->getOs()));
        lettore.writeAttribute("prezzo_base", QString("%1").arg(daSalvare->getPrezzoBase()));
        lettore.writeAttribute("anno_diuscita", QString("%1").arg(daSalvare->getAnno_diuscita()));
        lettore.writeAttribute("ram", QString("%1").arg(daSalvare->getRam()));
        lettore.writeAttribute("memoria", QString("%1").arg(daSalvare->getMemoria()));


        if(tipologiaOgg == "computer"){
            const computer * oggcomputer = static_cast<const computer*>(daSalvare);
            lettore.writeAttribute("schedavideo", oggcomputer->getSchedavideo() ? "true" : "false");
            lettore.writeAttribute("scheda_vid", QString::fromStdString(oggcomputer->getScheda_vid()));
                if(tipologiaOgg == "fisso"){
                    const fisso* oggfisso = static_cast<const fisso*>(daSalvare);
                    lettore.writeAttribute("tastiera", oggfisso->hasTastiera() ? "true" : "false");

                }else if(tipologiaOgg == "portatile"){
                    const portatile * oggportatile = static_cast<const portatile*>(daSalvare);
                    lettore.writeAttribute("durata_batteria", QString("%1").arg(oggportatile->getDurata_batteria()));
                    lettore.writeAttribute("schermo_touch", oggportatile->isSchermo_touch() ? "true" : "false");
                    lettore.writeAttribute("dim_schermo", QString("%1").arg(oggportatile->getDim_schermo()));

            }
        } else if(tipologiaOgg == "smartablet"){
            const smartablet * oggsmartablet = static_cast<const smartablet*>(daSalvare);
            lettore.writeAttribute("duratta_batteria", QString("%1").arg(oggsmartablet->getDuratta_batteria()));
            lettore.writeAttribute("fotocamerafrontale", oggsmartablet->getFotocamerafrontale() ? "true" : "false");
            lettore.writeAttribute("megapixel", QString("%1").arg(oggsmartablet->getMegapixel()));
            lettore.writeAttribute("dim_schermo", QString("%1").arg(oggsmartablet->getDim_schermo()));

                if(tipologiaOgg == "tablet"){
                    const tablet * oggtablet = static_cast<const tablet*>(daSalvare);
                    lettore.writeAttribute("schedasim", oggtablet->hasSchedasim() ? "true" : "false");
                    lettore.writeAttribute("auricolari", oggtablet->hasAuricolari() ? "true" : "false");
                }else if(tipologiaOgg == "smartphone"){
                    const smartphone * oggsmartphone = static_cast<const smartphone *>(daSalvare);
                    lettore.writeAttribute("memoria_espandibile", oggsmartphone->hasMemoria_espanibile() ? "true" : "false");
                    lettore.writeAttribute("dual_sim", oggsmartphone->isDual_sim() ? "true" : "false");
                }
        }

        ++it;
    }

    lettore.writeEndElement();
    lettore.writeEndDocument();
    datiSalvati = true;
    file.commit();
}

//settare un nuovo percorso per io dati
void model::setNuovoPercorso(std::string p){
    Path = p;
    delete lista;
    datiSalvati = false;
    lista = new container<itembase*>();
}


