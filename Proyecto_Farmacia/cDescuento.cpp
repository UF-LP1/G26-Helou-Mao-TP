/**
 * Project Untitled
 */


#include "cDescuento.h"

cDescuento::cDescuento(float porcentaje, string obraSocial) {
    this->porcentaje = porcentaje;
    this->obraSocial = obraSocial;
}

cDescuento::~cDescuento() {

}

string cDescuento::GET_OBRASOCIAL() {
    return this->obraSocial;
}

float cDescuento::GET_PORCENTAJE() {
    return this->porcentaje;

}
