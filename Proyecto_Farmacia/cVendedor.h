#pragma once
#include "cEmpleado.h"

class cVendedor: public cEmpleado{
protected:
    vector<cCliente> misClientes;

public:
    cVendedor(string dni);
    cVendedor(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cVendedor();
    virtual void AtenderCliente(cCliente cliente) ;
    //virtual void AgregarProductoCarrito(cProducto producto) = 0;
   cCliente PasarClienteaCaja();

};