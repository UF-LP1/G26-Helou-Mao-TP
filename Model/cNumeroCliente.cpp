/**
 * Project Untitled
 */


#include "cNumeroCliente.h"


cNumeroCliente::cNumeroCliente(int _numeroActual) {

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

