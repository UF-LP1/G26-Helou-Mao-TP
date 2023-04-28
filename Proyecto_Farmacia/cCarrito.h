#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cProducto.h"


class cCarrito {

private:
    list<cProducto>listaProductos;
    float precioCarrito;
    int cantidad;

public:
    cCarrito();
    cCarrito(list<cProducto> listaProductos, float _precioTotal, int _cantidad);
    ~cCarrito();
    float GET_PRECIO();
    cProducto GET_LISTAPRODUCTOS();
    void SET_PRECIOCARRITO(float _precioNuevo);
    void AgregarProductos(cProducto _product, int _cant);
    void EliminarProductos(cProducto _product, int _cant);

};

#endif //_CCARRITO_H