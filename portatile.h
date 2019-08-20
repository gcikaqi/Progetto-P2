#ifndef PORTATILE_H
#define PORTATILE_H
#include "computer.h"
#include "item.h"



class portatile: public computer
{
private:
    double durata_batteria;
    bool schermo_touch;
    double dim_schermo;
public:
    //costruttore di portatile
    portatile(string ,string , string , string ,double , int ,int , double , bool, string, double ,bool ,double );
    //costruttore di copia
    portatile(const portatile&);

    double calcolaPrezzo() const; //metodo virtuale per calcolare il prezzo
    string getTipo() const; //metodo virtuale per il sottotipo

    //get
    double getDurata_batteria() const;
    bool isSchermo_touch() const;
    double getDim_schermo() const;

    //set
    void setDurata_batteria(double);
    void setSchermo_touch(bool);
    void setDim_schermo(double);

    //operator
    bool operator==(const portatile&) const;
    bool operator!=(const portatile&) const;

    virtual string infoItem() const;
};

#endif // PORTATILE_H
