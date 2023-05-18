#pragma once
#include "cEmpleado.h"
#include "cPerfumeria.h"
class cVendedor: public cEmpleado{
    vector<cCliente> misClientes;

public:
    cVendedor(string dni);
    cVendedor(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cVendedor();
    void AtenderCliente(cCliente &cliente) ;
    virtual void AgregarProductoCarrito(cProducto producto, cCarrito &carrito)=0;
    void PasarClienteaCaja(cCliente& cliente);

};