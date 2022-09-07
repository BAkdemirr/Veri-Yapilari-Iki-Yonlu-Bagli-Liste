/**
* @file Node.hpp
* @description düğüm sınıfı ve fonksiyon tanımlamaları burada
* @course 2/B
* @assignment 1.Ödev
* @date 25 Kasım 2020
* @author Berkecan Akdemir
*/
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node
{
public:
	int data; 
	Node* next; 
	Node* previous; 

	Node(const int data, Node* next = NULL, Node* previous = NULL);
};
#endif
