#ifndef MODEL_H
#define MODEL_H

#include <fisso.h>
#include <portatile.h>
#include <tablet.h>
#include <smartphone.h>
#include <container.h>

class model
{
private:
    container<itembase*>* lista;
    std::string Path;
    bool datiSalvati;//controllo per vedere se ci sono i dati salvati
public:
    model(std::string = ":/SalvataggioDati");
    ~model();

    void caricamento(); //caricamento dei dati
    void setNuovoPercorso(std::string);
    void salvataggio();

    container<itembase*>::Iterator mbegin();//return iteratore begin
    container<itembase*>::Iterator mend();//return itaratore end
    container<itembase*>::constiterator mcbegin() const;
    container<itembase*>::constiterator mcend() const;

    container<itembase*>* getlista() const;//return di puntatore al mio contenitore
    container<itembase*>::Iterator melimina( container<itembase*>::Iterator itel );
    void meliminanoi( container<itembase*>::Iterator itel );

};

#endif // MODEL_H
