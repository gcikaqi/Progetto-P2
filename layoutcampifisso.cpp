#include "layoutcampifisso.h"
#include <QFormLayout>

layoutcampifisso::layoutcampifisso(QWidget * parent):
        QWidget(parent),
        hcampifisso(new QHBoxLayout(this)),
        tastiera(new QCheckBox("Tastiera",this))
{
    QFormLayout * fcampifisso = new QFormLayout();
    hcampifisso->addLayout(fcampifisso);
}

