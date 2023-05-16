/**
 * Project Untitled
 */


#include "cEmpleadosPerfumeria.h"

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string dni)
    :cVendedor::cVendedor(dni)
{

}

cEmpleadosPerfumeria::cEmpleadosPerfumeria( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
    :cVendedor( nombre, apellido, numeroEmpleado, dni, contacto)
{

}

cEmpleadosPerfumeria::~cEmpleadosPerfumeria() {

}

void cEmpleadosPerfumeria::Asesorar(cCliente cliente) {
    return;
}

void AgregarProductoCarrito(cProducto producto, cCarrito carrito)
{
    return;
}

void PasarClienteaCaja(cCliente cliente)
{
    return;
}