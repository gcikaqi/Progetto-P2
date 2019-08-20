#include "tablet.h"
#include "smartablet.h"
#include "item.h"

//costruttore di tablet
tablet::tablet(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem,double d_b, bool front, int mega, double dim_sc, bool scheda, bool auri): smartablet(nom,marc,mod,o,prezzob,anno,r,mem, d_b,front,mega,dim_sc),schedasim(scheda), auricolari(auri){}

//costruttore di copia
tablet::tablet(const tablet & t):smartablet(t), schedasim(t.hasSchedasim()), auricolari(t.hasAuricolari()){}

//get
bool tablet::hasSchedasim() const{
    return schedasim;
}
bool tablet::hasAuricolari() const{
    return auricolari;
}

//set
void tablet::setSchedasim(bool s){
    schedasim=s;
}
void tablet::setAuricolari(bool a){
    auricolari=a;
}

//operator==
bool tablet::operator==(const tablet& i) const{
    const tablet* t= dynamic_cast<const tablet*>(&i);
    return t && smartablet::operator ==(i) && ( hasSchedasim()==t->hasSchedasim() && hasAuricolari()==t->hasAuricolari());
}

//operator!=
bool tablet::operator!=(const tablet& i) const{
    const tablet * t=dynamic_cast<const tablet*>(&i);
    if(!t)
        return true;
    bool ret=false;
    if(smartablet::operator!=(i)){
        return true;
    }
    if(!ret && hasSchedasim()!=t->hasSchedasim()){
        return true;
    }
    else{
        ret=false;
    }
    if(!ret && hasAuricolari()!=t->hasAuricolari()){
        return true;
    }
    else{
        ret=false;
    }
    return false;
}


//calcola prezzo virtuale
double tablet::calcolaPrezzo() const{
    if(getNome()=="iPad" && getMarca()=="Apple" && getModello()=="iPad Pro" && getAnno_diuscita()==2019){
        return getPrezzoBase() + 1000;
    }
    if(getNome()=="Galaxy Tab" && getMarca()=="Samsung" && getModello()=="A 10"){
        return getPrezzoBase() + 400;
    }
    if(getNome()=="Media Pad" && getMarca()=="Huawei" && getModello()=="T5 10"){
        return getPrezzoBase() + 300;
    }
    return false;
}

//get tipo virtuale
string tablet::getTipo() const
{
    return "tablet";
}

std::string tablet::infoItem() const{
    std::string str = smartablet::infoItem();
    return str.append("\n").append("Scheda Sim: ").append(hasSchedasim() ? "Si" : "No")
            .append("\nAuricolari: ").append(hasAuricolari() ? "Si" : "No");

}
