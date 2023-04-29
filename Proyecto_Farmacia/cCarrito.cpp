#include "cCarrito.h"

cCarrito::cCarrito(vector<cProducto> listaProductos, float descuentomed)
{
    this->listaProductos = listaProductos;
    this->descuentoMed = descuentomed;
}
float cCarrito::GET_DESCUENTOMED()
{
    return this->descuentoMed;
}
void cCarrito::SET_LISTAPROD(vector<cProducto> listaProductosNuev)
{
    this->listaProductos = listaProductosNuev;
}
void cCarrito::SET_DESCUENTO(float nuevoDes)
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
