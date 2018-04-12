//
//  main.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 10.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include "Tester.hpp"


int main()
{
    Tester *tester =new Tester(2000);
//    tester->startTestingMenu();
    for (int i =0; i<11; i++) {
        tester->testTabFrontPush();
    }
    tester->testTabFrontPush();
//    tester->testTabBackPush();
//    tester->testListFrontPush();
//    tester->testListBackPush();
//    tester->testHeapPush();
    
    
    
    return 0;
}



