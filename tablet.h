#ifndef TABLET_H
#define TABLET_H
#include "smartablet.h"
#include "item.h"


class tablet:public smartablet
{
private:
    bool schedasim;
    bool auricolari;
public:
    //costruttore di tablet
    tablet(string ,string ,string ,string ,double ,int ,int ,double ,double ,bool ,int ,double ,bool ,bool );
    //costruttore di copia
    tablet(const tablet& );

    double calcolaPrezzo() const; //metodo virtuale per calcolare il prezzo
    string getTipo() const; //metodo virtuale per il sottotipo

    //get
    bool hasSchedasim() const;
    bool hasAuricolari() const;

    //set
    void setSchedasim(bool);
    void setAuricolari(bool);

    //operator
    bool operator==(const tablet&) const;
    bool operator!=(const tablet&) const;

    virtual string infoItem()const;

};

#endif // TABLET_H
