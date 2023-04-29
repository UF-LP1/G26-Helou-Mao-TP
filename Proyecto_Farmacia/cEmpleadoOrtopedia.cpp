/**
 * Project Untitled
 */


#include "cEmpleadoOrtopedia.h"

cEmpleadoOrtopedia::cEmpleadoOrtopedia(string dni)
    :cEmpleado::cEmpleado(dni)
{

}
    

cEmpleadoOrtopedia::cEmpleadoOrtopedia(cCliente** lCliente, string nombre, string apellido, int numerEmpleado, const string dni, string contacto)
    :cEmpleado(lCliente,nombre, apellido, numerEmpleado, dni, contacto)
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

