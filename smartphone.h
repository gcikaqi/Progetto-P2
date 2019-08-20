#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "smartablet.h"
#include "item.h"


class smartphone:public smartablet
{
private:
    bool memoria_espandibile;
    bool dual_sim;
public:
    //costruttore di tablet
    smartphone(string ,string , string , string ,double , int ,int , double ,double, bool, int ,double , bool ,bool);
    //costruttore di copia
    smartphone(const smartphone& );

    double calcolaPrezzo() const; //metodo virtuale per calcolare il prezzo
    string getTipo() const; //metodo virtuale per il sottotipo

    //get
    bool hasMemoria_espanibile() const;
    bool isDual_sim() const;

    //set
    void setMemoria_espandibile(bool);
    void setDual_sim(bool);

    //operator
    bool operator==(const smartphone&) const;
    bool operator!=(const smartphone&) const;

    virtual string infoItem()const;
};

#endif // TABLET_H
