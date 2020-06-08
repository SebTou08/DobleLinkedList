#ifndef __CAR_H__
#define _CAR_H__

#include <iostream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
#include <functional>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
string modelos[10] = {"Toyota", "Nisan", "Mazda", "BMW", "Mercedenz", "Hiunday", "Ford", "Jeep", "Rnage-Rovers", "Ciantro"};
string tipos[2] = {"Automatico", "Mecanico"};
string colores[10] = {"Rojo", "Azul", "Amarillo", "Anaranjado", "Rosa", "Verde", "Negro", "Blanco", "Morado", "Cian"};

class car
{
private:
    string modelo;
    string tipo;
    double precio;
    int año;
    string color;

public:
    car()
    {
        modelo = modelos[rand() % 10];
        tipo = tipos[rand() % 2];
        color = colores[rand() % 10];
        precio = rand() % 50000 + 15000.45896;
        año = rand() % 30 + 1990;
    }
    car(string _modelo, string _tipo, string _color, int _año, double _precio)
    {
        modelo = _modelo;
        tipo = _tipo;
        color = _color;
        año = _año;
        precio = _precio;
    }

    int getanio() { return año; }
    double getprecio() { return precio; }
    string mostrarmodelo() { return "Modelo: " + modelo; }

    string mostrar() { return "\n \t Modelo: " + modelo + "'\n \t Color: " + color + "\n \t Precio: " + to_string(precio) + "\n\t Anio: " + to_string(año) + '\n'; }
    string save() { return "\n" + modelo + ',' + tipo + ',' + color + ',' + to_string(año) + ',' + to_string(precio); }
};

#endif // !__CAR_H__