/**
 * Project Untitled
 */


#include "cEmpleado.h"


cEmpleado::cEmpleado(string dni):DNI(dni)
{
    this->lClientes = nullptr;
    this->nombre = "";
    this->apellido = "";
    this->numeroEmpleado = 0;
    this->contacto = "";

}
cEmpleado::cEmpleado(cCliente** lCliente, string nombre, string apellido, int numeroEmpleado,  string dni, string contacto) :DNI(dni) {
    this->lClientes = lCliente;
    this->nombre = nombre;
    this->apellido = apellido;
    this->numeroEmpleado = numeroEmpleado;
    this->contacto = contacto;
}

cEmpleado::~cEmpleado() {

}
void cEmpleado::AtenderCliente(cCliente cliente) {
    return;
}

void cEmpleado::AgregarProductoCarrito(cProducto producto, cCarrito carrito) {
    return;
}

void cEmpleado::PasarClienteaCaja(cCliente cliente) {
    return;
}