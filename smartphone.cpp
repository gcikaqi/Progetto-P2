#include "smartphone.h"
#include "smartablet.h"
#include "item.h"

//costruttore di smartphone
smartphone::smartphone(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem,double db, bool front, int mega, double dim_sc,bool m_es, bool dual):smartablet(nom,marc,mod,o,prezzob,anno,r,mem, db,front,mega,dim_sc), memoria_espandibile(m_es), dual_sim(dual){}

//costruttore di copia
smartphone::smartphone(const smartphone & s):smartablet(s), memoria_espandibile(s.hasMemoria_espanibile()), dual_sim(s.isDual_sim()){}

//get
bool smartphone::hasMemoria_espanibile() const{
    return memoria_espandibile;
}
bool smartphone::isDual_sim() const{
    return dual_sim;
}

//set
void smartphone::setMemoria_espandibile(bool s){
    memoria_espandibile=s;
}
void smartphone::setDual_sim(bool a){
    dual_sim=a;
}

//operator==
bool smartphone::operator==(const smartphone& i) const{
    const smartphone* t= dynamic_cast<const smartphone*>(&i);
    return t && smartphone::operator ==(i) && ( hasMemoria_espanibile()==t->hasMemoria_espanibile() && isDual_sim()==t->isDual_sim());
}

//operator!=
bool smartphone::operator!=(const smartphone& i) const{
    const smartphone * t=dynamic_cast<const smartphone*>(&i);
    if(!t)
        return true;
    bool ret=false;
    if(smartablet::operator!=(i)){
        return true;
    }
    if(!ret && hasMemoria_espanibile()!=t->hasMemoria_espanibile()){
        return true;
    }
    else{
        ret=false;
    }
    if(!ret && isDual_sim()!=t->isDual_sim()){
        return true;
    }
    else{
        ret=false;
    }
    return false;
}

//calcola prezzo virtuale
double smartphone::calcolaPrezzo() const{
    if(getNome()=="iPhone" && getMarca()=="Apple" && getModello()=="XS"){
        return getPrezzoBase() + 700;
    }
    if(getNome()=="Samsung" && getMarca()=="Samsung" && getModello()=="S10"){
        return getPrezzoBase() + 400;
    }
    if(getNome()=="Huawei" && getMarca()=="Huawei" && getModello()=="P30"){
        return getPrezzoBase() + 300;
    }
    return false;
}

//get tipo virtuale
string smartphone::getTipo() const
{
    return "smartphone";
}

std::string smartphone::infoItem()const{
    std::string str = smartablet::infoItem();
    return str.append("\n").append("Memoria Espandibile: ").append(hasMemoria_espanibile() ? "Si" : "No")
            .append("\nDual Sim: ").append(isDual_sim() ? "Si" : "No");

}
