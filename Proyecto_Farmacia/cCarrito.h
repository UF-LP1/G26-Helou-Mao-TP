#ifndef _CCARRITO_H
#define _CCARRITO_H
#include "cProducto.h"


class cCarrito {

private:
    vector<cProducto>listaProductos;
    int cantidad;
    float descuentoMed;

public:
    cCarrito();
    cCarrito(vector<cProducto> listaProductos, int _cantidad, float descuentoMed);
    ~cCarrito();
    vector<cProducto> GET_LISTAPRODUCTOS();
    float GET_DESCUENTOMED();
    void AgregarProductos(cProducto _product, int _cant);
    void EliminarProductos(cProducto _product, int _cant);

};

#endif //_CCARRITO_H