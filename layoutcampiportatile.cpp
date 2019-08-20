#include "layoutcampiportatile.h"
#include <QFormLayout>


layoutcampiportatile::layoutcampiportatile(QWidget* parent) :
    QWidget(parent),
    hcampiportatile(new QHBoxLayout(this)),
    durata_batteria(new QLineEdit(this)),
    schermo_touch(new QCheckBox("Schermo Touch", this)),
    dim_schermo(new QLineEdit(this))
{
    hcampiportatile->addWidget(durata_batteria);
    QFormLayout * fcampiportatile = new QFormLayout();
    fcampiportatile->addRow("Durata Batteria: ", durata_batteria);
    fcampiportatile->addRow("Dimensione Schermo: ", dim_schermo);
    hcampiportatile->addLayout((fcampiportatile));
}

