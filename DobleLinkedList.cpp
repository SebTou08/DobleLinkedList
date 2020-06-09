#include "DobleLinkedList.h"
#include "car.h"
#include<ctime>
#include<stdlib.h>


int main()
{
    srand(time(NULL));

    DobleLinkedList<car*>lista;
    car *carrito[10];
    //lista.LoadData();
    for (size_t i = 0; i<10;++i)
    {
        carrito[i] = new car();
        lista.BeginningAddition(carrito[i]);
    }


    lista.Show();

    lista.BubbleSort();
    cout << "\n ---------listaordenada-------- \n<\n\n";
    lista.Show();
    cout << "\n\n Filtrado por lambda: \n \n";
    auto todos = [](car* c) {return (c->getanio() > 2005) ? true : false; };
   lista.lamb(todos);
    
    cin.get();
    return 0;
   
}