/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente(cCarrito miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, sLesion lesion, eNecesidad necesidad, string dni) :DNI(dni)
{
    this->miCarrito = miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->lesion = lesion;
    this->necesidad = necesidad;

}

cCliente::~cCliente() {

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

