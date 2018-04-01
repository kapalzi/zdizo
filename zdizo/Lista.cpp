//
//  Lista.cpp
//  zdizo
//
//  Created by Krzysztof Kapała on 10.03.2018.
//  Copyright © 2018 Krzysztof Kapała. All rights reserved.
//

#include "Lista.hpp"

Lista::Lista()
{
    head = NULL;
    tail = NULL;
    counter = 0;
}

void Lista::pushFront(int data)
{
    Element *newElement = new Element();
    newElement->data = data;
    newElement->previous = NULL;
    
    if(head)
    {
        head->previous = newElement;
        newElement->next=head;
        head = newElement;
    }
    else
    {
        newElement->next = NULL;
        head = newElement;
        tail = newElement;
    }
    counter++;
}

void Lista::pushBack(int data)
{
    Element *newElement = new Element();
    newElement->data = data;
    newElement->next = NULL;
    
    if(tail)
    {
        tail->next = newElement;
        newElement->previous=tail;
        tail = newElement;
    }
    else
    {
        newElement->previous = NULL;
        head = newElement;
        tail = newElement;
    }
    counter++;
}
void Lista::pushAtIndex(int index, int data)
{
    if(head)
    {
        Element *newElement = new Element;
        Element *pointedElement = head;

        if (index==0)
        {
            pushFront(data);
            return;
        }
        
        if(index==counter)
        {
            pushBack(data);
            return;
        }
        
        if(counter>=index)
        {
            for (int i = 0; i < index; i++)
            {
                pointedElement = pointedElement->next;
            }
            newElement->previous = pointedElement->previous;
            pointedElement->previous->next = newElement;
            
            if (pointedElement->next==NULL) pointedElement->previous = newElement;
            else pointedElement->next->previous = newElement;
            
            newElement->next = pointedElement;
            
            newElement->data = data;

            counter++;
        }
    }
}

void Lista::popFront()
{
    if(head)
    {
        Element *tmpElement = new Element();
        tmpElement = head;
        head = head->next;
        delete tmpElement;
    }
    else
    {
        return;
    }
    counter--;
}

void Lista::popBack()
{
    if(tail)
    {
        Element *tmpElement = new Element();
        tmpElement = tail;
        tail = tail->previous;
        delete tmpElement;
    }
    else
    {
        return;
    }
    counter--;
}

void Lista::popAtIndex(int index)
{
    if(head)
    {
        Element *pointedElement = head;
        
        if(index==0)
        {
            popFront();
            return;
        }
        
        if(index==counter-1)
        {
            popBack();
            return;
        }
        
        if(counter>index)
        {
            for (int i = 0; i < index; i++)
            {
                pointedElement = pointedElement->next;
            }
            
            pointedElement->previous->next = pointedElement->next;
            
            pointedElement->next->previous = pointedElement->previous;

            delete pointedElement;
            counter--;
        }
    }
}

bool Lista::isValue(int value)
{
    if(head)
    {
        Element *newElement = head;
        for (int i=0; i< counter; i++)
        {
            if (newElement->data == value)
            {
                return true;
            }
            newElement = newElement->next;
        }
    }
    return false;
}

void Lista::print()
{
    if(head)
    {
        Element *newElement = head;
        for (int i=0; i< counter; i++)
        {
            printf("[%d]",newElement->data);
            newElement = newElement->next;
        }
        printf("\n");
    }
    else printf("No data\n");
}
