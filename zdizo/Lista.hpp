//
//  Lista.hpp
//  zdizo
//
//  Created by Krzysztof Kapała on 10.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include <stdio.h>

class Lista
{
public:
    struct Element
    {
        int data;
        Element *next;
        Element *previous;
    };
    
    Element *head;
    Element *tail;
    int counter;
    
    Lista();
    void pushFront(int data);
    void pushBack(int data);
    void pushAtIndex(int index, int data);
    void popFront();
    void popBack();
    void popAtIndex(int index);
    void print();
    bool isValue(int value);
};



