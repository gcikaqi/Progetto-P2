#include "smartablet.h"
#include "item.h"
#include <QString>


//costruttore di smartablet
smartablet::smartablet(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem,double db, bool front, int mega, double dim_sc):itembase(nom,marc,mod,o,prezzob,anno,r,mem), duratta_batteria(db),fotocamerafrontale(front), megapixel(mega), dim_schermo(dim_sc) {}

//costruttore di copia
smartablet::smartablet(const smartablet & s):itembase(s), duratta_batteria(s.getDuratta_batteria()), fotocamerafrontale(s.getFotocamerafrontale()), megapixel(s.getMegapixel()),dim_schermo(s.getDim_schermo() ){}

//get
double smartablet::getDuratta_batteria() const{
    return duratta_batteria;
}
bool smartablet::getFotocamerafrontale() const{
    return fotocamerafrontale;
}
int smartablet::getMegapixel() const{
    return megapixel;
}
double smartablet::getDim_schermo() const{
    return dim_schermo;
}

//set
void smartablet::setDuratta_batteria(double d){
    duratta_batteria=d;
}
void smartablet::setFotocamerafrontale(bool f){
    fotocamerafrontale=f;
}
void smartablet::setMegapixel(int m){
    megapixel=m;
}
void smartablet::setDim_schermo(double d){
    dim_schermo=d;
}


//operator ==
bool smartablet::operator ==(const smartablet& i) const{
    const smartablet *s=dynamic_cast<const smartablet*>(&i);
    return s && smartablet::operator ==(i) && ( getDuratta_batteria() == s->getDuratta_batteria() &&
           getFotocamerafrontale()==s->getFotocamerafrontale() && getMegapixel()==s->getMegapixel() && getDim_schermo()==s->getDim_schermo());
}

//operator !=
bool smartablet::operator !=(const smartablet& i) const{
    const smartablet *s=dynamic_cast<const smartablet*>(&i);
    if(!s)
        return true;
    bool ret=false;
    if(itembase::operator!=(i)){
        return true;
    }
    if(!ret && getDuratta_batteria()!=s->getDuratta_batteria()){
        return true;
    }
    else{
        ret=false;
    }
    if(!ret && getFotocamerafrontale()!=s->getFotocamerafrontale()){
        return true;
    }
    else{
        ret=false;
    }
    if(!ret && getMegapixel()!=s->getMegapixel()){
        return true;
    }
    else{
        ret=false;
    }
    if(!ret && getDim_schermo()!=s->getDim_schermo()){
        return true;
    }
    else{
        ret=false;
    }
    return false;
}


std::string smartablet::infoItem() const{
    std::string str = itembase::infoItem();
    return str.append("\n").append("Durata Batteria: " + (QString::number(getDuratta_batteria()).toUtf8()))
            .append("\nFotocamera Frontale: ").append(getFotocamerafrontale() ? "Si" : "No")
            .append("\nMegapixel: " + (QString::number(getMegapixel()).toUtf8()))
            .append("\nDimensione Schermo: " + (QString::number(getDim_schermo()).toUtf8()) );


}
