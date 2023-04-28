/**
 * Project Untitled
 */


#include "cEmpleadosPerfumeria.h"

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cEmpleadosPerfumeria::cEmpleadosPerfumeria(list <cCliente>cliente, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
    :cEmpleado(cliente, nombre, apellido, numeroEmpleado, dni, contacto)
{

}

cEmpleadosPerfumeria::~cEmpleadosPerfumeria() {

}

void cEmpleadosPerfumeria::Asesorar(cCliente cliente) {
    return;
}

