/**
 * Project Untitled
 */


#include "cPerfumeria.h"

cPerfumeria::cPerfumeria(float _precio, string _nombre, int _cantidad, string _marca, ePerfumeria _tipoProduct) {

}

cPerfumeria::~cPerfumeria() {

}

ePerfumeria cPerfumeria::GET_TIPO() {
    return this->tipoProducto;
}