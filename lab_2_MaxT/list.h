#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;




struct Elem
{
   int data; // данные
   Elem * next, * prev;
};

class List
{
   // Голова, хвост
   Elem * Head, * Tail;
   // Количество элементов
   int Count;

public:

   // Конструктор
   List();
   // Конструктор копирования
   List(const List&);
   // Деструктор
   ~List();
 
   // Получить количество
   int GetCount();
   // Получить элемент списка
   Elem* GetElem(int);
	
	int Get(int);
   // Удалить весь список
   void DelAll();
   // Удаление элемента, если параметр не указывается,
   // то функция его запрашивает
   void Del(int pos = 0);
   // Вставка элемента, если параметр не указывается,
   // то функция его запрашивает
   void Insert(int pos = 0);
	
   // Добавление в конец списка
   void AddTail(int n);
	
   // Добавление в начало списка
   void AddHead(int n);
		
   // Печать списка
   void Print();	
   // Печать определенного элемента
   void Print(int pos);
	
   List& operator = (const List&);
   // сложение двух списков (дописывание)
   List operator + (const List&);
	
   // сравнение по элементам
   bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);

   // переворачивание списка
   List operator - ();
   
   int  min(int x, int y);

   int fibMonaccianSearch(List obj, int x, int n);
};


#endif
