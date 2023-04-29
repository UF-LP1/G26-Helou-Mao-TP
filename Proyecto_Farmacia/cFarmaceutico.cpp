/**
 * Project Untitled
 */


#include "cFarmaceutico.h"

cFarmaceutico::cFarmaceutico(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cFarmaceutico::cFarmaceutico( vector<cDescuento>descuent,string nombre, string apellido, int numeroEmpleado, const string dni, string contacto)
    :cEmpleado( nombre, apellido, numeroEmpleado, dni, contacto)
{

}

cFarmaceutico::~cFarmaceutico() {

}

vector<cDescuento> cFarmaceutico::GET_DESCUENTO() {
    return this->descuento;
}




void cFarmaceutico::ExplicarDosificacion(cReceta _objetoRec, cProducto _objProducto) {
    return;
}

void cFarmaceutico::RecomendarRemedios(cCliente miCliente) {
    return;
}

void cFarmaceutico::ExpenderReceta(cReceta miReceta) {
    return;
}

float cFarmaceutico::ChequearDescuentos(cReceta _objetoReceta, cDescuento _objetoDescuento) {
    return 0.0;
}

