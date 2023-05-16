#pragma once
#include "cEmpleado.h"
class cVendedor: public cEmpleado{
    vector<cCliente*> misClientes;

public:
    cVendedor(string dni);
    cVendedor(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cVendedor();
    void AtenderCliente(cCliente &cliente) ;
    void AgregarProductoCarrito(cProducto producto, cCarrito &carrito);
    void PasarClienteaCaja(cCliente& cliente);

};