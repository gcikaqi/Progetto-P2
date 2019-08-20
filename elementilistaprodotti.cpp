#include "elementilistaprodotti.h"

elementilistaprodotti::elementilistaprodotti(QWidget* p , itembase* ogg):
    parent(p),
    oggetto(ogg)
{
    update();
}

itembase* elementilistaprodotti::prelevaItem() const{
    return oggetto;
}

void elementilistaprodotti::update() {
    setText(QString::fromStdString(oggetto->infoItem()));
}
