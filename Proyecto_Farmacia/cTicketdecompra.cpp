/**
 * Project Untitled
 */


#include "cTicketdecompra.h"

cTicketdecompra::cTicketdecompra(bool _compraExitosa, double _precioTotal, string _dni, string nombreEmpleado, string apellidoEmpleado, int numeroEmpleado, string nombreCliente, string apellidoCliente, vector<cProducto> productosComprados)
{
    this->compraExitosa = _compraExitosa;
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

void cTicketdecompra::SET_TOTAL(double _nuevoTotal) {
    return;
}




