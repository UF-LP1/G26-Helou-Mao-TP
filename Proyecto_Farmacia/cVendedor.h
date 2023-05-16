#pragma once
#include "cEmpleado.h"
class cVendedor: public cEmpleado{

public:
    cVendedor(string dni);
    cVendedor(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cVendedor();
    virtual void AtenderCliente(cCliente cliente) = 0;
    virtual void AgregarProductoCarrito(cProducto producto, cCarrito carrito)=0;
    virtual void PasarClienteaCaja(cCliente cliente)=0;

};