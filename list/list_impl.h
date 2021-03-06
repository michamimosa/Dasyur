/**
 *  include/list_impl.h
 *
 *  Copyright (C) 2014 Michael Sippel
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @author Michael Sippel <michamimosa@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

template <typename T>
List<T>::List()
{
    this->head = NULL;
    this->current = NULL;
    this->size = 0;
}

template <typename T>
List<T>::~List()
{
}

template <typename T>
void List<T>::add(ListEntry<T> *entry)
{
    entry->next = NULL;
    entry->prev = this->current;

    if(this->current != NULL)
    {
        this->current->next = entry;
    }
    this->current = entry;
    if(this->head == NULL)
    {
        this->head = entry;
    }

    this->size++;
}

template <typename T>
void List<T>::remove(ListEntry<T> *entry)
{
    if(entry->prev != NULL)
    {
        entry->prev->next = entry->next;
    }
    else
    {
        this->head = entry->next;
    }

    if(entry->next != NULL)
    {
        entry->next->prev = entry->prev;
    }
    else
    {
        this->current = entry->prev;
    }
}

template <typename T>
void List<T>::join(List<T> *list)
{
    if(list != NULL)
    {
        if(this->head == NULL)
        {
            this->head = list->head;
        }
        else
        {
            this->current->next = list->head;
            list->head->prev = this->current;
        }
        this->current = list->current;
        this->size += list->size;
    }
}
template <typename T>
ListEntry<T> *List<T>::add(T *element)
{
    ListEntry<T> *entry = new ListEntry<T>(element);
    this->add(entry);

    return entry;
}

template <typename T>
ListEntry<T> *List<T>::add(T *element, const char *name)
{
    return this->add(element, (char*) name);
}

template <typename T>
ListEntry<T> *List<T>::add(T *element, char *name)
{
    ListEntry<T> *entry = new ListEntry<T>(element, name);
    this->add(entry);

    return entry;
}

template <typename T>
ListEntry<T> *List<T>::getEntry(const char *name_)
{
    return this->getEntry((char*) name_);
}

template <typename T>
ListEntry<T> *List<T>::getEntry(char *name_)
{
    if(name_ == NULL)
    {
        return NULL;
    }

    ListEntry<T> *entry = this->head;
    while(entry != NULL)
    {
        if(strcmp(entry->name, name_) == 0)
        {
            return entry;
        }
        entry = entry->next;
    }

    return NULL;
}

template <typename T>
T *List<T>::getElement(const char *name_)
{
    return this->getElement((char*) name_);
}

template <typename T>
T *List<T>::getElement(char *name_)
{
    ListEntry<T> *entry = this->getEntry(name_);

    if(entry != NULL)
    {
        return entry->element;
    }

    return NULL;
}

template <typename T>
ListEntry<T> *List<T>::isContained(T *e)
{
    ListEntry<T> *entry = this->head;
    while(entry != NULL)
    {
        if(entry->element == e)
        {
            return entry;
        }
        entry = entry->next;
    }

    return NULL;
}

template <typename T>
ListEntry<T> *List<T>::getHead(void)
{
    return this->head;
}

template <typename T>
ListEntry<T> *List<T>::getCurrent(void)
{
    return this->current;
}

template <typename T>
int List<T>::getSize(void)
{
    return this->size;
}

