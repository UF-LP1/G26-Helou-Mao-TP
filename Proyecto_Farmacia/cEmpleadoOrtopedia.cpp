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

void cEmpleadoOrtopedia::Asesorar() {

    return;
}

void cEmpleadoOrtopedia::AgregarProductoCarrito(cOrtopedia producto)
{
    int aux = misClientes.size();
    misClientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS().push_back (producto);
     
}
void cEmpleadoOrtopedia::RecomendarProductos()
{
    return;
}