/**
 * Project Untitled
 */


#include "cNumeroCliente.h"
//yo sacaria esta clase y haria numero acrual como un static en la clase cliente


cNumeroCliente::cNumeroCliente(int _numeroActual) {
    this->numero = _numeroActual;

}

cNumeroCliente::~cNumeroCliente() {

}

int cNumeroCliente::GET_NUMERO() {
    return this->numero;
}

void cNumeroCliente::SET_NUMERO(int _numeroNuevo) {
    this->numero = _numeroNuevo;
    return;
}

