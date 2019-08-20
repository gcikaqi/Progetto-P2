#ifndef ITEM_H
#define ITEM_H
#include <string.h>
#include <iostream>
#include <QString>

using std::string;


class itembase
{
private:
    string nome;
    string marca;
    string modello;
    string os;
    double prezzo_base;
    int anno_diuscita;
    int ram;
    double memoria;

public:
    //costruttori
    itembase(string,string, string, string, double, int, int, double );//costruttore
    itembase(const itembase &);//costruttore di copia
    virtual ~itembase() = default; //distruttore virtuale

    virtual double calcolaPrezzo() const = 0; //metodo virtuale per calcolare il prezzo
    virtual string getTipo() const=0; //metodo virtuale per il sottotipo

    //metodi di get
    string getNome() const;
    string getMarca() const;
    string getModello() const;
    string getOs() const; //get sistema operativo
    double getPrezzoBase() const;
    int getAnno_diuscita() const;
    double getRam() const;
    double getMemoria() const;

    //metodi di set
    void setNome(string);
    void setMarca(string);
    void setModello(string);
    void setOs(string);
    void setPrezzoBase(double);
    void setAnno_diuscita(int);
    void setRam(double);
    void setMemoria(double);

    //operator
    virtual bool operator==(const itembase&) const;
    virtual bool operator!=(const itembase&) const;


    virtual string infoItem() const;
};
/*
std::ostream& operator<<(std::ostream& ,const item& );//operator << esterno alla classe */

#endif // ITEM_H
