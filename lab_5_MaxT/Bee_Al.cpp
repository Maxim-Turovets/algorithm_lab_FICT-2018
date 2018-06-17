
#include <iostream>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define XRY 100  //Количество вершин графа.

using namespace std;
typedef int Boolean;
typedef struct Node *svqz;
typedef struct Node
{
  int Key;  // Вершина графа.
  svqz Up;  // Указатель на смежную вершину.
  svqz Sled;// Указатель на следующую смежную вершину.
};

class Lists
{
  private:
     svqz Beg[XRY+1]; //Массив указателей на вершины.
     void Add_Bee (int);
     int Find (int, int, svqz *);
     void Greedy_Algorithm (int, int);
     void Make (int, int);
     void Delinenok (int, int);
     void Bee_Algorithm (int, int);
     void Bee (int);
     int Find_Color (int, int, svqz *);
  public:
     Lists();
     void Init_Graph ();
     void Make_Graph ();
     void Print_Graph ();
     void Color ();
     void Print_Color ();
};

int  main ()
{
  Lists A;
  setlocale (0,"rus"); 
  A.Init_Graph ();
  A.Make_Graph ();
  A.Print_Graph ();
  getch();
  A.Color ();
  A.Print_Color (); 
  getch();
}

Lists::Lists()
{
  for ( int i=0; i<=XRY;Beg[i++] = NULL );
}

void Lists::Add_Bee (int x)
{
  svqz Ukaz = new (Node);

  Ukaz->Sled = NULL; 
  Beg[x] = Ukaz;
}

void Lists::Init_Graph ()
{
  for (int i=1;i<=XRY;i++) Add_Bee (i);
}

int Lists::Find (int x, int y, svqz *UkZv)
{
  svqz Ukaz;

  Ukaz = Beg[x]->Sled;
  while  (Ukaz != NULL && Ukaz->Key != y) 
     Ukaz = Ukaz->Sled;
  *UkZv = Ukaz;
  return  ( Ukaz != NULL );
}

void Lists::Greedy_Algorithm (int x, int y)
{
  svqz Ukaz = new (Node);

   Ukaz->Sled = Beg[x]->Sled; Ukaz->Key = y;
   Beg[x]->Sled = Ukaz;
}

void Lists::Make (int x, int y)
{
  svqz Ukaz;

  if  ( !Find(x,y,&Ukaz) )
  {
     Greedy_Algorithm (x,y);
     if ( x != y ) Greedy_Algorithm (y,x);
     Beg[x]->Sled->Up = Beg[y];
     Beg[y]->Sled->Up = Beg[x];
  }
}

void Lists::Make_Graph ()
{
  int f;
   
  for (int i=1;i<=XRY;i++)
  {
    cout << "Введите вершины, смежные с " << i << "-й вершиной: ";
    cin >> f;
    while (f!=0)
    {
      Make (i,f); 
      cout << " "; 
      cin >> f;
    }
    cout << endl;
  }
}

void Lists::Delinenok (int x, int y)
{
  svqz Ukaz;
  svqz Ukazlenok;
  
  Ukazlenok = Beg[x]; Ukaz = Beg[x]->Sled;
  while (Ukaz != NULL && Ukaz->Key != y)
  {  Ukazlenok = Ukaz; Ukaz = Ukaz->Sled; }
  if ( Ukaz != NULL )
  {
     Ukazlenok->Sled = Ukaz->Sled;
     delete Ukaz;
  }
}

void Lists::Bee_Algorithm (int x, int y)
{
  Delinenok (x,y); Delinenok (y,x);
}

void Lists::Bee (int x)
{
  svqz Ukaz;
  svqz Ukazlenok;

  for (int i=1;i<=XRY;i++) Delinenok (i,x);
  Ukaz = Beg[x]; Beg[x] = NULL;
  while ( Ukaz != NULL )
  {
     Ukazlenok = Ukaz->Sled;
     delete Ukaz; Ukaz = Ukazlenok;
  }
}

void Lists::Print_Graph ()
{
  svqz UkZv;
  
  for (int i=1;i<=XRY;i++)
  {
    if ( Beg[i] != NULL )
    {
      UkZv = Beg[i]->Sled;
      cout << i << " - ";
      while ( UkZv != NULL )
      {
        cout << " " << UkZv->Key;
        UkZv = UkZv->Sled;
      }
    }
    cout << endl;
  }
}

int Lists::Find_Color (int x, int c, svqz *UkZv)
{
   int i = 1;
   
   while (!(Find(x,i,&(*UkZv)) &&
          Beg[i]->Key==c)   && 
          i != x) i++;
   return (i==x);
}

void Lists::Color ()
{
  int i = 1;
  int c = 1;
  svqz UkZv;
   
  while  (Beg[i] == NULL && i<=XRY) i++;
  if ( i != XRY )
  {
    Beg[i]->Key = c;
    i++;
    while  (i<=XRY)  
     if ( Beg[i] != NULL )
     {
       c = 1;
       while  (!Find_Color(i,c,&UkZv)) c++;
       Beg[i]->Key = c; i++;
     }
     else  i++;
  }
  else  cout << "Граф отсутствует!";
}

void Lists::Print_Color ()
{                 
  for (int i=1;i<=XRY;i++)
    if ( Beg[i] != NULL )
       cout << "Вершина " << i << " Цвет - " << Beg[i]->Key << endl;
}
