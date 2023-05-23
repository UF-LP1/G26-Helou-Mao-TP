/**
 * Project Untitled
 */


 /**
  * Project Untitled
  */


#include "cFactura.h"
cFactura::cFactura()    //constructor por defecto de factura
{
    this->monto = 0;
    this->nombreCliente = "";
    this->apellidoCliente = "";
    this->formato = false;
    this->productosComprados;
}
    //constructor de factura con todos sus datos
cFactura::cFactura(double _monto, string nombreCliente, string apellidoCliente, bool _formato, list<cProducto> _productosComprados)
{   this->monto = _monto;
    this->nombreCliente = nombreCliente;
    this->apellidoCliente = apellidoCliente;
    this->formato = _formato;
    this->productosComprados = _productosComprados;

}
string cFactura::GET_APELLIDO()
{
    return this->apellidoCliente;
}
cFactura::~cFactura() {
}

bool cFactura::GET_FORMATO() {
    return this->formato;
}

void cFactura::SET_FORMATO(bool _nuevoFormato) {
    this->formato = _nuevoFormato;
    return;
}

string cFactura::GET_NOMBRE()
{
    return this->nombreCliente;
}
double cFactura::GET_MONTO()
{
    return this->monto;
}
void cFactura::SET_NOMBRECLIENTE(string _nuevoNombreCliente)
{
    this->nombreCliente = _nuevoNombreCliente;
}
void cFactura::SET_APELLIDOCLIENTE(string _nuevoApellidoCliente)
{
    this->apellidoCliente= _nuevoApellidoCliente;
}
void cFactura::SET_MONTO(double _nuevomonto)
{
    this->monto= _nuevomonto;
}

