/**
 * Project Untitled
 */


#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(float _precio, string _nombre, int _cantidad, string _marca, eOrtopedia _tipoProduct) {

}

cOrtopedia::~cOrtopedia() {

}

eOrtopedia cOrtopedia::GET_TIPO() {
    return this->tipoProducto;
}