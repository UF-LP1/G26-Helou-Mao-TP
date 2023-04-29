/**
 * Project Untitled
 */


#include "cEmpleadosPerfumeria.h"

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
    :cEmpleado( nombre, apellido, numeroEmpleado, dni, contacto)
{

}

cEmpleadosPerfumeria::~cEmpleadosPerfumeria() {

}

void cEmpleadosPerfumeria::Asesorar(cCliente cliente) {
    return;
}

