/**
 * Project Untitled
 */


#include "cPerfumeria.h"

cPerfumeria::cPerfumeria(double _precio, string _nombre, string _marca, ePerfumeria _tipoProduct)
    :cProducto(_precio,_nombre,_marca)
{
    this->tipoProducto = _tipoProduct;
}

cPerfumeria::~cPerfumeria() {

}

ePerfumeria cPerfumeria::GET_TIPO() {
    return this->tipoProducto;
}