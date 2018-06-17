#include "list.h"

List::List()
{
   // Изначально список пуст
   Head = Tail = NULL;
   Count = 0;
}

List::List(const List & L)
{
   Head = Tail = NULL;
   Count = 0;

   // Голова списка, из которого копируем
   Elem * temp = L.Head;
   // Пока не конец списка
   while(temp != 0)
   {
      // Передираем данные
      AddTail(temp->data);
      temp = temp->next;
   }
}

List::~List()
{
   // Удаляем все элементы
   DelAll();
}

void List::AddHead(int n)
{
   // новый элемент
   Elem * temp = new Elem;

   // Предыдущего нет
   temp->prev = 0;
   // Заполняем данные
   temp->data = n;
   // Следующий - бывшая голова
   temp->next = Head;

   // Если элементы есть?
   if(Head != 0)
      Head->prev = temp;

   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - головной
      Head = temp;

   Count++;
}

void List::AddTail(int n)
{
   // Создаем новый элемент
   Elem * temp = new Elem;
   // Следующего нет
   temp->next = 0;
   // Заполняем данные
   temp->data = n;
   // Предыдущий - бывший хвост
   temp->prev = Tail;
	
   // Если элементы есть?
   if(Tail != 0)
      Tail->next = temp;
	
   // Если элемент первый, то он одновременно и голова и хвост
   if(Count == 0)
      Head = Tail = temp;
   else
      // иначе новый элемент - хвостовой
   Tail = temp;			

   Count++;
}

void List::Insert(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
      cout << "Input position: ";
      cin >> pos;
   }

  // Позиция от 1 до Count?
   if(pos < 1 || pos > Count + 1)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   // Если вставка в конец списка
   if(pos == Count + 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в конец списка
      AddTail(data);
      return;
   }
   else if(pos == 1)
   {
      // Вставляемые данные
      int data;
      cout << "Input new number: ";
      cin >> data;
      // Добавление в начало списка
      AddHead(data);
      return;
   }

   // Счетчик
   int i = 1;

   // Отсчитываем от головы n - 1 элементов
   Elem * Ins = Head;

   while(i < pos)
   {
      // Доходим до элемента, 
      // перед которым вставляемся
      Ins = Ins->next;
      i++;
   }

   // Доходим до элемента, 
   // который предшествует
   Elem * PrevIns = Ins->prev;
	
   // Создаем новый элемент
   Elem * temp = new Elem;

   // Вводим данные
   cout << "Input new number: ";
   cin >> temp->data;

   // настройка связей
   if(PrevIns != 0 && Count != 1)
      PrevIns->next = temp;
	
   temp->next = Ins;
   temp->prev = PrevIns;
   Ins->prev = temp;
	
   Count++;
}

void List::Del(int pos)
{
   // если параметр отсутствует или равен 0, то запрашиваем его
   if(pos == 0)
   {
       cout << "Input position: ";
       cin >> pos;
   }
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   // Счетчик
   int i = 1;

   Elem * Del = Head;

   while(i < pos)
   {
      // Доходим до элемента, 
      // который удаляется
      Del = Del->next;
      i++;
   }

   // Доходим до элемента, 
   // который предшествует удаляемому
   Elem * PrevDel = Del->prev;
   // Доходим до элемента, который следует за удаляемым
   Elem * AfterDel = Del->next;
	
   // Если удаляем не голову
   if(PrevDel != 0 && Count != 1)
      PrevDel->next = AfterDel;
   // Если удаляем не хвост
    if(AfterDel != 0 && Count != 1)
      AfterDel->prev = PrevDel;

   // Удаляются крайние?
   if(pos == 1)
       Head = AfterDel;
   if(pos == Count)
       Tail = PrevDel;

   // Удаление элемента
   delete Del;

   Count--;
}

void List::Print(int pos)
{
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return;
   }

   Elem * temp;

   // Определяем с какой стороны 
   // быстрее двигаться
   if(pos <= Count / 2)
   {
      // Отсчет с головы
      temp = Head;
      int i = 1;

      while(i < pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->next;
         i++;
      }
   }
   else
   {
       // Отсчет с хвоста
      temp = Tail;
      int i = 1;

      while(i <= Count - pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->prev;
         i++;
      }
   }
   // Вывод элемента
   cout << pos << " element: ";
   cout << temp->data << endl;
}

void List::Print()
{
   // Если в списке присутствуют элементы, то пробегаем по нему
   // и печатаем элементы, начиная с головного
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
   // Пока остаются элементы, удаляем по одному с головы
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

   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return 0;
   }

   int i = 1;
   // Ищем нужный нам элемент
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
    // Проверка присваивания элемента "самому себе"
    if(this == &L)
       return *this;

   // удаление старого списка
   this->~List(); // DelAll();

   Elem * temp = L.Head;

   // Копируем элементы
   while(temp != 0)
   {
      AddTail(temp->data);
      temp = temp->next;
   }

   return *this;
}
// сложение двух списков
List List::operator + (const List& L)
{
   // Заносим во временный список элементы первого списка
   List Result(*this);
   // List Result = *this;
	
   Elem * temp = L.Head;

   // Добавляем во временный список элементы второго списка
   while(temp != 0)
   {
      Result.AddTail(temp->data);
      temp = temp->next;
   }

   return Result;
}

bool List::operator == (const List& L)
{
   // Сравнение по количеству
   if(Count != L.Count)
      return false;

   Elem *t1, *t2;

   t1 = Head;
   t2 = L.Head;

   // Сравнение по содержанию
   while(t1 != 0)
   {
      // Сверяем данные, которые
      // находятся на одинаковых позициях
      if(t1->data != t2->data)
         return false;
		
      t1 = t1->next;
      t2 = t2->next;
  }

   return true;
}

bool List::operator != (const List& L)
{
   // Используем предыдущую функцию сравнения
   return !(*this == L);
}

bool List::operator >= (const List& L)
{
   // Сравнение по количеству
   if(Count > L.Count)
      return true;
   // Сравнение по содержанию
   if(*this == L)
      return true;
	
   return false;
}

bool List::operator <= (const List& L)
{
   // Сравнение по количеству
   if(Count < L.Count)
      return true;
   // Сравнение по содержанию
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

// переворот
List List::operator - ()
{
   List Result;

   Elem * temp = Head;
   // Копируем элементы списка, начиная с головного,
   // в свой путем добавления элементов в голову,
   // таким образом временный список Result будет содержать
   // элементы в обратном порядке
   while(temp != 0)
   {
       Result.AddHead(temp->data);
       temp = temp->next;
   }

   return Result;
}

int List::Get(int pos)
{
   // Позиция от 1 до Count?
   if(pos < 1 || pos > Count)
   {
      // Неверная позиция
      cout << "Incorrect position !!!\n";
      return 0;
   }

   Elem * temp;

   // Определяем с какой стороны 
   // быстрее двигаться
   if(pos <= Count / 2)
   {
      // Отсчет с головы
      temp = Head;
      int i = 1;

      while(i < pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->next;
         i++;
      }
   }
   else
   {
       // Отсчет с хвоста
      temp = Tail;
      int i = 1;

      while(i <= Count - pos)
      {
         // Двигаемся до нужного элемента
         temp = temp->prev;
         i++;
      }
   }
   // Вывод элемента
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
