/**
 * Project Untitled
 */


#include "cCliente.h"


cCarrito::cCarrito()
{
    this->listaProductos;
    this->precioCarrito = 0.0;
    this->cantidad = 0;
    this->descuentoMed = 0.0;

}
cCliente::cCliente(vector<cFactura>miFactura,cCarrito miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago,float saldoDisponible, float efectivoDisponible, eNecesidad necesidad, string dni, bool facturaFisica) :DNI(dni)
{
    this->miCarrito = miCarrito;
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

cCarrito cCliente::GET_CARRITO() {
    
    return this->miCarrito;
}

void cCliente::AgregarProductosPerfumeria(cProducto prodPerfumeria, int cantidad) {
    return;
}

void cCliente::AgregarGolosinas(cProducto golosinas, int cantidad) {
    return;
}

