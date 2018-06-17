#include "arr.h"

Arr::Arr()
{
}

Arr::~Arr()
{
}

//  функция для поиска минимум двух элементов
int Arr:: min(int x, int y) 
{
 return (x<=y)? x : y;

  }

/*Возвращает индекс x, если он присутствует, else возвращает -1 */

int Arr::fibMonaccianSearch(int arr[], int x, int n)
{ 
    
	/* Инициализировать число фибоначчи*/
	int fibMMm2 = 0; // (m -2)'th Fibonacci No.
	int fibMMm1 = 1; // (m -1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/*fibM собирается хранить самый маленький Fibonacci
    Число, большее или равное n */
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Отмечает устраненный диапазон спереди
	int offset = -1;

	/* в то время как есть элементы, подлежащие проверке. Обратите внимание, что
    мы сравниваем arr [fibMm2] с x. Когда fibM становится равным 1,
    fibMm2 становится 0 */
	while (fibM > 1)
	{
		// Проверьте правильность местоположения fibMm2
		int i = min(offset+fibMMm2, n-1);
         
		/*Если x больше значения в index fibMm2,
        вырезать массив подмассивов из смещения в i */
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
			
		}

		/*Если x больше значения в index fibMm2,
        разрезать подмассиву после i + 1 */
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else return i;
	}
    
	/* сравнивая последний элемент с x */
	if(fibMMm1 && arr[offset+1]==x)return offset+1;
     
    
	/*element not found. return -1 */
	return -1;
	
  
}
