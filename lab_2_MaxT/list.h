#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;




struct Elem
{
   int data; // ������
   Elem * next, * prev;
};

class List
{
   // ������, �����
   Elem * Head, * Tail;
   // ���������� ���������
   int Count;

public:

   // �����������
   List();
   // ����������� �����������
   List(const List&);
   // ����������
   ~List();
 
   // �������� ����������
   int GetCount();
   // �������� ������� ������
   Elem* GetElem(int);
	
	int Get(int);
   // ������� ���� ������
   void DelAll();
   // �������� ��������, ���� �������� �� �����������,
   // �� ������� ��� �����������
   void Del(int pos = 0);
   // ������� ��������, ���� �������� �� �����������,
   // �� ������� ��� �����������
   void Insert(int pos = 0);
	
   // ���������� � ����� ������
   void AddTail(int n);
	
   // ���������� � ������ ������
   void AddHead(int n);
		
   // ������ ������
   void Print();	
   // ������ ������������� ��������
   void Print(int pos);
	
   List& operator = (const List&);
   // �������� ���� ������� (�����������)
   List operator + (const List&);
	
   // ��������� �� ���������
   bool operator == (const List&);
   bool operator != (const List&);
   bool operator <= (const List&);
   bool operator >= (const List&);
   bool operator < (const List&);
   bool operator > (const List&);

   // ��������������� ������
   List operator - ();
   
   int  min(int x, int y);

   int fibMonaccianSearch(List obj, int x, int n);
};


#endif
