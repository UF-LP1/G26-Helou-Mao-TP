/**
 * Project Untitled
 */


#include "cFarmaceutico.h"


cFarmaceutico::cFarmaceutico(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto) {

}

cFarmaceutico::~cFarmaceutico() {

}

cDescuento cFarmaceutico::GET_LISTADESCUENTOS() {
    return null;
}

cReceta cFarmaceutico::GET_RECETA() {
    return null;
}

cProducto cFarmaceutico::GET_MEDICAMENTO() {
    return null;
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

