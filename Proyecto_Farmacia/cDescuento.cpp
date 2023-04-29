/**
 * Project Untitled
 */


#include "cDescuento.h"

cDescuento::cDescuento(double porcentaje, string obraSocial) {
    this->porcentaje = porcentaje;
    this->obraSocial = obraSocial;
}

cDescuento::~cDescuento() {

}

string cDescuento::GET_OBRASOCIAL() {
    return this->obraSocial;
}

double cDescuento::GET_PORCENTAJE() {
    return this->porcentaje;

}
