#ifndef SMARTABLET_H
#define SMARTABLET_H
#include "item.h"


class smartablet: public itembase
{
private:
    double duratta_batteria;
    bool fotocamerafrontale;
    int megapixel;
    double dim_schermo;
public:
    //costruttore di smartablet
    smartablet(string ,string , string , string ,double , int ,int , double ,double , bool , int , double );
    smartablet(const smartablet &); //costruttore di copia

    virtual double calcolaPrezzo() const = 0; //metodo virtuale per calcolare il prezzo
    virtual string getTipo() const=0; //metodo virtuale per il sottotipo


    //get
    double getDuratta_batteria() const;
    bool getFotocamerafrontale() const;
    int getMegapixel() const;
    double getDim_schermo() const;


    //set
    void setDuratta_batteria(double);
    void setFotocamerafrontale(bool);
    void setMegapixel(int);
    void setDim_schermo(double);

    //operator
    bool operator==(const smartablet&) const;
    bool operator!=(const smartablet&) const;

    virtual string infoItem() const;
};

#endif // SMARTABLET_H
