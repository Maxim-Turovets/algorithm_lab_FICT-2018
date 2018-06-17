// C program for Fibonacci Search
#include <stdio.h>
#include <iostream>
#include "list.h"
#include "arr.h"

  

/* driver function */
int main(void)
{  
  

	std::cout<<"Enter size arr end list\n";
	int siz;
	std::cin>>siz;
	
	int arr[siz];
	
	//  ������� ������
	for (int i=0;i<siz;i++)
	arr[i]=i;
	
	// �����
	int x;
	std::cout<<"Enter element\n";
	std::cin>>x;	
	
	// ��� �����
	for (int i=0;i<siz;i++)
    {
	 std::cout<<arr[i]<<" ";	
    }
	 
	double t=clock();				
	int n = sizeof(arr)/sizeof(arr[0]);
	

	
	Arr obj;
	// ����� �������� � �������
	printf("\nFound at index ARRAY: %d",obj.fibMonaccianSearch(arr, x, n));
	  
	std::cout<<"\nTime:\n";    
   std::cout<<(clock()-t)<<endl;
   

	
	//=======================================================================
	
	//������		
	std::cout<<"\n";
	t=clock();		// ����� 
	List ob;
	
	// ���������� 
	for (int i=0;i<siz;i++)
	ob.AddTail(i);
//	ob.Print();

    // ����� 
    printf("Found at index LIST: %d",ob.fibMonaccianSearch(ob,x-1,n));
    	std::cout<<"\nTime:\n";    
   std::cout<<(clock()-t)<<endl; // �����
	//ob.Print(1);
	
	
	
	
			
	return 0;
}
