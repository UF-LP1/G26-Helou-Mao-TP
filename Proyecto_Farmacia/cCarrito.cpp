#include "cCarrito.h"

cCarrito::cCarrito()
{
    this->precioCarrito= 0.0;
    this->cantidad = 0;

}

cCarrito::cCarrito(list<cProducto> listaProductos, float _precioTotal, int _cantidad)
{
    this->listaProductos = listaProductos;
    this->precioCarrito = _precioTotal;
    this->cantidad = _cantidad;
}

float cCarrito::GET_PRECIO()
{
    return this->precioCarrito;
}

cCarrito::~cCarrito() {

}

cProducto cCarrito::GET_LISTAPRODUCTOS() {
    cProducto miProducto;
    return miProducto;
}

void cCarrito::SET_PRECIOCARRITO(float _precioNuevo) {
    return;
}

void cCarrito::AgregarProductos(cProducto _product, int _cant) {
    return;
}


void cCarrito::EliminarProductos(cProducto _product, int _cant) {
    return;
}
