//
//  DoTest.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 14.04.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include "DoTest.hpp"
#include "Tester.hpp"
#include <time.h>
#include <iostream>
#include <iomanip>

DoTest::DoTest()
{

}

void DoTest::startTests()
{
    srand(time(NULL));
    int numberOfElements = 1000;
    
    clock_t begin_time = clock();
    clock_t midTime;
    float badTimeCounter = 0.0;
    
    //    TEST DODAWANIA Do TABLICY OD PRZODU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        badTimeCounter = badTimeCounter + (clock() - midTime);
        
        tester->testTabFrontPush();

    }
    std::cout<<"Tab front push: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    std::cout<<"Tab front push: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/(100*numberOfElements)<<std::endl;
    
    //    TEST DODAWANIA Do TABLICY OD TYŁU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testTabBackPush();
    }
    std::cout <<"Tab back push: " <<(float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST USUWANIA Z TABLICY OD PRZODU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        tester->testTabFrontPush();
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testTabFrontPop();
    }
    std::cout<<"Tab front pop: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST USUWANIA Z TABLICY OD TYŁU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        tester->testTabFrontPush();
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testTabBackPop();
    }
    std::cout<<"Tab back pop: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST WYSZUKIWANIA W TABLICY
    badTimeCounter = 0.0;
    Tester *tabSearch =new Tester(numberOfElements);
    tabSearch->testTabFrontPush();
    int x;
    begin_time = clock();
    for (int i =0; i<100; i++)
    {
        x = (rand()%100)+1;
        tabSearch->testTabSearch(x);
    }
    std::cout<<"Tab search: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST DODAWANIA Do LISTY OD PRZODU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testListFrontPush();
    }
    std::cout <<"List front push: " <<(float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST DODAWANIA Do LISTY OD TYŁU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testListBackPush();
    }
    std::cout <<"List back push: " <<(float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST USUWANIA Z LISTY OD PRZODU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        tester->testListFrontPush();
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testListFrontPop();
    }
    std::cout<<"List front pop: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST USUWANIA Z LISTY OD TYLU
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        tester->testListFrontPush();
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testListBackPop();
    }
    std::cout<<"List back pop: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST WYSZUKIWANIA W KOLEJCE
    badTimeCounter = 0.0;
    Tester *listSearch =new Tester(numberOfElements);
    listSearch->testListFrontPush();
    int y;
    begin_time = clock();
    for (int i =0; i<100; i++)
    {
        y = (rand()%100)+1;
        listSearch->testListSearch(y);
    }
    std::cout<<"List search: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST DODAWANIA Do KOPCA
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testHeapPush();
    }
    std::cout <<"Heap push: " <<(float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST WYSZUKIWANIA W KOPCU
    badTimeCounter = 0.0;
    Tester *tester =new Tester(numberOfElements);
    tester->testHeapPush();
    int z;
    begin_time = clock();
    for (int i =0; i<100; i++)
    {
        z = (rand()%100)+1;
        tester->testHeapSearch(z);
    }
    std::cout<<"Heap search: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
    //    TEST USUWANIA Z KOPCA
    begin_time = clock();
    badTimeCounter = 0.0;
    for (int i =0; i<100; i++)
    {
        midTime = clock();
        Tester *tester =new Tester(numberOfElements);
        tester->testHeapPush();
        badTimeCounter = badTimeCounter + (clock() - midTime);
        tester->testHeapPop();
    }
    std::cout<<"Heap pop: " << (float(clock () - begin_time - badTimeCounter ) /  CLOCKS_PER_SEC)/100<<std::endl;
    
}


