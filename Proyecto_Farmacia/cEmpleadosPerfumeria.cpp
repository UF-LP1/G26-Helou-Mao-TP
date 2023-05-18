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
void cEmpleadosPerfumeria::AgregarProductoCarrito(cPerfumeria producto)
{
    int aux = misClientes.size();
    misClientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS().push_back(producto);
}

