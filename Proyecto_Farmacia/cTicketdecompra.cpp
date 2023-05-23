/**
 * Project Untitled
 */


#include "cTicketdecompra.h"

cTicketdecompra::cTicketdecompra(bool _compraExitosa, double _precioTotal, string _dni, string nombreEmpleado, string apellidoEmpleado, int numeroEmpleado, string nombreCliente, string apellidoCliente, list<cProducto> productosComprados)
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
cTicketdecompra::cTicketdecompra()
{
    this->compraExitosa = false;
    this->precioTotal = 0.0;
    this->DNI = "";
    this->nombreEmpleado = "";
    this->apellidoEmpleado = "";
    this->numeroEmpleado = 0;
    this->nombreCliente = "";
    this->apellidoCliente = "";

}
bool cTicketdecompra::GET_COMPRA()
{
    return this->compraExitosa;

}

list<cProducto> cTicketdecompra::GET_LISTAPRO()
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
    this->precioTotal = _nuevoTotal;
    return;
}
string cTicketdecompra::GET_NOMBREEMP()
{
    return this->nombreEmpleado;
}
string cTicketdecompra::GET_NOMBRCLIEN()
{    return this->nombreCliente;
}


