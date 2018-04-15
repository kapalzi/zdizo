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
#include <ctime>
using namespace std;

Tablica *tablica;
Lista *list;
Kopiec *heap;

Tester::Tester(int numberOfElements)
{
    Tester::numberOfElements=numberOfElements;
    generateRandomNumbersFile();
    tablica = new Tablica();
    list = new Lista();
    heap = new Kopiec();

}

Tester::~Tester()
{
    tablica->~Tablica();
    list->~Lista();
    heap->~Kopiec();
}

void Tester::startTestingMenu()
{
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
    
    srand(time(NULL));

    ofstream file ("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt");

    file<<numberOfElements<<"\n";
    
    for(int i=1; i<=numberOfElements; i++)
    {
        int randomInteger = (rand()%1000)+1;
        file << randomInteger << "\n";
    }
}

void Tester::startTab()
{
    int k;

    do
    {
        printf("Funkcje Tablicy \n 1. Dodaj elementy z pliku od przodu \n 2. Dodaj elementy z pliku od tyłu \n 3. Usuń element z przodu \n 4. Usuń element z tyłu\n 5. Sprawdz czy wartosc jest w tablicy\n 6. Wypisz wszystkie elementy");
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
    
            case 5:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",tablica->isValue(look));
                break;
                
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
    fstream file("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushFront(num);
    }
}

void Tester::testTabBackPush()
{
    fstream file("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt",ios::in);
    string line;
    int num;
    
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushBack(num);
    }
    
    
}

void Tester::testTabFrontPop()
{
    
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popFront();        
    }
//    printf("Usunięte\n");
    
}

void Tester::testTabBackPop()
{
    
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popBack();
    }
}

void Tester::startList()
{
    int k;
    
    do
    {
        printf("Funkcje Listy \n 1. Dodaj elementy z pliku od przodu \n 2. Dodaj elementy z pliku od tyłu \n 3. Usuń element z przodu \n 4. Usuń element z tyłu\n 5. Sprawdz czy wartosc jest w tablicy\n 6. Wypisz wszystkie elementy");
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
                
            case 5:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",list->isValue(look));
                break;
                
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
    fstream file("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt",ios::in);
    string line;
    int num;
    
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushFront(num);
    }
    
}

void Tester::testListBackPush()
{
    fstream file("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt",ios::in);
    string line;
    int num;
    
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushBack(num);
    }
    
}

void Tester::testListFrontPop()
{
    
    if (list->head)
    {
        while(list->counter>0)
        {
            list->popFront();
        }
    
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
        
    }
}

void Tester::startHeap()
{
    int k;
    
    do
    {
        printf("Funkcje Tablicy \n 1. Dodaj elementy z pliku \n 2. Usuń element\n 3. Sprawdz czy wartosc jest w kopcu \n 4. Wypisz wszystkie elementy\n");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testHeapPush();
                break;
                
            case 2:
                testHeapPop();
                break;
                
            case 3:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",heap->isValue(look));
                break;
                
            case 4:
                heap->print();
                break;
                
                
            case 6:
                heap->print();
                break;
                
            default: printf("Nie ma takiej opcji\n");
        }
        
    }
    while (k != 0 );
}
void Tester::testHeapPush()
{
//    fstream file ("/Users/krzysztof/Documents/pwr/zdizo/zdizo//Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt");

    fstream file("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt",ios::in);
    string line;
    int num;
    
    while (getline(file, line))
    {
        num = stoi(line);
        heap->push(num);
    }
}
void Tester::testHeapPop()
{
    
    for (int i=heap->size; i>0; i--)
    {
        heap->pop();
    }
}

void Tester::testTabSearch(int x)
{
    tablica->isValue(x);
}

void Tester::testListSearch(int x)
{
    list->isValue(x);
}

void Tester::testHeapSearch(int x)
{
    heap->isValue(x);
}




