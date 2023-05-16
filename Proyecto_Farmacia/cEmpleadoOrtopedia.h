/**
 * Project Untitled
 */


#ifndef _CEMPLEADOORTOPEDIA_H
#define _CEMPLEADOORTOPEDIA_H

#include "cVendedor.h"


class cEmpleadoOrtopedia : public cVendedor {

public:
    cEmpleadoOrtopedia(string dni);
    cEmpleadoOrtopedia( string nombre, string apellido, int numerEmpleado, const string dni, string contacto);
    ~cEmpleadoOrtopedia();
    void Asesorar(cCliente cliente);
    void RecomendarProductos(cCliente cliente);
    void AgregarProductoCarrito(cProducto producto, cCarrito& carrito);
};

#endif //_CEMPLEADOORTOPEDIA_H