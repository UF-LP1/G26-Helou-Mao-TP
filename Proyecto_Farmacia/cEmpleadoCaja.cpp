/**
 * Project Untitled
 */


#include "cEmpleadoCaja.h"

cEmpleadoCaja::cEmpleadoCaja(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cEmpleadoCaja::cEmpleadoCaja(list <cCliente>cliente, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
:cEmpleado(cliente,nombre, apellido, numeroEmpleado, dni, contacto)
    {
    }

cEmpleadoCaja::~cEmpleadoCaja() {

}



void cEmpleadoCaja::Cobrar(float precioTotal) {
    return;
}

cTicketdecompra cEmpleadoCaja::AgregarTicketCaja(cCarrito carrito, cCliente cliente) {
    cTicketdecompra nuevoTicket(carrito.GET_PRECIO(), cliente.GET_DNI());
    return nuevoTicket;
}