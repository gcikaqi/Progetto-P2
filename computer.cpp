#include "computer.h"
#include "item.h"


//costruttore di computer
computer::computer(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem,bool scheda, string sche_v):itembase(nom,marc,mod,o,prezzob,anno,r,mem), schedavideo(scheda), scheda_vid(sche_v){}

//costruttore di copia
computer::computer(const computer & c):itembase(c), schedavideo(c.getSchedavideo()), scheda_vid(c.getScheda_vid()){}

//get
bool computer::getSchedavideo() const{
    return schedavideo;
}
string computer::getScheda_vid() const{
    return scheda_vid;
}

//set
void computer::setSchedavideo(bool s){
    schedavideo=s;
}
void computer::setScheda_vid(string c){
    scheda_vid=c;
}

//operator==
bool computer::operator==(const computer& i) const{
    const computer *c=dynamic_cast<const computer*>(&i);
    return c && itembase::operator ==(i) && ( getSchedavideo()== c->getSchedavideo() && getScheda_vid()==c->getScheda_vid());
}

//operator!=
bool computer::operator !=(const computer& i) const{
    const computer* c=dynamic_cast<const computer*>(&i);
    if(!c)
        return true;
    bool ret=false;
    if(itembase::operator!=(i)){
        return true;
    }
    if(!ret && getSchedavideo()!=c->getSchedavideo()){
        return true;
    }
    else{
        return false;
    }
    if(!ret && getScheda_vid()!=c->getScheda_vid()){
        return true;
    }
    else{
        return false;
    }
}


std::string computer::infoItem() const{
    std::string str = itembase::infoItem();
    return str.append("\n").append("Scheda Video: ").append(getSchedavideo() ? "Si" : "No")
            .append("\nNome Scheda Video: " + getScheda_vid());

}
