#include "layoutcampismartphone.h"
#include <QFormLayout>

layoutcampismartphone::layoutcampismartphone(QWidget* parent) :
    QWidget(parent),
    hcampismartphone(new QHBoxLayout(this)),
    memoria_espandibile(new QCheckBox("Memoria Espandibile",this)),
    dual_sim(new QCheckBox("Dual Sim",this))
{
    hcampismartphone->addWidget(memoria_espandibile);
    hcampismartphone->addWidget(dual_sim);
    QFormLayout * fcampismartphone = new QFormLayout();
    hcampismartphone->addLayout(fcampismartphone);
}

