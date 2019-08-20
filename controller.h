#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QTabWidget>//libreira per le tab

#include "catalogo.h"
#include "model.h"
#include "paginains.h"
#include "paginamodifica.h"

class controller : public QWidget
{
Q_OBJECT
private:
    //layout principale della mia app
    QVBoxLayout * layoutprincipale;
    //creo puntatore alla mia pagina catalogo
    catalogo * paginacatalogo;
    paginains * paginainserisci;
    QString file;
    model * mod;




public slots:
    void pressioneinserisci();
    void pressionecatalogoins();
    void caricaDatiCatalogo();
public:
    controller(QWidget * parent= nullptr);
};




#endif // CONTROLLER_H
