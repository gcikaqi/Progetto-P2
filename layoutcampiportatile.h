#ifndef LAYOUTCAMPIPORTATILE_H
#define LAYOUTCAMPIPORTATILE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>



class layoutcampiportatile : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout * hcampiportatile;
    QLineEdit * durata_batteria;
    QCheckBox * schermo_touch;
    QLineEdit * dim_schermo;
public:
    layoutcampiportatile(QWidget * parent);
};

#endif // LAYOUTCAMPIPORTATILE_H
