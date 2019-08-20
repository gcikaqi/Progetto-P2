#include "item.h"

//costruttore item
itembase::itembase(string nom,string marc,string mod, string o, double prezzob,int anno, int r,double mem):nome(nom), marca(marc), modello(mod), os(o), prezzo_base(prezzob), anno_diuscita(anno), ram(r),memoria(mem){}

//costruttore di copia
itembase::itembase(const itembase & i):nome(i.getNome()), marca(i.getMarca()), modello(i.getModello()), os(i.getOs()), prezzo_base(i.getPrezzoBase()), anno_diuscita(i.getAnno_diuscita()), ram(i.getRam()),memoria(i.getMemoria()){}

//get
string itembase::getNome() const{
    return nome;
}
string itembase::getMarca() const{
    return marca;
}
string itembase::getModello() const{
    return modello;
}
string itembase::getOs() const{
    return os;
}
double itembase::getPrezzoBase() const{
    return prezzo_base;
}
int itembase::getAnno_diuscita() const{
    return anno_diuscita;
}
double itembase::getRam() const{
    return ram;
}
double itembase::getMemoria() const{
    return memoria;
}

//set
void itembase::setNome(string s){
    nome=s;
}
void itembase::setMarca(string m) {
    marca=m;
}
void itembase::setModello(string m) {
    modello=m;
}
void itembase::setOs(string o) {
    os=o;
}
void itembase::setPrezzoBase(double p) {
    prezzo_base=p;
}
void itembase::setAnno_diuscita(int a) {
    anno_diuscita=a;
}
void itembase::setRam(double r) {
    ram=r;
}
void itembase::setMemoria(double m) {
    memoria=m;
}

//operator ==
bool itembase::operator ==(const itembase& i) const{
    return  ((getNome()==i.getNome() || getNome()=="" ||i.getNome()=="") && (getMarca()==i.getMarca() || getMarca()=="" || i.getMarca()=="")
             && (getModello()==i.getModello() || getModello()=="" || i.getModello()=="") && (getOs()==i.getOs() || getOs()=="" || i.getOs()=="")
             && (getPrezzoBase()==i.getPrezzoBase() || getPrezzoBase()==0 || i.getPrezzoBase()==0) && (getAnno_diuscita()==i.getAnno_diuscita() ||
             getAnno_diuscita()==0 ||i.getAnno_diuscita()==0) && (getRam()==i.getRam() || getRam()==0 ||i.getRam()==0) && (getMemoria()==i.getMemoria() ||
             getMemoria()==0 || i.getMemoria()==0));
}

//operator !=
bool itembase::operator !=(const itembase& i) const{
    bool ret=false;
    if(nome=="" || i.nome==""){
        ret=true;
    }
    if(!ret && nome!=i.nome){
        return true;
    }
    else{
         ret=false;
    }
    if(marca=="" || i.marca==""){
        ret=true;
    }
    if(!ret && marca!=i.marca){
        return true;
    }
    else{
        ret=false;
    }
    if(modello=="" || i.modello==""){
        ret=true;
    }
    if(!ret && modello!=i.modello){
        return true;
    }
    else{
        ret=false;
    }
    if(os=="" || i.os==""){
        ret=true;
    }
    if(!ret && os!=i.os){
        return true;
    }
    else{
        ret=false;
    }
    if(getPrezzoBase()==0 || i.getPrezzoBase()==0)
    {
        ret=true;
    }
    if(!ret && getPrezzoBase()!=i.getPrezzoBase())
    {
        return true;
    }else{
        return false;
    }
    if(anno_diuscita==0 || i.anno_diuscita==0){
        ret=true;
    }
    if(!ret && anno_diuscita!=i.anno_diuscita){
        return true;
    }
    else{
        return false;
    }
    if(ram==0 || i.ram==0){
        ret=true;
    }
    if(!ret && ram!=i.ram){
        return true;
    }
    else{
        return false;
    }
    if(memoria==0 || i.memoria==0){
        ret=true;
    }
    if(!ret && memoria!=i.memoria){
        return true;
    }
    else{
        return false;
    }
}

//metodo per estrappolare i dati e metterli in stringa
std::string itembase::infoItem() const{
    std::string str = "";
    return str.append("\n").append("Nome prodotto: " + getNome())
            .append("\nMarca: " + getMarca())
            .append("\nModello: " + getModello())
            .append("\nSistema Operativo: " + getOs())
            .append("\nPrezzo Base: " + (QString::number(getPrezzoBase()).toUtf8()))
            .append("\nAnno di uscita: " + (QString::number(getAnno_diuscita()).toUtf8()))
            .append("\nRam: " + (QString::number(getRam()).toUtf8()))
            .append("\nMemoria: " + (QString::number(getMemoria()).toUtf8()));

}
