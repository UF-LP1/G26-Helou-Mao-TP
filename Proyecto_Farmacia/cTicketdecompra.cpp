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
bool cTicketdecompra::GET_COMPRA()
{
    return this->compraExitosa;

}

vector<cProducto> cTicketdecompra::GET_LISTAPRO()
{
    return this->productosComprados;
}

cTicketdecompra::~cTicketdecompra() {

}

double cTicketdecompra::GET_PRECIOFINAL()
{
    return this->precioTotal;
}

void cTicketdecompra::SET_TOTAL(double _nuevoTotal) {
    return;
}




