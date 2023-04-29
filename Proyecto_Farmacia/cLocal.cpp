/**
 * Project Untitled
 */


#include "cLocal.h"

cLocal::cLocal(string _nombre, string _direccion, string _contacto, double _fondos) {
    this->nombre = _nombre;
    this->direccion = _direccion;
    this->contacto = _contacto;
    this->fondos = _fondos;
}

cLocal::~cLocal() {

}

void cLocal::AgregarTicketCompra(cTicketdecompra _ticketNuevo) {
    return;
}

