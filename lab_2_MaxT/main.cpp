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
	
	//  создаем массив
	for (int i=0;i<siz;i++)
	arr[i]=i;
	
	// число
	int x;
	std::cout<<"Enter element\n";
	std::cin>>x;	
	
	// его вывод
	for (int i=0;i<siz;i++)
    {
	 std::cout<<arr[i]<<" ";	
    }
	 
	double t=clock();				
	int n = sizeof(arr)/sizeof(arr[0]);
	

	
	Arr obj;
	// поиск елемента в массиве
	printf("\nFound at index ARRAY: %d",obj.fibMonaccianSearch(arr, x, n));
	  
	std::cout<<"\nTime:\n";    
   std::cout<<(clock()-t)<<endl;
   

	
	//=======================================================================
	
	//список		
	std::cout<<"\n";
	t=clock();		// время 
	List ob;
	
	// добавление 
	for (int i=0;i<siz;i++)
	ob.AddTail(i);
//	ob.Print();

    // поиск 
    printf("Found at index LIST: %d",ob.fibMonaccianSearch(ob,x-1,n));
    	std::cout<<"\nTime:\n";    
   std::cout<<(clock()-t)<<endl; // время
	//ob.Print(1);
	
	
	
	
			
	return 0;
}
