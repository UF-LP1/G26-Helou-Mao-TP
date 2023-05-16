/**
 * Project Untitled
 */


#include "cEmpleadoOrtopedia.h"

cEmpleadoOrtopedia::cEmpleadoOrtopedia(string dni)
    :cVendedor::cVendedor(dni)
{

}
    

cEmpleadoOrtopedia::cEmpleadoOrtopedia( string nombre, string apellido, int numerEmpleado, const string dni, string contacto)
    :cVendedor(nombre, apellido, numerEmpleado, dni, contacto)
{

}

cEmpleadoOrtopedia::~cEmpleadoOrtopedia() {

}

void cEmpleadoOrtopedia::Asesorar(cCliente cliente) {
    return;
}

void cEmpleadoOrtopedia::RecomendarProductos(cCliente cliente) {
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