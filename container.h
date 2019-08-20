#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

template <class T>
class container{
private:
    //---CLASSE NODO---
    class nodo
    {
        public:
            T info;//Campo dati all' interno del mio nodo
            nodo * prev;//puntatore al nodo precedente
            nodo * next;//puntatore al nodo sucessivo
            nodo(const T &, nodo * =NULL, nodo * =NULL);
            ~nodo();

    };
    //---FINE NODO--

    //CAMPI DATO CONTENITORE
        nodo * first;//puntatore primo nodo
        nodo * last;//puntatore ultimo nodo
        //PUBLIC CLASSE CONTENITORE
public:
    void PushBegin(const T &);
    void PushEnd(const T &);
    container(nodo * =NULL, nodo* =NULL);

    //---CONSTITERATOR
    class constiterator
    {
        friend class container<T>;
        private:
            const nodo * pt;
            bool pte;//serve per pass the end.
            constiterator(nodo *, bool =false);
        public:
            constiterator();
            constiterator &operator++();
            //operator ++(int)
            constiterator &operator--();
            //operator --(int)
            const T &operator*() const;
            const T *operator->() const;
            bool operator==(const constiterator &) const;
            bool operator!=(const constiterator &) const;
    };
    //---FINE CONSTITERATOR

    //---ITERATOR
    class Iterator
    {
        friend class container<T>;
        private:
            nodo * pt;
            bool pte;
            Iterator(nodo *, bool=false);
        public:
            Iterator();
            Iterator &operator++();
            Iterator &operator--();
            const T &operator*() const;
            const T *operator->() const;
            bool operator==(const Iterator &) const;
            bool operator!=(const Iterator &) const;
    };
    //---FINE ITITERATOR
        //METODI PUBBLICI CONTENITORE
        //METODI PER CONSTITERATOR
        constiterator cbegin() const;
        constiterator cend() const;
        //erase solo per non const iterator

        //METODI PER ITERATOR
        Iterator begin() const;
        Iterator end() const;
        Iterator erase(Iterator);
        void erasenoi(Iterator);
        //erase return un iteratore rif costante
};

//---NODO---
//Costruttore nodo inline def
template <typename T>
container<T>::nodo::nodo(const T & t, nodo * pr, nodo * ne): info(t), prev(pr), next(ne) {}

//Distruttore di nodo ridefinito
template <typename T>
container<T>::nodo::~nodo()
{
    if(next)
    {
        delete next;
    }
}

//---CONTENITORE---
//Costruttore
template <typename T>
container<T>::container(nodo * f, nodo * l): first(f), last(l) {}

//Push begin inserisce, inserimento a inzio lista.
template <typename T>
void container<T>::PushBegin(const T & t)
{
    first = new nodo(t, NULL, first);
    if (last == NULL)
    {
        last = first;
    }
    else
    {
        (first->next)->prev = first;
    }
}
//Push end, inserimento a fine lista.
template <typename T>
void container<T>::PushEnd(const T & t)
{
    last = new nodo(t, last, NULL);
    if (first == NULL)
    {
        first = last;
    }
    else
    {
        (last->prev)->next = last;
    }
}

//begin constiterator
template<typename T>
typename container<T>::constiterator container<T>::cbegin() const
{
    return constiterator(first);
}

//end constiterator
template<typename T>
typename container<T>::constiterator container<T>::cend() const
{
    if(first == NULL)
        return constiterator(NULL);
    return constiterator(last + 1, true);
}
//begin iterator
template<typename T>
typename container<T>::Iterator container<T>::begin() const
{
    return Iterator(first);
}

//end iterator
template<typename T>
typename container<T>::Iterator container<T>::end() const
{
    if(first == NULL)
        return Iterator(NULL);
    return Iterator(last + 1, true);
}

//---CONSTITERATOR---
//costrtuttore constiterator
template< typename T>
container<T>::constiterator::constiterator(nodo * p, bool b) : pt(p), pte(b) {}

//costrtuttore constiterator
template< typename T>
container<T>::constiterator::constiterator() : pt(NULL), pte(false) {}

