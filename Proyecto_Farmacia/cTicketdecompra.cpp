/**
 * Project Untitled
 */


#include "cTicketdecompra.h"

cTicketdecompra::cTicketdecompra(float _precioTotal, string _dni, string nombreEmpleado, string apellidoEmpleado, int numeroEmpleado, string nombreCliente, string apellidoCliente, vector<cProducto> productosComprados)
{
    this->precioTotal=_precioTotal;
    this->DNI = _dni;
    this->nombreEmpleado = nombreEmpleado;
    this->apellidoEmpleado = apellidoEmpleado;
    this->numeroEmpleado = numeroEmpleado;
    this->nombreCliente = nombreCliente;
    this->apellidoCliente = apellidoCliente;
    this->productosComprados = productosComprados;
}


cTicketdecompra::~cTicketdecompra() {

}

float cTicketdecompra::GET_TOTAL() {
    return 0.0;
}

void cTicketdecompra::SET_TOTAL(float _nuevoTotal) {
    return;
}




