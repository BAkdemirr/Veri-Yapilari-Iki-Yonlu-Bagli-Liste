/**
* @file CircularDoublyLinkedList.hpp
* @description CircularDoublyLinkedList sınıfı, liste üstünde yapılabilcek işlemlerin fonksiyon tanımları, Açıklamalar burda.
* @course 2/B
* @assignment 1.Ödev
* @date 25 Kasım 2020
* @author Berkecan Akdemir
*/
#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include "Node.hpp"

class CircularDoublyLinkedList
{
private:
	Node* center; 

	int size; 

	//verilen indexten önceki düğümü bulup döndürme fonksiyonu
	Node* FindPreviousNode(int index); 

public:
	
	// kurucu fonksiyon
	CircularDoublyLinkedList(); 
	
	
	// liste boş mu kontrolü yapan fonksiyon
	bool isEmpty() const; 
	
	
	// parametre olarak gelen dizinin içindeki elemanları algoritmaya sadık kalarak listeye ekleme fonksiyonu
	void add1(int* array, int length); 
	// listeye düz ekleme fonksiyonu
	void add2(const int& item); 
	// listeye index belirterek ekleme fonksiyonu
	void insert(int index, const int& item); 
	
	
	// listeden istenen datayı içeren düğümü silme fonksiyonu
	void remove(const int& item);
	// listeyi ters çevirip silerek ekleme fonksiyonu
	void deleteAndAdd(); 
	// belirttiğimiz indexteki düğümü silme fonksiyonu
	Node* removeAt(int index); 
	// listeyi temizleme fonksiyonu
	void clear(); 
	
	
	// listenin lengthini döndüren fonksiyon
	int getSize() const; 
	// takaslama işleminden sonra listenin lengthini tespit etme fonksiyonu
	void sizeCalculate(); 
	// verilen data hangi indexte onu bulan fonksiyon
	int indexOf(const int& item) const; 
	
	
	// orta düğümün verisini döndürme.
	int getCenterData(); 
	// orta düğümün kendisini döndürme.
	Node* getCenter(); 
	
	
	// listeyi orta düğümden sağa doğru yazdıran fonksiyon
	void printFromCenter(); 
	// listeyi baştan sona doğru yazdıran fonksiyon
	void print(); 
	// belirtilen indexten başlayarak tersten yani sola doğru listeyi yazdıran fonksiyon
	void printListFromIndexReverse(int index); 
	// listeyi tersten yani sağdan sola yazdıran fonksiyon	
	void printListReverse(); //listeyi tersten yazdırma fonksiyonu
	
	// belirtilen datayı listede arayıp bulursa true bulamazsa false döndüren fonksiyon
	bool find(const int& item) const; 

	// yıkıcı fonk
	~CircularDoublyLinkedList(); 
};

#endif