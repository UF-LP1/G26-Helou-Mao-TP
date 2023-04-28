/**
 * Project Untitled
 */
#include "cProducto.h"

cProducto::cProducto()
{   
    this->precio = 0.0;
    this->nombre = "";
    this->cantidad = 0;
    this->marca = "";
}

cProducto::cProducto(float _precio, string _nombre, int _cantidad, string marca) 
{
    this->precio= _precio;
    this->nombre= _nombre;
    this->cantidad= _cantidad;
    this->marca = marca;
}

cProducto::~cProducto() {

}

float cProducto::Get_PRECIO() {
    return this->precio;
}

string cProducto::Get_NOMBRE() {
    return this->nombre;
}

