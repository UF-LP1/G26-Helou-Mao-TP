/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente( cFactura _miFactura, cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago,double saldoDisponible, double efectivoDisponible, eNecesidad necesidad, string dni, bool facturaFisica) :DNI(dni)
{
    this->miFactura = _miFactura;
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->efectivodisponible = efectivoDisponible;
    this->necesidad = necesidad;
    this->facturaFisica = facturaFisica;

}

cCliente::~cCliente() {

}
bool cCliente:: GET_FORMATO()
{
    return this->facturaFisica;
}
string cCliente::GET_DNI() {
    return this->DNI;
}
eMetodo cCliente::GET_METODO()
{
    return this->metodoPago;
}

cCarrito cCliente::GET_CARRITO() {
    
    return this->miCarrito;
}

void cCliente::AgregarProductosPerfumeria(cProducto prodPerfumeria, int cantidad) {
    return;
}

void cCliente::AgregarGolosinas(cProducto golosinas, int cantidad) {
    return;
}
string cCliente::GET_NOMBRE()
{
    return this->nombre;
}
string cCliente::GET_APELLIDO()
{
    return this->apellido;
}
void cCliente::SET_FACTURA(cFactura nuevaFactura)
{
    this->miFactura= nuevaFactura;
}
float cCliente::GET_SALDO_DISPONIBLE()
{
    return this->saldoDisponible;
}
float cCliente::GET_EFECTIVO_DISPONIBLE()
{
    return this->efectivodisponible;
}
float cCliente::GET_SALDO_MP()
{
    return this->saldoMPago;
}