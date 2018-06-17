#include "list.h"

List::List()
{
   // ���������� ������ ����
   Head = Tail = NULL;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;

   // ������ ������, �� �������� ��������
   Elem * temp = L.Head;
   // ���� �� ����� ������
   while(temp != 0)
   {
      // ���������� ������
      AddTail(temp->data);
      temp = temp->next;
   }
}

List::~List()
{
   // ������� ��� ��������
   DelAll();
}

void List::AddHead(int n)
{
   // ����� �������
   Elem * temp = new Elem;

   // ����������� ���
   temp->prev = 0;
   // ��������� ������
   temp->data = n;
   // ��������� - ������ ������
   temp->next = Head;

   // ���� �������� ����?
   if(Head != 0)
      Head->prev = temp;

   // ���� ������� ������, �� �� ������������ � ������ � �����
   if(Count == 0)
      Head = Tail = temp;
   else
      // ����� ����� ������� - ��������
      Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   // ������� ����� �������
   Elem * temp = new Elem;
   // ���������� ���
   temp->next = 0;
   // ��������� ������
   temp->data = n;
   // ���������� - ������ �����
   temp->prev = Tail;
	
   // ���� �������� ����?
   if(Tail != 0)
      Tail->next = temp;
	
   // ���� ������� ������, �� �� ������������ � ������ � �����
   if(Count == 0)
      Head = Tail = temp;
   else
      // ����� ����� ������� - ���������
   Tail = temp;			

   Count++;
}

void List::Insert(int pos)
{
   // ���� �������� ����������� ��� ����� 0, �� ����������� ���
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }

  // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count + 1)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return;
   }

   // ���� ������� � ����� ������
   if(pos == Count + 1)
   {
      // ����������� ������
      int data;
      cout << "Input new number: ";
      cin >> data;
      // ���������� � ����� ������
      AddTail(data);
      return;
   }
   else if(pos == 1)
   {
      // ����������� ������
      int data;
      cout << "Input new number: ";
      cin >> data;
      // ���������� � ������ ������
      AddHead(data);
      return;
   }

   // �������
   int i = 1;

   // ����������� �� ������ n - 1 ���������
   Elem * Ins = Head;

   while(i < pos)
   {
      // ������� �� ��������, 
      // ����� ������� �����������
      Ins = Ins->next;
      i++;
   }

   // ������� �� ��������, 
   // ������� ������������
   Elem * PrevIns = Ins->prev;
	
   // ������� ����� �������
   Elem * temp = new Elem;

   // ������ ������
   cout << "Input new number: ";
   cin >> temp->data;

   // ��������� ������
   if(PrevIns != 0 && Count != 1)
      PrevIns->next = temp;
	
   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;
	
   Count++;
}

void List::Del(int pos)
{
   // ���� �������� ����������� ��� ����� 0, �� ����������� ���
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return;
   }

   // �������
   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
      // ������� �� ��������, 
      // ������� ���������
      Del = Del->next;
      i++;
   }

   // ������� �� ��������, 
   // ������� ������������ ����������
   Elem * PrevDel = Del->prev;
   // ������� �� ��������, ������� ������� �� ���������
   Elem * AfterDel = Del->next;
	
   // ���� ������� �� ������
   if(PrevDel != 0 && Count != 1)
      PrevDel->next = AfterDel;
   // ���� ������� �� �����
    if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;

   // ��������� �������?
   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;

   // �������� ��������
   delete Del;

   Count--;
}

void List::Print(int pos)
{
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return;
   }

   Elem * temp;

   // ���������� � ����� ������� 
   // ������� ���������
   if(pos <= Count / 2)
   {
      // ������ � ������
      temp = Head;
      int i = 1;

      while(i < pos)
      {
         // ��������� �� ������� ��������
         temp = temp->next;
         i++;
      }
   }
   else
   {
       // ������ � ������
      temp = Tail;
      int i = 1;

      while(i <= Count - pos)
      {
         // ��������� �� ������� ��������
         temp = temp->prev;
         i++;
      }
   }
   // ����� ��������
   cout << pos << " element: ";
   cout << temp->data << endl;
}

void List::Print()
{
   // ���� � ������ ������������ ��������, �� ��������� �� ����
   // � �������� ��������, ������� � ���������
   if(Count != 0)
   {
      Elem * temp = Head;
      while(temp->next != 0)
      {
          cout << temp->data << " ";
          temp = temp->next;
      }

      cout << temp->data << "\n";
   }
}

