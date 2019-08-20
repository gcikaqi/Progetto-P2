#include <iostream>
#include <QApplication>
#include "container.h"
#include "item.h"
#include "computer.h"
#include "smartablet.h"
#include "fisso.h"
#include "portatile.h"
#include "tablet.h"
#include "smartphone.h"
#include "controller.h"


using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller w(nullptr);
    w.show();

    return a.exec();
}

/*
int main()
{
   item *x = new portatile ("mac","apple", "pro", "macos", 1500.0, 2019, 8, 256,true, "sisi", 8.40, true, 14);
    container<item*> ret;
    ret.PushEnd(x);

   item* x= new portatile( "mac", "apple", "macbookpro", "iosmojave", 900, 2019, 8, 256, true, "asa", 8, true, 15);
   container<item*> ret;
   ret.PushBegin(x);
   container<item*>::Iterator it = ret.begin();
   for(; it!=ret.end(); ++it){
       std::cout<< (*it)->getMarca();
   }
}
*/
