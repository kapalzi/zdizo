//
//  Tablica.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 10.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//
#include "Tablica.hpp"

Tablica::Tablica()
{
    size = 0;
}

Tablica::~Tablica()
{
    delete []tab;
}

void Tablica::pushFirstElement(int data)
{
    tab = new int[0];
    tab[0] = data;
}

void Tablica::pushFront(int data)
{
    if(tab)
    {
        int newSize = size+1;
        int *tmpTab = new int[newSize];
        for (int i=1; i<size; i++)
        {
            tmpTab[i]=tab[i-1];
        }
        
        delete []tab;
        tmpTab[0]=data;
        tab = tmpTab;
        size=newSize;
    }
    else pushFirstElement(data);
}

void Tablica::pushBack(int data)
{
    if(tab)
    {
        size++;
        int *tmpTab = new int[size];
        for (int i=0; i<size; i++)
        {
            tmpTab[i]=tab[i];
        }
        delete []tab;
        tmpTab[size]=data;
        tab = tmpTab;
    }
    else pushFirstElement(data);
}

void Tablica::pushAtIndex(int index, int data)
{
    if(tab)
    {
        size++;
        int *tmpTab = new int[size];
        for (int i=0; i<=index; i++)
        {
            tmpTab[i]=tab[i];
        }
        for (int i=index+1; i<=size; i++)
        {
            tmpTab[i]=tab[i-1];
        }
        delete []tab;
        tmpTab[index]=data;
        tab = tmpTab;
//        co jak index>size+1
    }
    else pushFirstElement(data);
}

void Tablica::popFront()
{
    if(tab)
    {
        int *tmpTab = new int[size];
        for (int i=1; i<=size; i++)
        {
            tmpTab[i]=tab[i+1];
        }
        delete []tab;
        tab=tmpTab;
        size--;
    }
}

void Tablica::popBack()
{
    if(tab)
    {
        size--;
        int *tmpTab = new int[size];
        for (int i=0; i<=size; i++)
        {
            tmpTab[i]=tab[i];
        }
        delete []tab;
        tab=tmpTab;
    }
}

bool Tablica::isValue(int value)
{
    if(tab)
    {
        for (int i=0; i<=size; i++)
        {
            if (tab[i]==value)
                return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

void Tablica::print()
{
    if(tab)
    {
        for (int i=0; i<=size; i++)
        {
            printf("[%d]",tab[i]);
        }
        printf("\n");
    }
    else printf("No data");
}




