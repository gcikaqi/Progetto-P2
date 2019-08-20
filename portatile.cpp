#include "portatile.h"
#include "computer.h"
#include "item.h"
#include <QString>

//costruttore di portatile
portatile::portatile(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem, bool scheda, string sche_v, double d_b, bool schermoT, double dim_s):computer(nom,marc,mod,o,prezzob,anno,r,mem ,scheda,sche_v), durata_batteria(d_b), schermo_touch(schermoT), dim_schermo(dim_s){}

//costruttore di copia
portatile::portatile(const portatile & p): computer(p), durata_batteria(p.getDurata_batteria()), schermo_touch(p.isSchermo_touch()), dim_schermo(p.getDim_schermo()){}

//get
double portatile::getDurata_batteria() const{
    return durata_batteria;
}
bool portatile::isSchermo_touch() const{
    return schermo_touch;
}
double portatile::getDim_schermo() const{
    return dim_schermo;
}

//set
void portatile::setDurata_batteria(double d){
    durata_batteria=d;
}
void portatile::setSchermo_touch(bool s){
    schermo_touch=s;
}
void portatile::setDim_schermo(double ds){
    dim_schermo=ds;
}

//operator==
bool portatile::operator ==(const portatile& c) const{
    const portatile* p=dynamic_cast<const portatile*>(&c);
    return p && computer::operator ==(c) && (getDurata_batteria()==p->getDurata_batteria() && isSchermo_touch()==p->isSchermo_touch() && getDim_schermo()==p->getDim_schermo());
}

//operator!=
bool portatile::operator !=(const portatile& c) const{
    const portatile* p=dynamic_cast<const portatile*>(&c);
    if(!p)
        return true;
    bool ret=false;
    if(computer::operator !=(c)){
        return true;
    }
    if(!ret && getDurata_batteria()!=p->getDurata_batteria()){
        return true;
    }
    else{
        return false;
    }
    if(!ret && isSchermo_touch()!=p->isSchermo_touch()){
        return true;
    }
    else{
        return false;
    }
    if(!ret && getDim_schermo()!=p->getDim_schermo()){
        return true;
    }
    else{
        return false;
    }
}


//calcola prezzo virtuale
double portatile::calcolaPrezzo() const{
    if(getNome()=="mac" && getMarca()=="apple" && getModello()=="macbookpro" && getOs()=="iosmojave" ){
        return getPrezzoBase() + 700;
    }
    if(getMarca()=="Lenovo" && getModello()=="U31"){
        return getPrezzoBase() + 350;
    }
    return calcolaPrezzo();
}

//get tipo virtuale
string portatile::getTipo() const
{
    return "portatile";
}


std::string portatile::infoItem() const{
    std::string str = computer::infoItem();
    return str.append("\n").append("Durata Batteria: " + (QString::number(getDurata_batteria()).toUtf8()))
            .append("\nSchermo Touch: ").append(isSchermo_touch() ? "Si" : "No")
            .append("\nDimensione Schermo: " + (QString::number(getDim_schermo()).toUtf8()));

}
