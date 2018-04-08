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
Kopiec *heap;

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
    int numberOfElements = 24;
    
    srand(time(NULL));

    ofstream file ("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt");
//    ofstream file ("numbers.txt");

    file<<numberOfElements<<"\n";
    
    for(int i=1; i<=numberOfElements; i++)
    {
        int randomInteger = (rand()%1000)+1;
        file << randomInteger << "\n";
    }
}

void Tester::startTab()
{
    tablica = new Tablica();
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
    const clock_t begin_time = clock();
    
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    getline(file, line);
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushFront(num);
    }
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<std::endl;
//    printf("Dodane\n");
}

void Tester::testTabBackPush()
{
    const clock_t begin_time = clock();
    
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    getline(file, line);
    while (getline(file, line))
    {
        num = stoi(line);
        tablica->pushBack(num);
    }
    
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<std::endl;
//    printf("Dodane\n");
}

void Tester::testTabFrontPop()
{
    const clock_t begin_time = clock();
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popFront();        
    }
//    printf("Usunięte\n");
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<std::endl;
}

void Tester::testTabBackPop()
{
    const clock_t begin_time = clock();
    for (int i=tablica->size; i>0; i--)
    {
        tablica->popBack();
    }
//    printf("Usunięte\n");
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<std::endl;
}

void Tester::startList()
{
    list = new Lista();
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
    const clock_t begin_time = clock();
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushFront(num);
    }
    std::cout << float( clock () - begin_time )/  CLOCKS_PER_SEC <<std::endl;
}

void Tester::testListBackPush()
{
    const clock_t begin_time = clock();
    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    while (getline(file, line))
    {
        num = stoi(line);
        list->pushBack(num);
    }
    std::cout << float( clock () - begin_time )/  CLOCKS_PER_SEC <<std::endl;
}

void Tester::testListFrontPop()
{
    const clock_t begin_time = clock();
    if (list->head)
    {
        while(list->counter>0)
        {
            list->popFront();
        }
        std::cout << float( clock () - begin_time )/  CLOCKS_PER_SEC <<std::endl;
    }
}

void Tester::testListBackPop()
{
    const clock_t begin_time = clock();
    if (list->head)
    {
        while(list->counter>0)
        {
            list->popBack();
        }
        std::cout << float( clock () - begin_time )/  CLOCKS_PER_SEC <<std::endl;
    }
}

void Tester::startHeap()
{
    heap = new Kopiec();
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
//                testTabBackPush();
                heap->Tablica::print();
                break;
                
            case 3:
                int look;
                printf("Podaj szukana wartosc\n");
                std::cin>>look;
                printf("%i\n",tablica->isValue(look));
                break;                break;
                
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
    const clock_t begin_time = clock();

    fstream file ("/Users/krzysztof/Documents/pwr/zdizo/zdizo/numbers.txt");

//    fstream file("numbers.txt",ios::in);
    string line;
    int num;
    getline(file, line);
    while (getline(file, line))
    {
        num = stoi(line);
        heap->push(num);
    }
    
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<std::endl;

}











