//#include <iostream>

#include "Tester.hpp"
//#include "Kopiec.hpp"

int main()
{
//    Tester *tester =new Tester(1000);
//    tester->startTestingMenu();

//    Tablica *tab = new Tablica();
//    tab->pushFront(21);
//    tab->pushFront(22);
//    tab->pushFront(23);
//
//    tab->pushBack(11);
//    tab->pushBack(12);
//    tab->pushBack(13);
//    tab->print();
//
//    tab->popBack();
//    tab->popBack();
//    tab->popBack();
//    tab->print();
//
    Kopiec *heap = new Kopiec();
    heap->push(21);
    heap->push(31);
    heap->push(1);
    heap->push(2);
    heap->push(241);
    heap->push(71);
    heap->push(21);
    heap->print();
    printf("%i\n",heap->isValue(2));
    
//
//    heap->pop();
//    heap->print();
//
//

//    heap->Tablica::print();
    
//    heap->print();
//
//    heap->pop();
//    heap->print();
    

    return 0;
}



