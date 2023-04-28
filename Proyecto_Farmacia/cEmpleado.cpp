/**
 * Project Untitled
 */


#include "cEmpleado.h"

cEmpleado::cEmpleado(string dni):DNI(dni)
{
    this->nombre = "";
    this->apellido = "";
    this->numeroEmpleado = 0;
    this->contacto = "";

}
cEmpleado::cEmpleado(list <cCliente>cliente, string nombre, string apellido, int numeroEmpleado,  string dni, string contacto) :DNI(dni) {
    this->cliente = cliente;
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

float cEmpleado::CalculaMontoACobrar(cProducto producto, int cantidad, float precio) {
    return 0.0;
}

cTicketdecompra cEmpleado::EmitirTicket(float precio, cProducto producto, cCliente cliente, int cantidad) {
    string aux = cliente.GET_DNI();
    cTicketdecompra  miTicket(precio, aux);
    return miTicket;
}

void cEmpleado::AgregarProductoCarrito(cProducto producto, cCarrito carrito) {
    return;
}

void cEmpleado::PasarClienteaCaja(cCliente cliente) {
    return;
}