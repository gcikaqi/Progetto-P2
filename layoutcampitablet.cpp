#include "layoutcampitablet.h"
#include <QFormLayout>


layoutcampitablet::layoutcampitablet(QWidget * parent):
    QWidget(parent),
    hcampitablet(new QHBoxLayout(this)),
    schedasim(new QCheckBox("Scheda Sim",this)),
    auricolari(new QCheckBox("Auricolari", this))
{
    hcampitablet->addWidget(schedasim);
    hcampitablet->addWidget(auricolari);
    QFormLayout * fcampitablet = new QFormLayout();
    hcampitablet->addLayout(fcampitablet);

}

