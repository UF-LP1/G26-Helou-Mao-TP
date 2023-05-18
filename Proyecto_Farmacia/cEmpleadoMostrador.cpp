/**
 * Project Untitled
 */
using namespace std;

#include "cEmpleadoMostrador.h"

cEmpleadoMostrador::cEmpleadoMostrador( string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual)
    :cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->numActual = numActual;
}

cEmpleadoMostrador::~cEmpleadoMostrador() {

}

void cEmpleadoMostrador::LlamarNumSiguiente(unsigned int numero) {
    //una vez que llamo al cliente, incrementa el numero de los que llama para poder llamar al otro
    this->numActual = numActual+1;
    return;
}

cCliente cEmpleadoMostrador::EnviarClienteOtroEmp() {
    
    cCliente siguiente = this->misClientes.front();//copio el primer cliente de la cola
    misClientes.pop();
    return siguiente;
    
}

void cEmpleadoMostrador::SET_NUMACTUAL(unsigned int numero)
{
    this->numActual = numero;
    return;
}

void cEmpleadoMostrador::agregarCliente(cCliente nuevoCliente)//nuevo cliente va a ser el cliente que pase el local (primero en la queue, se conecta por main)
{
    this->misClientes.push(nuevoCliente);
}
