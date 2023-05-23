/**
 * Project Untitled
 */


#include "cGolosinas.h"

cGolosinas::cGolosinas(double _precio, string _nombre, string _marca, eGolosinas _tipoGolosinas)
	:cProducto(_precio, _nombre,_marca)
{
	this->tipoGolosina = _tipoGolosinas;
}

cGolosinas::~cGolosinas() {

}
eGolosinas cGolosinas::GET_TIPO()
{
	return this->tipoGolosina;
}