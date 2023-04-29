/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente(vector<cFactura>miFactura,cCarrito miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, eNecesidad necesidad, string dni, bool facturaFisica) :DNI(dni)
{
    this->miCarrito = miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
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

