#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cPerfumeria.h"

class cCarrito {

private:
    list<cProducto>miListaProductos;
    double descuentoMed;


public:
    cCarrito();

    cCarrito(list<cProducto> listaProductos, double descuentoMed);
    ~cCarrito();
    void SET_LISTAPROD(list<cProducto> listaProductosNuev);
    void SET_DESCUENTO(double descuento);
    list<cProducto> GET_LISTAPRODUCTOS();
    double GET_DESCUENTOMED();
    void EliminarProductos( int pos);
    void SET_PRODUCTO(cProducto *nuevoProducto);

};

#endif //_CCARRITO_H