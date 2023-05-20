/**
 * Project Untitled
 */


#include "cMedicamento.h"

cMedicamento::cMedicamento(double _precio, string _nombre, string _marca, int _dosis, bool _ventaLibre)
	:cProducto(_precio,_nombre,_marca)
{
	this->dosis = _dosis;
	this->ventaLibre = _ventaLibre;
}
cMedicamento::~cMedicamento() {

}
bool cMedicamento::GET_VENTA_LIBRE()
{
	return this->ventaLibre;
}