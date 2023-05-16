#include "cCarrito.h"

cCarrito::cCarrito(vector<cProducto> listaProductos, double descuentomed)
{
    for (int i = 0; i < listaProductos.size(); i++)
    {
        this->miListaProductos.push_back(listaProductos[i]);
    }
    this->descuentoMed = descuentomed;
}
cCarrito::cCarrito()
{
    this->descuentoMed = 0;
}
double cCarrito::GET_DESCUENTOMED()
{
    return this->descuentoMed;
}
void cCarrito::SET_LISTAPROD(vector<cProducto> listaProductosNuev)
{
    for (int i = 0; i < listaProductosNuev.size(); i++)
    {
        miListaProductos.push_back(listaProductosNuev[i]);
    }
}
void cCarrito::SET_DESCUENTO(double nuevoDes)
{
    this->descuentoMed = nuevoDes;
}

cCarrito::~cCarrito() {

}

vector<cProducto> cCarrito::GET_LISTAPRODUCTOS() {
    
    return this->miListaProductos;
}

void cCarrito::EliminarProductos(cProducto _product) {
    return;
}
void cCarrito::SET_PRODUCTO(cProducto nuevoProducto)    //agrego productos al carrito 
{
    this->miListaProductos.push_back(nuevoProducto);
    return;
}
