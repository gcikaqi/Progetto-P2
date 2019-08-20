#include "fisso.h"
#include "computer.h"
#include "item.h"

//costruttore di fisso
fisso::fisso(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem, bool scheda, string sche_v, bool tast):computer(nom,marc,mod,o,prezzob,anno,r,mem, scheda,sche_v), tastiera(tast){}
//costruttore di copia
fisso::fisso(const fisso & f): computer(f), tastiera(f.hasTastiera()){}

//get
bool fisso::hasTastiera() const{
    return tastiera;
}

//set
void fisso::setTastiera(bool t){
    tastiera=t;
}

//operator==
bool fisso::operator ==(const fisso& c) const{
    const fisso* f=dynamic_cast<const fisso*>(&c);
    return f && fisso::operator ==(c) && (hasTastiera()==f->hasTastiera());
}

//operator !=
bool fisso::operator !=(const fisso& c) const{
    const fisso* f=dynamic_cast<const fisso*>(&c);
    if(!f)
        return true;
    bool ret=false;
    if(computer::operator !=(c)){
        return true;
    }
    if(!ret && hasTastiera()!=f->hasTastiera()){
        return true;
    }
    else{
        return false;
    }
}

//calcola prezzo virtuale
double fisso::calcolaPrezzo() const{
    if(getNome()=="ProDesk" && getMarca()=="HP" && getModello()=="400"){
        return getPrezzoBase() + 658;
    }
    if(getNome()=="Vostro" && getMarca()=="Dell" && getModello()=="3470 SFF"){
        return getPrezzoBase() + 369;
    }
    if(getNome()=="Pavilion" && getMarca()=="HP" && getModello()=="790-0000NL" && getRam()==8){
        return getPrezzoBase() + 1700;
    }
    return calcolaPrezzo();
}

//get tipo virtuale
string fisso::getTipo() const
{
    return "fisso";
}



std::string fisso::infoItem() const{
    std::string str = computer::infoItem();
    return str.append("\n").append("Tastiera: ").append(hasTastiera() ? "Si" : "No");


}
