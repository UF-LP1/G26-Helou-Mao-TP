/**
 * Project Untitled
 */


#include "cEmpleadoLimpieza.h"

cEmpleadoLimpieza::cEmpleadoLimpieza(string nombre, string apellido, int numeroEmpleado, string dni, string contacto, int turno)
    :cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
    {
        this -> turno = turno;
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
