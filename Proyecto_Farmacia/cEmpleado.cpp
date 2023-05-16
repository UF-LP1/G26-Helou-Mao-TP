/**
 * Project Untitled
 */


#include "cEmpleado.h"


cEmpleado::cEmpleado(string dni):DNI(dni)
{
  
    this->nombre = "";
    this->apellido = "";
    this->numeroEmpleado = 0;
    this->contacto = "";

}
cEmpleado::cEmpleado( string nombre, string apellido, int numeroEmpleado,  string dni, string contacto) :DNI(dni) {

    this->nombre = nombre;
    this->apellido = apellido;
    this->numeroEmpleado = numeroEmpleado;
    this->contacto = contacto;
}

cEmpleado::~cEmpleado() {

}
