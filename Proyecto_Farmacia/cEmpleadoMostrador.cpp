/**
 * Project Untitled
 */
using namespace std;

#include "cEmpleadoMostrador.h"

cEmpleadoMostrador::cEmpleadoMostrador( string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual)
    :cVendedor(nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->numActual = numActual;
}

cEmpleadoMostrador::~cEmpleadoMostrador() {

}

void cEmpleadoMostrador::LlamarNumSiguiente(unsigned int numero) {
    //agregaria el proximo cliente a su lista de clientes (creo que el nuevo cliente lo tendria que buscar en lo cal, que local tenga una lista de los clientes que van "entrando"
    this->numActual = numActual+1;
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
