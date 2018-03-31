//
//  Tester.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 24.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include "Tester.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

Tablica *tablica;

Tester::Tester()
{
}

void Tester::startTestingMenu()
{
    generateRandomNumbersFile();
    char k;
    printf("Wybierz strukturę \n 1. Tablica \n 2. Lista \n 3. Kopiec");
    std::cin>>k;
    switch(k)
    {
        case '1':
            startTab();
            break;
            
        case '2':
            startList();
            break;
            
        case '3':
            startHeap();
            break;
            
        default: printf("Nie ma takiej opcji");
            
    }
}

void Tester::generateRandomNumbersFile()
{
    int numberOfElements = 1000;
    
    srand(time(NULL));

    ofstream file ("numbers.txt");
    
    for(int i=0; i<numberOfElements; i++)
    {
        int random_integer = (rand()%1000)+1;
        file << random_integer << "\n";
    }
}

void Tester::startTab()
{
    tablica = new Tablica();
    
    char k;
    printf("Funkcje \n 1. Dodaj elementy z pliku od przodu \n 2. Dodaj elementy z pliku od tyłu \n 3. Usuń element z przodu \n 4. Usuń element z tyłu\n 5. Usuń element z pozycji");
    std::cin>>k;
    switch(k)
    {
        case '1':
            testTabFrontPush();
            break;
            
        case '2':
            testTabBackPush();
            break;

//        case '3': testTabFrontPop();
//
//        case '4': testTabFrontPop();
//
//        case '5': testTabFrontPop();
            
        
        default: printf("Nie ma takiej opcji");
            
    }
    
}

void Tester::testTabFrontPush()
{
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushFront(num);
    }
    printf("Dodane");
//    tablica->print();
}

void Tester::testTabBackPush()
{
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushBack(num);
    }
    
    printf("Dodane");
    tablica->print();
}

void Tester::startList()
{
    
}

void Tester::startHeap()
{
    
}

