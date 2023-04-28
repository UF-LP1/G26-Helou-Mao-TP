/**
 * Project Untitled
 */


 /**
  * Project Untitled
  */


#include "cFactura.h"


cFactura::cFactura(float _monto, string _nombreCliente, string _fecha, bool _formato) {

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



