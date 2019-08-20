#ifndef COMPUTER_H
#define COMPUTER_H
#include "item.h"

using std::string;

class computer: public itembase
{
private:
    bool schedavideo;
    string scheda_vid;
public:
    //costruttore di computer
    computer(string ,string , string , string ,double , int ,int , double ,bool , string);
    //costruttore di copia
    computer(const computer &);

    virtual double calcolaPrezzo() const = 0; //metodo virtuale per calcolare il prezzo
    virtual string getTipo() const=0; //metodo virtuale per il sottotipo

    //get
    bool getSchedavideo() const;
    string getScheda_vid() const;

    //set
    void setSchedavideo(bool);
    void setScheda_vid(string);

    //operator
    bool operator==(const computer&) const;
    bool operator!=(const computer&) const;
    virtual string infoItem() const;
};

#endif // COMPUTER_H
