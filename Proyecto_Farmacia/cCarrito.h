#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cPerfumeria.h"

class cCarrito {

private:
    vector<cProducto>miListaProductos;
    double descuentoMed;


public:
    cCarrito();

    cCarrito(vector<cProducto> listaProductos, double descuentoMed);
    ~cCarrito();
    void SET_LISTAPROD(vector<cProducto> listaProductosNuev);
    void SET_DESCUENTO(double descuento);
    vector<cProducto> GET_LISTAPRODUCTOS();
    double GET_DESCUENTOMED();
    void EliminarProductos(cProducto _product);
    void SET_PRODUCTO(cProducto nuevoProducto);
    void EliminarProducto(cProducto _product)
};

#endif //_CCARRITO_H