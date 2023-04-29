/**
 * Project Untitled
 */


#include "cEmpleadosPerfumeria.h"

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cEmpleadosPerfumeria::cEmpleadosPerfumeria(cCliente** lCliente, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
    :cEmpleado( lCliente,nombre, apellido, numeroEmpleado, dni, contacto)
{

}

cEmpleadosPerfumeria::~cEmpleadosPerfumeria() {

}

void cEmpleadosPerfumeria::Asesorar(cCliente cliente) {
    return;
}

