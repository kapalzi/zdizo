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

    ofstream file ("numbers.txt");

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
    int x;
    do
    {
        printf("Funkcje Tablicy \n 1. Dodaj elementy z pliku \n 2. Dodaj element od przodu \n 3. Dodaj element od tyłu \n 4. Usuń element z przodu \n 5. Usuń element z tyłu\n 6. Sprawdz czy wartosc jest w tablicy\n 7. Usuń wszystkie elementy\n 8. Wypisz wszystkie elementy \n 9. Wróć \n");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testTabBackPush();
                break;
                
            case 2:
                printf("Podaj wartosc\n");
                std::cin>>x;
                tablica->pushFront(x);
                break;

            case 3:
                printf("Podaj wartosc\n");
                std::cin>>x;
                tablica->pushBack(x);
                break;
    
            case 4:
                tablica->popFront();
                break;
                
            case 5:
                tablica->popBack();
                break;
    
            case 6:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",tablica->isValue(look));
                break;
                
            case 7:
                testTabBackPop();
                break;
                
            case 8:
                tablica->print();
                break;
                
            case 9:
                startTestingMenu();
                break;
                
            default: printf("Nie ma takiej opcji\n");
        }
    
    }
    while (k != 0 );
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
    int k,x;
    
    do
    {
        printf("Funkcje Listy \n 1. Dodaj elementy z pliku\n 2. Dodaj element od przodu \n 3. Dodaj element od tyłu \n 4. Usuń element z przodu \n 5. Usuń element z tyłu\n 6. Sprawdz czy wartosc jest w tablicy\n 7 .Usuń wszystkie elementy \n 8. Wypisz wszystkie elementy \n 9. Wróć \n");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testListFrontPush();
                break;
                
            case 2:
                printf("Podaj wartosc\n");
                std::cin>>x;
                list->pushFront(x);
                break;
                break;
                
            case 3:
                printf("Podaj wartosc\n");
                std::cin>>x;
                list->pushBack(x);
                break;
                
            case 4:
                list->popFront();
                break;
                
            case 5:
                list->popBack();
                break;

            case 6:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",list->isValue(look));
                break;
                
            case 7:
                testListFrontPop();
                break;
                
            case 8:
                list->print();
                break;
                
            case 9:
                startTestingMenu();
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
    int k,x;
    
    do
    {
        printf("Funkcje Tablicy \n 1. Dodaj elementy z pliku \n 2. Dodaj element \n 3. Usuń element \n 4. Sprawdz czy wartosc jest w kopcu \n 5. Usuń wszystkie elementy \n 6. Wypisz wszystkie elementy\n 7. Wróć \n");
        std::cin>>k;
        switch(k)
        {
            case 1:
                testHeapPush();
                break;
                
            case 2:
                printf("Podaj wartosc\n");
                std::cin>>x;
                heap->push(x);
                break;
                
            case 3:
                heap->pop();
                break;
                
            case 4:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",heap->isValue(look));
                break;
                
            case 5:
                testHeapPop();
                break;
                
                
            case 6:
                heap->print();
                break;
                
            case 7:
                startTestingMenu();
                break;
                
            default: printf("Nie ma takiej opcji\n");
        }
        
    }
    while (k != 0 );
}
void Tester::testHeapPush()
{
    fstream file("numbers.txt",ios::in);
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




