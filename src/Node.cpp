/**
* @file Node.cpp
* @description düğüm sınıfının yapacağı iş burada yazılı. Fonksiyon işlemleri cpplerde.
* @course 2/B
* @assignment 1.Ödev
* @date 25 Kasım 2020
* @author Berkecan Akdemir
*/
#include "Node.hpp"
Node::Node(const int data, Node* next, Node* previous) 
{
    this->next = next;
    this->previous = previous;
    this->data = data;
}
