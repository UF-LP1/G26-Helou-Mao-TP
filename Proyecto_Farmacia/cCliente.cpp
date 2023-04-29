/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente( cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago,float saldoDisponible, float efectivoDisponible, eNecesidad necesidad, string dni, bool facturaFisica) :DNI(dni)
{
  
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
string cCliente::GET_APELLIDO()
{

}
string cCliente::GET_NOMBRE()
{

}
float cCliente::GET_SALDO_DISPONIBLE()
{

}
float cCliente::GET_EFECTIVO_DISPONIBLE()
{

}
float cCliente::GET_SALDO_MP()
{

}