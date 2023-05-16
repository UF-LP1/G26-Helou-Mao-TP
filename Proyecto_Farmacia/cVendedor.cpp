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
