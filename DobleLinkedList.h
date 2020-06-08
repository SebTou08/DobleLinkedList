#ifndef __DOBLELINKEDLIST_H__
#define __DOBLELINKEDLIST_H__
#include "car.h"

template <typename TipoGen>
class DobleLinkedList;

template <typename TipoGen>
class Node
{
private:
    TipoGen data;
    Node<TipoGen> *next;
    Node<TipoGen> *prev;
    friend class DobleLinkedList<TipoGen>;

public:
    Node(TipoGen _data, Node<TipoGen> *_next = NULL, Node<TipoGen> *_prev = NULL)
    {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

template <typename TipoGen>
class DobleLinkedList
{
    Node<TipoGen> *beginning;
    Node<TipoGen> *end;
    int size;

public:
    DobleLinkedList()
    {
        beginning = end = nullptr;
        size = 0;
    }

    //METODOS PARA AGREGAR
    void BeginningAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            _new->next = beginning;
            beginning->prev = _new;
            beginning = _new;
        }
        ++size;
        car *p;
        p = _new->data;
        ofstream pepe("car.txt", ios::app);
        pepe << p->save();
        pepe.close();
    }

    void FinalAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            end->next = _new;
            _new->prev = end;
            end = _new;
        }
        ++size;
    }

    void MiddleAddition(TipoGen v, int p)
    {
        Node<TipoGen> *aux = beginning;
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        for (size_t i = 0; i < p - 1; ++i)
        {
            aux = aux->next;
        }

        _new->next = aux->next;
        _new->prev = aux;
        aux->next->prev = _new;
        aux->next = _new;
        ++size;
    }

    //AGREGAR CARGANDO DATOS
    void LoadData()
    {
        ifstream carros("car.txt");
        string registro, tipo, modelo, precio, año, color;
        int _año;
        double _precio;

        while (getline(carros, registro))
        {
            stringstream ss(registro);
            getline(ss, modelo, ',');
            getline(ss, tipo, ',');
            getline(ss, color, ',');
            getline(ss, año, ',');
            _año = stoi(año);
            getline(ss, precio);
            _precio = stod(precio);
            car *newcar = new car(modelo, tipo, color, _año, _precio);
            FinalAddition(newcar);
        }
    }

    //ELIMINACION
    void BeginningDisposal()
    {
        Node<TipoGen> *aux = beginning;
        beginning = aux->next;
        delete aux;
        --size;
    }

    void FinalDisposal()
    {
        Node<TipoGen> *aux = end->prev;
        delete aux->next;
        aux->next = nullptr;
        end = aux;
        --size;
    }

    //Ways to get po

    car *getpo(int p)
    {
        if (p == 1)
        {
            return beginning->data;
        }
        else if (p > size)
        {
            return 0;
        }
        else
        {
            Node<TipoGen> *aux = beginning;
            int i = 0;
            while (i != p - 1)
            {
                aux = aux->next;
                i++;
            }
            return aux->data;
        }
    }

    car *getposition(int pos)
    {
        Node<TipoGen> *aux = beginning;
        int i = 0;
        while (i != pos)
        {
            aux = aux->next;
            i++;
        }
        car *obj = aux->data;
        return obj;
    }

    //ordenamientos

    void change(int p, TipoGen _data)
    {
        Node<TipoGen> *aux = beginning;
        int i = 0;
        while (i < p - 1)
        {
            aux = aux->next;
            i++;
        }
        aux->data = _data;
    }

    //Burbuja

    void BubbleSort()
    {
        car *tmp;
        for (size_t i = 1; i <= size; i++)
        {
            bool ordenado = true;
            for (size_t j = 1; j <= size - i; j++)
            {
                if (getpo(j)->getanio() > getpo(j + 1)->getanio())
                {
                    ordenado = false;
                    tmp = getpo(j);
                    change(j, getpo(j + 1));
                    change(j + 1, tmp);
                }
            }
            if (ordenado)
                break;
        }
    }

    //Intercambio
    void ExchangeSort()
    {
        car *tmp;
        for (size_t i = 1; i <= size; ++i)
        {
            for (size_t j = i + 1; j <= size; j++)
            {
                if (getpo(i)->getanio() > getpo(j)->getanio())
                {
                    tmp = getpo(i);
                    change(i, getpo(j));
                    change(j, tmp);
                }
            }
        }
    }

    void SelectionSort()
    {
        car *tmp;
        for (size_t i = 1; i <= size - 1; ++i)
        {
            int min = i;
            for (size_t j = i + 1; j <= size; ++j)
            {
                if (getpo(j)->getanio() < getpo(min)->getanio())
                {
                    min = j;
                }
            }
            if (min != i)
            {
                tmp = getpo(i);
                change(i, getpo(min));
                change(min, tmp);
            }
        }
    }

    //LAMBDA
    void lamb(function<bool(car *)> criterio)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (criterio(getposition(i)))
            {
                cout << "-----------------------" << endl;
                cout << getposition(i)->mostrarmodelo() << endl;
            }
        }
    }

    //Mostrar
    void Show()
    {
        int i = 1;
        Node<TipoGen> *aux = beginning;
        while (aux != nullptr)
        {
            car *obj = aux->data;
            cout << "-------------Caroo" << i << " -----------------" << endl;
            cout << obj->mostrar();
            ++i;
            aux = aux->next;
        }
    }
};

#endif // !__DOBLELINKEDLIST_H__
