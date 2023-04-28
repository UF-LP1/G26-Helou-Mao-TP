/**
 * Project Untitled
 */


#include "cTicketdecompra.h"

cTicketdecompra::cTicketdecompra(float _precioTotal, string _dni) {
    this->precioTotal=_precioTotal;
    this->DNI = _dni;

}

cTicketdecompra::cTicketdecompra()
{
    this->precioTotal = 0.0;
    this->DNI = "";
}

cTicketdecompra::~cTicketdecompra() {

}

float cTicketdecompra::GET_TOTAL() {
    return 0.0;
}

void cTicketdecompra::SET_TOTAL(float _nuevoTotal) {
    return;
}




