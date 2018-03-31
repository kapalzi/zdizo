//
//  Tablica.hpp
//  zdizo
//
//  Created by Krzysztof Kapała on 10.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include <stdio.h>

class Tablica
{
protected:
    void pushFirstElement(int data);
    
public:
    int *tab;
    int size;
    
    Tablica();
    ~Tablica();
    
    void pushFront(int data);
    void pushBack(int data);
    void pushAtIndex(int index, int data);
    void popFront();
    void popBack();
    void popAtIndex(int index);
    bool isValue(int value);
    void print();
};
