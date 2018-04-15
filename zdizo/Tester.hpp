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
    Tester(int numberOfElemenst);
    ~Tester();
    int numberOfElements;
    
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
    
    void testHeapPush();
    void testHeapPop();
    
    void testTabSearch(int x);
    void testListSearch(int x);
    void testHeapSearch(int x);
    
};
