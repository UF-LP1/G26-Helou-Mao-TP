#include "cCarrito.h"

cCarrito::cCarrito()
{   
    this->precioCarrito= 0.0;
    this->cantidad = 0;

}

cCarrito::cCarrito(vector<cProducto> listaProductos, float _precioTotal, int _cantidad, float descuentomed)
{
    this->listaProductos = listaProductos;
    this->precioCarrito = _precioTotal;
    this->cantidad = _cantidad;
    this->descuentoMed = descuentomed;
}
float cCarrito::GET_DESCUENTOMED()
{
    return this->descuentoMed;
}

float cCarrito::GET_PRECIO()
{
    return this->precioCarrito;
}

cCarrito::~cCarrito() {

}

vector<cProducto> cCarrito::GET_LISTAPRODUCTOS() {
    
    return this->listaProductos;
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
