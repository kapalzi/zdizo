//
//  Tester.hpp
//  zdizo
//
//  Created by Krzysztof Kapała on 24.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include <stdio.h>
#include "Lista.hpp"
#include "Kopiec.hpp"

class Tester
{
private:
    
    
public:
    Tester();
    ~Tester();
    void startTestingMenu();
    void startTab();
    void startList();
    void startHeap();
    
    void generateRandomNumbersFile();
    
    void testTabFrontPush();
    void testTabBackPush();
    void testTabFrontPop();
    void testTabBackPop();
    
    void testListFrontPush();
    void testListBackPush();
    void testListFrontPop();
    void testListBackPop();
};
