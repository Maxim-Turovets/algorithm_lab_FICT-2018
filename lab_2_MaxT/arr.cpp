#include "arr.h"

Arr::Arr()
{
}

Arr::~Arr()
{
}

//  ������� ��� ������ ������� ���� ���������
int Arr:: min(int x, int y) 
{
 return (x<=y)? x : y;

  }

/*���������� ������ x, ���� �� ������������, else ���������� -1 */

int Arr::fibMonaccianSearch(int arr[], int x, int n)
{ 
    
	/* ���������������� ����� ���������*/
	int fibMMm2 = 0; // (m -2)'th Fibonacci No.
	int fibMMm1 = 1; // (m -1)'th Fibonacci No.
	int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/*fibM ���������� ������� ����� ��������� Fibonacci
    �����, ������� ��� ������ n */
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// �������� ����������� �������� �������
	int offset = -1;

	/* � �� ����� ��� ���� ��������, ���������� ��������. �������� ��������, ���
    �� ���������� arr [fibMm2] � x. ����� fibM ���������� ������ 1,
    fibMm2 ���������� 0 */
	while (fibM > 1)
	{
		// ��������� ������������ �������������� fibMm2
		int i = min(offset+fibMMm2, n-1);
         
		/*���� x ������ �������� � index fibMm2,
        �������� ������ ����������� �� �������� � i */
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
			
		}

		/*���� x ������ �������� � index fibMm2,
        ��������� ���������� ����� i + 1 */
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else return i;
	}
    
	/* ��������� ��������� ������� � x */
	if(fibMMm1 && arr[offset+1]==x)return offset+1;
     
    
	/*element not found. return -1 */
	return -1;
	
  
}
