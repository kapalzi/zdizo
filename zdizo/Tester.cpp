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
Lista *list;

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
    int numberOfElements = 10000;
    
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
    int k;

    do
    {
        printf("Funkcje Tablicy \n 1. Dodaj elementy z pliku od przodu \n 2. Dodaj elementy z pliku od tyłu \n 3. Usuń element z przodu \n 4. Usuń element z tyłu\n 5. Usuń element z pozycji");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testTabFrontPush();
                break;
                
            case 2:
                testTabBackPush();
                break;

            case 3:
                testTabFrontPop();
                break;
    
            case 4:
                testTabBackPop();
                break;
    
//            case 5:
//                testTabFrontPop();
//                break;
                
            case 6:
                tablica->print();
                break;
                
            default: printf("Nie ma takiej opcji\n");
        }
    
    }
    while (k != 0 );
}


void Tester::testTabFrontPush()
{
    const clock_t begin_time = clock();
    // do something
    
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushFront(num);
    }
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    printf("Dodane\n");
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
    
    printf("Dodane\n");
}

void Tester::testTabFrontPop()
{
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popFront();        
    }
    printf("Usunięte\n");
}

void Tester::testTabBackPop()
{
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popBack();
    }
    printf("Usunięte\n");
}

void Tester::startList()
{
    list = new Lista();
    int k;
    
    do
    {
        printf("Funkcje Listy \n 1. Dodaj elementy z pliku od przodu \n 2. Dodaj elementy z pliku od tyłu \n 3. Usuń element z przodu \n 4. Usuń element z tyłu\n 5. Usuń element z pozycji");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testListFrontPush();
                break;
                
            case 2:
                testListBackPush();
                break;
                
            case 3:
                testListFrontPop();
                break;
                
            case 4:
                testListBackPop();
                break;
                
                //            case 5:
                //                testTabFrontPop();
                //                break;
                
            case 6:
                list->print();
                break;
                
            default: printf("Nie ma takiej opcji");
        }
        
    }
    while (k != 0 );
}

void Tester::testListFrontPush()
{
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushFront(num);
    }
    printf("Dodane\n");
}

void Tester::testListBackPush()
{
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushBack(num);
    }
    printf("Dodane\n");
}

void Tester::testListFrontPop()
{
    if (list->head)
    {
        while(list->counter>0)
        {
            list->popFront();
        }
        printf("Usunięte\n");
    }

}

void Tester::testListBackPop()
{
    if (list->head)
    {
        while(list->counter>0)
        {
            list->popBack();
        }
        printf("Usunięte\n");
    }
}

void Tester::startHeap()
{
    
}

