#include "cCarrito.h"

cCarrito::cCarrito(vector<cProducto> listaProductos, double descuentomed)
{
    this->listaProductos = listaProductos;
    this->descuentoMed = descuentomed;
}
double cCarrito::GET_DESCUENTOMED()
{
    return this->descuentoMed;
}
void cCarrito::SET_LISTAPROD(vector<cProducto> listaProductosNuev)
{
    this->listaProductos = listaProductosNuev;
}
void cCarrito::SET_DESCUENTO(double nuevoDes)
{

}

cCarrito::~cCarrito() {

}

vector<cProducto> cCarrito::GET_LISTAPRODUCTOS() {
    
    return this->listaProductos;
}

 

void cCarrito::AgregarProductos(cProducto _product) {
    return;
}


void cCarrito::EliminarProductos(cProducto _product) {
    return;
}
