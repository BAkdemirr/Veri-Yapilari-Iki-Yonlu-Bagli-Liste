/**
* @file Test.cpp
* @description sınıfları ve fonksiyonları kullanarak gerekli işler yaptırılır.
* @course 2/B
* @assignment 1.Ödev
* @date 25 Kasım 2020
* @author Berkecan Akdemir
*/
#include <iostream>
#include <sstream>
#include "CircularDoublyLinkedList.hpp"
#include <fstream>


using namespace std;

// Sayilar.txt de kaç satır var.
int lineCounter()
{ 
	int sayac = 0;
	string satir;

	ifstream file("Sayilar.txt");
	while (getline(file, satir))
		sayac++;

	file.close();
	return sayac; 
}


// listeler inceleyip en büyük en küçük değeri bulan işlemleri yapan fonk. 
void enBuyukEnKucukDegerBul(CircularDoublyLinkedList** listeler, int boyut)
{ // parametre olarak tüm listeleri gösteren bir işaretçi alıyoruz bir de dosyada kaç liste olduğunu temsil eden boyut alıyoruz.
	int a, enBuyuk, enKucuk;
	enBuyuk = listeler[0]->getCenterData();
	enKucuk = listeler[0]->getCenterData();
	int enBuyukIndex = 0;
	int enKucukIndex = 0;
	
	// liste sayısı kadar dönüp listeleri kontrol ediyorum enBuyuk ve enKucuk değeri içeren değerleri buluyor.
	for (a = 1; a < boyut; a++) 
	{
		if (listeler[a]->getCenterData() >= enBuyuk)
		{
			
			enBuyuk = listeler[a]->getCenterData();
			enBuyukIndex = a;
		}
		if (listeler[a]->getCenterData() < enKucuk)
		{
			
			enKucuk = listeler[a]->getCenterData();
			enKucukIndex=a;
		}
	}
	
	CircularDoublyLinkedList* maxValueHolding; // enBuyuk değeri içeren listeyi gösterecek işaretçi
	CircularDoublyLinkedList* minValueHolding; // enKucuk değeri içeren listeyi gösterecek işaretçi
	maxValueHolding=listeler[enBuyukIndex];
	minValueHolding=listeler[enKucukIndex];
	
	
	cout<<"\nEn Buyuk Listenin Ortadaki Elemani =" << enBuyuk << "\n";
	cout<<"En Kucuk Listenin Ortadaki Elemani =" << enKucuk<<endl;

	// listeler için ters çevirme yapacak fonku çalıştır.
	minValueHolding->deleteAndAdd(); 
	maxValueHolding->deleteAndAdd(); 
	
	
	// Listeler burada takaslanır.
	Node* tmp;
	tmp = minValueHolding->getCenter()->next;
	minValueHolding->getCenter()->next->previous = maxValueHolding->getCenter();
	maxValueHolding->getCenter()->next->previous = minValueHolding->getCenter();
	minValueHolding->getCenter()->next = maxValueHolding->getCenter()->next;
	maxValueHolding->getCenter()->next = tmp;

	tmp = minValueHolding->getCenter()->previous;
	minValueHolding->getCenter()->previous->next = maxValueHolding->getCenter();
	minValueHolding->getCenter()->previous = maxValueHolding->getCenter()->previous;
	maxValueHolding->getCenter()->previous->next = minValueHolding->getCenter();
	maxValueHolding->getCenter()->previous = tmp;
	maxValueHolding->sizeCalculate();
	minValueHolding->sizeCalculate();
	
	// En büyük düğümü içeren listenin orta düğümünün adresini yazdırıyorum.
	cout << "En Buyuk Liste Orta Dugum Adres:" << (maxValueHolding->getCenter()) << endl;
	// En büyük düğümü içeren listeyi yazdırma
	maxValueHolding->print();	
	// En küçük düğümü içeren listenin orta düğümünün adresini yazdırıyorum.
	cout << "En Kucuk Liste Orta Dugum Adres:" << (minValueHolding->getCenter()) << endl; 
	//en küçük düğümü içeren listeyi yazdırma
	minValueHolding->print(); 
}

int main()
{
	// satır sayısını lineCounter fonksiyonu ile hesaplayıp değişkene atıyoruz.
	int lineSize = lineCounter();
	
	// dairesel listelerin tamamını içinde barındıracak işaretçi
	CircularDoublyLinkedList** listeler = new CircularDoublyLinkedList *[lineSize]; 
	
	// dairesel listeyi işaret edecek işaretçi
	CircularDoublyLinkedList* liste;
	
	// dosya okuma açma işlemi
	ifstream file("Sayilar.txt");			
	string satir;
	
	int listedekiElemanSayisi = 0;
	int listeSayisi = 0;

	while (getline(file, satir))
	{
		listedekiElemanSayisi = 0;
		liste = new CircularDoublyLinkedList(); 
		stringstream linestream(satir);
		string deger;
		
		// kaç adet eleman var
		while (getline(linestream, deger, ' '))
		{
			listedekiElemanSayisi++; 
		}
		
		//işaretçi dizi oluşturuyoruz satırdaki eleman sayısı kadar kapasiteye sahip.
		int* array = new int[listedekiElemanSayisi]; 
		listedekiElemanSayisi = 0;
		stringstream linestream1(satir);
		
		//diziye satırda bulunan elemanları atarak dolduruyoruz.
		while (getline(linestream1, deger, ' '))
		{
			array[listedekiElemanSayisi] = stoi(deger); 
			listedekiElemanSayisi++;
		}
		
		// listeye ekle fonksiyonunun parametrelerine satırdaki sayılardan oluşan diziyi ve kaç eleman olduğunu gönderiyoruz.
		liste->add1(array, listedekiElemanSayisi); 
		
		// listeleri tutan işaretçiye listenin adresini işaret ettiriyoruz.
		listeler[listeSayisi] = liste; 
		listeSayisi++;

		
		delete array; 
	}
	file.close(); 

	enBuyukEnKucukDegerBul(listeler, lineSize);
	for (int i = 0; i < lineSize; i++)
	{
		// bellekteki tüm listelerin silinme işlemi burada
		delete listeler[i]; 
	}
	delete listeler; // listeleri işaret eden işaretçinin silinmesi burada
	return 0;
}


