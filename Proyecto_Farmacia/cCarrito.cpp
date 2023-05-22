#include "cCarrito.h"

cCarrito::cCarrito(list<cProducto> listaProductos, double descuentomed)//constructor carrito con productos y desc ya definidos
{
    for (list<cProducto>::iterator it=listaProductos.begin(); it!= listaProductos.end(); it++)
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

void cCarrito::EliminarProductos(cProducto *_product)//elimino el producto todas las veces que aparece
{
    for (list<cProducto>::iterator it = miListaProductos.begin(); it != miListaProductos.end(); it++)
    {
        if (it->Get_NOMBRE() == _product->Get_NOMBRE()&& it->GET_MARCA() == _product->GET_MARCA())
        {
            miListaProductos.erase(it);//elimuno el producto que coincide con el que estoy buscando
        }
    }
    //voy a terminar de recorrer el vector de mi carrito hasta eliminar todos los productos que coinciden
    return;
}
void cCarrito::EliminarProducto(cProducto _product)//elimino el producto una sola vez
{
    for (list<cProducto>::iterator it = miListaProductos.begin(); it != miListaProductos.end(); it++)
    {
        if (it->Get_NOMBRE() == _product.Get_NOMBRE() && it->GET_MARCA() == _product.GET_MARCA())
        {
            miListaProductos.erase(it);//elimuno el producto que coincide con el que estoy buscando
            return;//al primer producto que coincide, salgo de la funcion
        }
    }
}
void cCarrito::SET_PRODUCTO(cProducto *nuevoProducto)    //agrego un producto al carrito 
{
    this->miListaProductos.push_back(*nuevoProducto);
    return;
}