//operatore ++
template< typename T>
typename container<T>::constiterator& container<T>::constiterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == NULL)
        {
            pt = pt + 1;
            pte = true;
        }
        else
            pt = pt->next;
    }
    return *this;
}
//operator --
template< typename T>
typename container<T>::constiterator& container<T>::constiterator::operator --()
{
    if (pte)
    {
        pt = pt - 1;
        pte = false;
    }
    else if (pt)
    {
        pt = pt->prev;
    }
    return *this;
}

//operator *
template< typename T>
const T & container<T>::constiterator::operator *() const
{
    return pt->info;
}

//operator ->
template< typename T>
const T * container<T>::constiterator::operator ->() const
{
    return &(pt->info);
}
//operator ==
template< typename T>
bool container<T>::constiterator::operator ==(const constiterator & x) const
{
    return pt == x.pt;
}

//operator !=
template< typename T>
bool container<T>::constiterator::operator !=(const constiterator & x) const
{
    return pt != x.pt;
}
//ITERATOR
//costrtuttore iterator
template< typename T>
container<T>::Iterator::Iterator(nodo * p, bool b) : pt(p), pte(b) {}

//costrtuttore iterator
template< typename T>
container<T>::Iterator::Iterator() : pt(NULL), pte(false) {}

//operatore ++
template< typename T>
typename container<T>::Iterator& container<T>::Iterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == NULL)
        {
            pt = pt + 1;
            pte = true;
        }
        else
            pt = pt->next;
    }
    return *this;
}

//operator --
template< typename T>
typename container<T>::Iterator& container<T>::Iterator::operator --()
{
    if (pte)
    {
        pt = pt - 1;
        pte = false;
    }
    else if (pt)
    {
        pt = pt->prev;
    }
    return *this;
}

//operator *
template< typename T>
const T & container<T>::Iterator::operator *() const
{
    return pt->info;
}

//operator ->
template< typename T>
const T * container<T>::Iterator::operator ->() const
{
    return &(pt->info);
}

//operator ==
template< typename T>
bool container<T>::Iterator::operator ==(const Iterator & x) const
{
    return pt == x.pt;
}

//operator !=
template< typename T>
bool container<T>::Iterator::operator !=(const Iterator & x) const
{
    return pt != x.pt;
}
//CONTENITORE
//erasae Iterator
template<typename T>
typename container<T>::Iterator container<T>::erase(Iterator it)
{
    //Cosa succede se la chiamo quando è pass the end???? return se stesso

    Iterator rit;
    if( (!(it.pt)->prev) && (!(it.pt)->next))//se è unico nodo presente nella lista
    {
        first=NULL;
        last=NULL;
        rit.pt=NULL;
        rit.pte=true;
        return rit;
    }

    if(!(it.pt)->next)//caso se è l'ultimo nodo presente nella lista
    {
        rit=(it.pt)->prev;
    }

    if( (it.pt)->prev )//caso se esiste il nodo precendente
        ((it.pt)->prev)->next=(it.pt)->next;
    else{//se non esiste aggioranre primo nodo dentro al contenitore
        if((it.pt)->next){
            first=(it.pt)->next;
        }else{
            first=NULL;
        }
    }

    if( (it.pt)->next )//caso se esiste il nodo sucessivo
        ((it.pt)->next)->prev=(it.pt)->prev;
    else//se non esiste aggiornare ultimo nodo presente dentro il contenitore
    {
        last=(rit.pt);
        return rit;
    }

    ++it;//incremento iteratore
    return it;
}
//erasaenoi Iterator
template<typename T>
void container<T>::erasenoi(Iterator it)
{
    if( (!(it.pt)->prev) && (!(it.pt)->next))//se è unico nodo presente nella lista
    {
        first=NULL;
        last=NULL;
    }else{

        if(!(it.pt)->next)//caso se è l'ultimo nodo presente nella lista
        {
            last=(it.pt)->prev;
        }
        if(!(it.pt)->prev)//caso se è il primo nodo presente nella lista
        {
            first=(it.pt)->next;
        }
        if( (it.pt)->prev ){//caso se esiste il nodo precendente
            ((it.pt)->prev)->next=(it.pt)->next;
        }
        if( (it.pt)->next ){//caso se esiste il nodo sucessivo
            ((it.pt)->next)->prev=(it.pt)->prev;
        }
    }
}
;
#endif // CONTAINER_H

