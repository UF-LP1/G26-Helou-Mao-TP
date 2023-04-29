/**
 * Project Untitled
 */


#include "cReceta.h"


cReceta::cReceta(string _obraSoc, string _medicamento, int _dosis) {

}

cReceta::~cReceta() {

}

int cReceta::GET_DOSIS() {
    return this->Dosis;
}

string cReceta::GET_MEDICAMENTO() {
    return this->Medicamento;
}

string cReceta::GET_OBRASOCIAL() {
    return this->ObraSocial;
}

