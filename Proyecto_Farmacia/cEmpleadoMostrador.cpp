/**
 * Project Untitled
 */
using namespace std;


#include "cEmpleadoMostrador.h"


cEmpleadoMostrador::cEmpleadoMostrador(string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual)
    :cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->numActual = numActual;
}

cEmpleadoMostrador::~cEmpleadoMostrador() {

}

void cEmpleadoMostrador::LlamarNumSiguiente(unsigned int numero) {
    return;
}

void cEmpleadoMostrador::EnviarClienteOtroEmp(cCliente _cliente) {
    return;
}

void cEmpleadoMostrador::SET_NUMACTUAL(unsigned int numero)
{
    this->numActual = numero;
    return;
}