void List::DelAll()
{
   // ���� �������� ��������, ������� �� ������ � ������
   while(Count != 0)
      Del(1);
}

int List::GetCount()
{
    return Count;
}

Elem * List::GetElem(int pos)
{
   Elem *temp = Head;

   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return 0;
   }

   int i = 1;
   // ���� ������ ��� �������
   while(i < pos && temp != 0)
   {
      temp = temp->next;
      i++;
   }

   if(temp == 0)
      return 0;
   else
      return temp;
}

List & List::operator = (const List & L)
{
    // �������� ������������ �������� "������ ����"
    if(this == &L)
       return *this;

   // �������� ������� ������
   this->~List(); // DelAll();

   Elem * temp = L.Head;

   // �������� ��������
   while(temp != 0)
   {
      AddTail(temp->data);
      temp = temp->next;
   }

   return *this;
}
// �������� ���� �������
List List::operator + (const List& L)
{
   // ������� �� ��������� ������ �������� ������� ������
   List Result(*this);
   // List Result = *this;
	
   Elem * temp = L.Head;

   // ��������� �� ��������� ������ �������� ������� ������
   while(temp != 0)
   {
      Result.AddTail(temp->data);
      temp = temp->next;
   }

   return Result;
}

bool List::operator == (const List& L)
{
   // ��������� �� ����������
   if(Count != L.Count)
      return false;

   Elem *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   // ��������� �� ����������
   while(t1 != 0)
   {
      // ������� ������, �������
      // ��������� �� ���������� ��������
      if(t1->data != t2->data)
         return false;
		
      t1 = t1->next;
      t2 = t2->next;
  }

   return true;
}

bool List::operator != (const List& L)
{
   // ���������� ���������� ������� ���������
   return !(*this == L);
}

bool List::operator >= (const List& L)
{
   // ��������� �� ����������
   if(Count > L.Count)
      return true;
   // ��������� �� ����������
   if(*this == L)
      return true;
	
   return false;
}

bool List::operator <= (const List& L)
{
   // ��������� �� ����������
   if(Count < L.Count)
      return true;
   // ��������� �� ����������
   if(*this == L)
       return true;
	
   return false;
}

bool List::operator > (const List& L)
{
   if(Count > L.Count)
     return true;
	
   return false;
}

bool List::operator < (const List& L)
{
   if(Count < L.Count)
       return true;
	
   return false;
}

// ���������
List List::operator - ()
{
   List Result;

   Elem * temp = Head;
   // �������� �������� ������, ������� � ���������,
   // � ���� ����� ���������� ��������� � ������,
   // ����� ������� ��������� ������ Result ����� ���������
   // �������� � �������� �������
   while(temp != 0)
   {
       Result.AddHead(temp->data);
       temp = temp->next;
   }

   return Result;
}

int List::Get(int pos)
{
   // ������� �� 1 �� Count?
   if(pos < 1 || pos > Count)
   {
      // �������� �������
      cout << "Incorrect position !!!\n";
      return 0;
   }

   Elem * temp;

   // ���������� � ����� ������� 
   // ������� ���������
   if(pos <= Count / 2)
   {
      // ������ � ������
      temp = Head;
      int i = 1;

      while(i < pos)
      {
         // ��������� �� ������� ��������
         temp = temp->next;
         i++;
      }
   }
   else
   {
       // ������ � ������
      temp = Tail;
      int i = 1;

      while(i <= Count - pos)
      {
         // ��������� �� ������� ��������
         temp = temp->prev;
         i++;
      }
   }
   // ����� ��������
   return  temp->data;
}


// Utility function to find minimum of two elements
int List:: min(int x, int y) { return (x<=y)? x : y; }

/* Returns index of x if present, else returns -1 */

int List::fibMonaccianSearch(List obj, int x, int n)
{
	/* Initialize fibonacci numbers */
	int fibMMm2 = 0; // (m -2)'th Fibonacci No.
	int fibMMm1 = 1; // (m -1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/* fibM is going to store the smallest Fibonacci
	Number greater than or equal to n */
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front
	int offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */
	while (fibM > 1)
	{
		// Check if fibMm2 is a valid location
		int i = min(offset+fibMMm2, n-1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i */
		if (obj.Get(i) < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is greater than the value at index fibMm2,
		cut the subarray after i+1 */
		else if (obj.Get(i) > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else return i;
	}

	/* comparing the last element with x */
	if(fibMMm1 && obj.Get(offset+1)==x)return offset+1;

	/*element not found. return -1 */
	return -1;
}
