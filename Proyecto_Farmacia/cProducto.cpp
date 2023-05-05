/**
 * Project Untitled
 */
#include "cProducto.h"

cProducto::cProducto()
{   
    this->precio = 0.0;
    this->nombre = "";
    this->marca = "";
}

cProducto::cProducto(double _precio, string _nombre, string marca) 
{
    this->precio= _precio;
    this->nombre= _nombre;
    this->marca = marca;
}

cProducto::~cProducto() {

}
string cProducto::GET_MARCA()
{
    return this->marca;
}
double cProducto::Get_PRECIO() {
    return this->precio;
}

string cProducto::Get_NOMBRE() {
    return this->nombre;
}

