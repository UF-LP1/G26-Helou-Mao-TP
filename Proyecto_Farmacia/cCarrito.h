#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cProducto.h"


class cCarrito {

private:
    vector<cProducto>listaProductos;

    float descuentoMed;

public:
    cCarrito();
    cCarrito(vector<cProducto> listaProductos, float descuentoMed);
    ~cCarrito();
    void SET_LISTAPROD(vector<cProducto> listaProductosNuev);
    void SET_DESCUENTO(float descuento);
    vector<cProducto> GET_LISTAPRODUCTOS();
    float GET_DESCUENTOMED();
    void AgregarProductos(cProducto _product);
    void EliminarProductos(cProducto _product);

};

#endif //_CCARRITO_H