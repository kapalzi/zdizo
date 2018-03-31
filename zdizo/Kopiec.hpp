//
//  Kopiec.hpp
//  zdizo
//
//  Created by Krzysztof Kapała on 15.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include "Tablica.hpp"
#include <stdio.h>

class Kopiec : public Tablica
{
private:
    int getBiggerSon(int dad);
    
public:
    Kopiec();
    ~Kopiec();
    void push(int data);
    void pop();
    bool isValue(int data);
};

