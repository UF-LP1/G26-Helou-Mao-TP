/**
 * Project Untitled
 */


 /**
  * Project Untitled
  */


#include "cFactura.h"
cFactura::cFactura()
{
    this->monto = 0;
    this->nombreCliente = "";
    this->apellidoCliente = "";
    this->formato = false;
    this->productosComprados;
}

cFactura::cFactura(double _monto, string nombreCliente, string apellidoCliente, bool _formato, vector<cProducto> _productosComprados)
{   this->monto = _monto;
    this->nombreCliente = nombreCliente;
    this->apellidoCliente = apellidoCliente;
    this->formato = _formato;
    this->productosComprados = _productosComprados;

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



