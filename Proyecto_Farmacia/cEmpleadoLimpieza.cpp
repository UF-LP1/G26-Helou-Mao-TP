/**
 * Project Untitled
 */


#include "cEmpleadoLimpieza.h"

cEmpleadoLimpieza::cEmpleadoLimpieza(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto, int turno) {

}

cEmpleadoLimpieza::~cEmpleadoLimpieza() {

}
void cEmpleadoLimpieza::SET_TURNO(int _turnoNuevo) {
    this->turno = _turnoNuevo;
    return;
}

int cEmpleadoLimpieza::GET_TURNO() {
    return this->turno;
}
