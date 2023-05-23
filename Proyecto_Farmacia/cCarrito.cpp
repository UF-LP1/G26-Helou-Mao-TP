#include "cCarrito.h"

cCarrito::cCarrito(list<cProducto> listaProductos, double descuentomed)//constructor carrito con productos y desc ya definidos
{
    for (list<cProducto>::iterator it=listaProductos.begin(); it!= listaProductos.end(); it++)  //recorro la lisa de prods y voy copiando uno a uno
    {
        this->miListaProductos.push_back(*it);
    }
    this->descuentoMed = descuentomed;
}
cCarrito::cCarrito()//constructor por defecto (sin productos ni descuento)
{
    this->descuentoMed = 0;
}
double cCarrito::GET_DESCUENTOMED()
{
    return this->descuentoMed;
}

void cCarrito::SET_LISTAPROD(list<cProducto> listaProductosNuev)//define la lista de productos o si ya hay, agrega una lista
{
    for (list<cProducto>::iterator it = listaProductosNuev.begin(); it != listaProductosNuev.end(); it++)
    {
        miListaProductos.push_back(*it);
    }
}
void cCarrito::SET_DESCUENTO(double nuevoDes)//agrega un producto a la lista
{
    this->descuentoMed = nuevoDes;
}

cCarrito::~cCarrito() {

}

list<cProducto> cCarrito::GET_LISTAPRODUCTOS() 
{
    return this->miListaProductos;
}

void cCarrito::EliminarProductos(int pos)//elimino el producto todas las veces que aparece
{
    int cont = 1;
    for (list<cProducto>::iterator it = miListaProductos.begin(); it != miListaProductos.end(); it++)
    {
   
        if (cont==pos)
        {
            miListaProductos.erase(it);//elimino el producto que coincide con el que estoy buscando
            return;
        }
        cont++;
    }
    //voy a terminar de recorrer el vector de mi carrito hasta eliminar todos los productos que coinciden
    return;
}

void cCarrito::SET_PRODUCTO(cProducto *nuevoProducto)    //agrego un producto al carrito 
{
    this->miListaProductos.push_back(*nuevoProducto);
    return;
}
