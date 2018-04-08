//
//  Kopiec.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 15.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

//numer lewego syna = 2k + 1
//numer prawego syna = 2k + 2
//numer ojca = [(k - 1) / 2], dla k > 0
//lewy syn istnieje, jeśli 2k + 1 < n
//prawy syn istnieje, jeśli 2k + 2 < n
//węzeł k jest liściem, jeśli 2k + 2 > n

#include "Kopiec.hpp"
#include <iostream>

Kopiec::Kopiec()
{
    size = 0;
}

Kopiec::~Kopiec()
{
    delete []tab;
}

void Kopiec::push(int data)
{
    if(tab)
    {
        pushBack(data);
        int son = size-1;
        int dad = (size-1)/2;
        int tmp;
        while(data>tab[dad])
        {
            tmp = tab[son];
            tab[son]=tab[dad];
            tab[dad]=tmp;
            
            son=dad;
            dad = (dad-1)/2;
        }
    }
    else
    pushFirstElement(data);
}

//numer lewego syna = 2k + 1
//numer prawego syna = 2k + 2
void Kopiec::pop()
{
    if(tab)
    {
        tab[0]=tab[size];
        popBack();
        int dad =0;
        int son = getBiggerSon(dad);

        int tmp;
        while(tab[dad]<tab[son])
        {
            tmp = tab[dad];
            tab[dad]=tab[son];
            tab[son]=tmp;
            dad=son;
            son=getBiggerSon(dad);
        }
    }
}

int Kopiec::getBiggerSon(int dad)
{
    int left = 2*dad+1;
    int right = 2*dad+2;
    if (tab[left]>=tab[right]) return left;
    else return right;
}

bool Kopiec::isValue(int data)
{
    if(tab)
    {
        int dad = 0;
        while(tab[dad]!=data)
        {
            int left = 2*dad+1;
            int right = 2*dad+2;
            if(tab[data]<=tab[left])
            {
                dad=left;
            }
            else
            {
                dad=right;
            }
        }
        return true;
    }
    else return false; //dokonczyc albo search z tablicy
}

void Kopiec::print()
{
    if(tab)
    {
        int p = 1;
        int l = 1;
        for (int i=0; i<size; i++)
        {
            printf("(%d}",tab[i]);
            
            if (p==l)
            {
                p=p*2;
                l=0;
                printf("\n");
            }
            l=l+1;
        }
        
        printf("\n");
    }
    else printf("No data\n");
}





