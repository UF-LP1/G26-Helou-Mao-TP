/**
 * Project Untitled
 */


#include "cEmpleado.h"

cEmpleado::cEmpleado(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto) {

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
    return;
}

void cEmpleado::AgregarProductoCarrito(cProducto producto, cCarrito carrito) {
    return;
}

void cEmpleado::PasarClienteaCaja(cCliente cliente) {
    return;
}