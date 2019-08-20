#include "layoutcampismartablet.h"
#include <QFormLayout>


layoutcampismartablet::layoutcampismartablet(QWidget* parent):
    QWidget(parent),
    hcampismartablet(new QHBoxLayout(this)),
    fotocamerafrontale(new QCheckBox("Fotocamera Frontale", this)),
    duratabatteria(new QLineEdit(this)),
    megapixel(new QLineEdit(this)),
    dimSchermo(new QLineEdit(this))
{
    hcampismartablet->addWidget(fotocamerafrontale);
    QFormLayout * fcampismartablet = new QFormLayout();
    fcampismartablet->addRow("Durata Batteria: ",duratabatteria);
    fcampismartablet->addRow("Megapixel: ",megapixel);
    fcampismartablet->addRow("Schermo: ",dimSchermo);
    hcampismartablet->addLayout(fcampismartablet);
}

