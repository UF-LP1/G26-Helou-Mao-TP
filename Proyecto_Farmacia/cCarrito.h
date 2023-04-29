#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cProducto.h"


class cCarrito {

private:
    vector<cProducto>listaProductos;
    float precioCarrito;
    int cantidad;
    float descuentoMed;

public:
    cCarrito();
    cCarrito(vector<cProducto> listaProductos, float _precioTotal, int _cantidad, float descuentoMed);
    ~cCarrito();
    float GET_PRECIO();
    vector<cProducto> GET_LISTAPRODUCTOS();
    float GET_DESCUENTOMED();
    void SET_PRECIOCARRITO(float _precioNuevo);
    void AgregarProductos(cProducto _product, int _cant);
    void EliminarProductos(cProducto _product, int _cant);

};

#endif //_CCARRITO_H