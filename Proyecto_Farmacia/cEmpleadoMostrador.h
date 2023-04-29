/**
 * Project Untitled
 */


#ifndef _CEMPLEADOMOSTRADOR_H
#define _CEMPLEADOMOSTRADOR_H

#include "cEmpleado.h"


class cEmpleadoMostrador : public cEmpleado {

private:
    unsigned int numActual;

public:
   
    cEmpleadoMostrador(cCliente** lCliente, string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual);
    ~cEmpleadoMostrador();
   
    void SET_NUMACTUAL(unsigned int numero);
    void LlamarNumSiguiente(unsigned int numero);
    void EnviarClienteOtroEmp(cCliente _cliente);

};

#endif //_CEMPLEADOMOSTRADOR_H