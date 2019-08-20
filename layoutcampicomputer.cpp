#include "layoutcampicomputer.h"
#include <QFormLayout>


layoutcampicomputer::layoutcampicomputer(QWidget* parent):
    QWidget(parent),
    hcampicomputer(new QHBoxLayout(this)),
    schedavideoo(new QCheckBox("Scheda Video",this)),
    schedavideonomee(new QLineEdit(this))
{
    hcampicomputer->addWidget(schedavideoo);
    QFormLayout * fcampicomputer = new QFormLayout();
    fcampicomputer->addRow("Nome: ", schedavideonomee);
    hcampicomputer->addLayout(fcampicomputer);
}

