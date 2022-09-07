/**
* @file CircularDoublyLinkedList.cpp
* @description dairesel listenin fonksiyonlarının işlevleri burada yazılı. Fonksiyonların ne yaptığının açıklaması hpp dosyasında.
* @course 2/B
* @assignment 1.Ödev
* @date 25 Kasım 2020
* @author Berkecan Akdemir
*/
#include "CircularDoublyLinkedList.hpp"

CircularDoublyLinkedList::CircularDoublyLinkedList() 
{
    center = NULL; 
    size = 0; 
}

Node* CircularDoublyLinkedList::FindPreviousNode(int index) 
{
    Node* former = center;
    int a = 1;
    for (Node* iterator = center; a != index; iterator = iterator->next, a++) former = former->next;
    return former;
}

bool CircularDoublyLinkedList::isEmpty() const 
{
    return size == 0;
}

void CircularDoublyLinkedList::add1(int* array, int length) 
{
    Node* leftNode;				
    Node* iterator;
    for (int a = 0; a <= length / 2; a++)  
    {
        if (size == 0)
        {
            center = new Node(array[a]);
            center->next = center->previous = center;
            size++;
        }
        else
        {
            iterator = center;

            while (iterator->previous != center)
            {
                iterator = iterator->previous;
            }

            iterator = new Node(array[a], iterator, iterator->previous);
            iterator->next->previous = iterator;
            iterator->previous->next = iterator;
            size++;
        }
    }
    leftNode = iterator;
    for (int a = (length / 2) + 1; a < length; a++) 
    {
        iterator = center;

        while (iterator->next != leftNode)
        {
            iterator = iterator->next;
        }

        iterator->next = new Node(array[a], iterator->next, iterator);
        iterator->next->next->previous = iterator->next;
        size++;
    }
    iterator = NULL;
    leftNode = NULL;
    delete iterator;
    delete leftNode;
}

void CircularDoublyLinkedList::add2(const int& item) 
{
    insert(size, item);
}

void CircularDoublyLinkedList::insert(int index, const int& item) 
{
    //if(index<0 || index>size) hata
    if (index == 0)
    {
        if (size == 0)
        {
            center = new Node(item);
            center->next = center->previous = center;
        }
        else
        {
            center = new Node(item, center, center->previous);
            center->next->previous = center;
            center->previous->next = center;
        }
    }
    else
    {
        Node* prv = FindPreviousNode(index);
        prv->next = new Node(item, prv->next, prv);
        prv->next->next->previous = prv->next;
    }
    size++;
}

void CircularDoublyLinkedList::remove(const int& item) 
{
    int index = indexOf(item);
    //if(index == -1 )hata
    removeAt(index);
}

void CircularDoublyLinkedList::deleteAndAdd() 
{
    Node* first = center;
    Node* last;
    Node* tmp;
    int length = this->getSize();
    int index = (length / 2) + 1;

    for (int a = 0; a < length / 2; a++)
    {
        first = first->previous;
    }
    tmp = first;
    last = first->previous;
    
    int sayac = 0;
    while (tmp != last)
    { 
        

        for (int a = 0; a < length / 2; a++)
        {
            if (tmp == last)
                break;
            tmp = tmp->next;
            Node* tmp = removeAt(index);
            tmp->next = last->next;
            tmp->previous = last;
            last->next = tmp;
            last->next->next->previous = last->next;
            size++;
            index++;
        }
        if (tmp == last)
            break;
        index = 1;
        last = center->previous;
        
        for (int a = 0; a < length / 2; a++)
        {
            if (tmp == last)
                break;

            tmp = tmp->next;
            Node* tmp1 = removeAt(index);
            tmp1->next = last->next;
            tmp1->previous = last;
            last->next = tmp1;
            last->next->next->previous = last->next;

            size++;
            
        }
        
        if (tmp == last)
            break;
        break;
    }
	// silmeden önce null a eşitleme nedeni: mevcut düğümü değil değişkeni silsin.
    first = NULL; 
    last = NULL;
    tmp = NULL;
    delete first; 
    delete last; 
    delete tmp; 
}

Node* CircularDoublyLinkedList::removeAt(int index) 
{
    //if(index<0 || index>=size) hata
    Node* sil;
    Node* iterator = center;
    if (index == 0)
    {
        int length = this->getSize();

        for (int a = 0; a < length / 2; a++)
        {
            iterator = iterator->previous;
        }
        sil = iterator;
        if (size == 1)
        {
            iterator = iterator->next = iterator->previous = NULL;
        }
        else
        {
            iterator = iterator->next;
            iterator->previous = sil->previous;
            sil->previous->next = iterator;
        }
    }
    else
    {
        Node* prv = FindPreviousNode(index);
        sil = prv->next;
        prv->next = sil->next;
        sil->next->previous = prv;
    }
    size--;
    return sil;
}

void CircularDoublyLinkedList::clear() 
{
    while (!isEmpty())
    {
        removeAt(0);
    }
}

int CircularDoublyLinkedList::getSize() const 
{
    int length=this->size;
    return length;              
}

void CircularDoublyLinkedList::sizeCalculate() 
{
    Node* iterator = center;   
    int counter = 0;

    do 
    {
        iterator = iterator->next;
        counter++;
    } while (iterator != center);
    this->size = counter;
}

int CircularDoublyLinkedList::indexOf(const int& item) const 
{
    int index = 0;
    for (Node* yineleyici = center; index < size; yineleyici = yineleyici->next)
    {
        if (yineleyici->data == item)
            return index;
        index++;
    }
    return -1;
}

int CircularDoublyLinkedList::getCenterData() 
{
    return center->data;
} 

Node *CircularDoublyLinkedList::getCenter() 
{
    return center;
}

void CircularDoublyLinkedList::printFromCenter() 
{
    Node* iterator = center;

    do
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    } while (iterator != center);
    cout << endl;
}

void CircularDoublyLinkedList::print() 
{
    Node* iterator = center;
    Node* tmp;
    int length = this->getSize();

    for (int a = 0; a < length / 2; a++)
    {
        iterator = iterator->previous;
    }
    tmp = iterator;
    cout << iterator->data << " ";
    iterator = iterator->next;

    while (iterator != tmp)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}

void CircularDoublyLinkedList::printListFromIndexReverse(int index) 
{
    //if(index<=0 || index>=size) hata
    int a = 0;
    for (Node *yineleyici = FindPreviousNode(index + 1); a < size; yineleyici = yineleyici->previous, a++)
        cout << yineleyici->data << " ";
    cout << endl;
}

void CircularDoublyLinkedList::printListReverse() 
{
    printListFromIndexReverse(size - 1);
}

bool CircularDoublyLinkedList::find(const int& item) const 
{
    int index = 0;
    for (Node *yineleyici = center; index < size; yineleyici = yineleyici->next, index++)
    {
        if (yineleyici->data == item)
            return true;
    }
    return false;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() 
{
    clear(); 
}


