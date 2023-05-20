/**
 * Project Untitled
 */


#include "cOrtopedia.h"

cOrtopedia::cOrtopedia(double _precio, string _nombre, string _marca, eOrtopedia _tipoProduct)
    :cProducto(_precio, _nombre,_marca)
{
    this->tipoProducto = _tipoProduct;
}

cOrtopedia::~cOrtopedia() {

}

eOrtopedia cOrtopedia::GET_TIPO() {
    return this->tipoProducto;
}
