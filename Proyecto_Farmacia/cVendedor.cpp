#include "cVendedor.h"

cVendedor::cVendedor(string dni)
    :cEmpleado::cEmpleado(dni)
{
}

cVendedor::cVendedor(string nombre, string apellido, int numeroEmpleado, string dni, string contacto)
    :cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
{
}

cVendedor::~cVendedor() {

}
void cVendedor::AtenderCliente(cCliente cliente) { return; }
void cVendedor::AgregarProductoCarrito(cProducto producto, cCarrito carrito) { return; }
void cVendedor::PasarClienteaCaja(cCliente cliente) {
    return;
}