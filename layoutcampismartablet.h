#ifndef LAYOUTCAMPISMARTABLET_H
#define LAYOUTCAMPISMARTABLET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLineEdit>



class layoutcampismartablet : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampismartablet;
    QCheckBox * fotocamerafrontale;
    QLineEdit * duratabatteria;
    QLineEdit * megapixel;
    QLineEdit * dimSchermo;
public:
    layoutcampismartablet(QWidget * parent);
};

#endif // LAYOUTCAMPISMARTABLET_H
