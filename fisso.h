#ifndef FISSO_H
#define FISSO_H
#include "computer.h"
#include "item.h"


class fisso:public computer
{
private:
    bool tastiera;
public:
    //costruttore di fisso
    fisso(string ,string , string , string ,double , int ,int , double , bool, string, bool );
    //costruttore di copia
    fisso(const fisso&);

    double calcolaPrezzo() const; //metodo virtuale per calcolare il prezzo
    string getTipo() const; //metodo virtuale per il sottotipo

    //get
    bool hasTastiera() const;

    //set
    void setTastiera(bool);

    //operator
    bool operator==(const fisso&) const;
    bool operator!=(const fisso&) const;

    virtual string infoItem() const;


};

#endif // FISSO_H
