#include "cCarrito.h"

cCarrito::cCarrito(vector<cProducto> listaProductos, double descuentomed)//constructor carrito con productos y desc ya definidos
{
    for (int i = 0; i < listaProductos.size(); i++)
    {
        this->miListaProductos.push_back(listaProductos[i]);
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

void cCarrito::SET_LISTAPROD(vector<cProducto> listaProductosNuev)//define la lista de productos o si ya hay, agrega una lista
{
    for (int i = 0; i < listaProductosNuev.size(); i++)
    {
        miListaProductos.push_back(listaProductosNuev[i]);
    }
}
void cCarrito::SET_DESCUENTO(double nuevoDes)//agrega un producto a la lista
{
    this->descuentoMed = nuevoDes;
}

cCarrito::~cCarrito() {

}

vector<cProducto> cCarrito::GET_LISTAPRODUCTOS() 
{
    return this->miListaProductos;
}

void cCarrito::EliminarProductos(cProducto _product)//elimino el producto todas las veces que aparece
{
    for (int i = 0; i < miListaProductos.size(); i++)
    {
        if (miListaProductos[i].Get_NOMBRE() == _product.Get_NOMBRE()&& miListaProductos[i].GET_MARCA() == _product.GET_MARCA())
        {
            miListaProductos.erase(miListaProductos.begin() + i);//elimuno el producto que coincide con el que estoy buscando
        }
    }
    //voy a terminar de recorrer el vector de mi carrito hasta eliminar todos los productos que coinciden
    return;
}
void cCarrito::EliminarProducto(cProducto _product)//elimino el producto una sola vez
{
    for (int i = 0; i < miListaProductos.size(); i++)
    {
        if (miListaProductos[i].Get_NOMBRE() == _product.Get_NOMBRE() && miListaProductos[i].GET_MARCA() == _product.GET_MARCA())
        {
            miListaProductos.erase(miListaProductos.begin() + i);//elimuno el producto que coincide con el que estoy buscando
            return;//al primer producto que coincide, salgo de la funcion
        }
    }
}
void cCarrito::SET_PRODUCTO(cProducto nuevoProducto)    //agrego un producto al carrito 
{
    this->miListaProductos.push_back(nuevoProducto);
    return;
}
