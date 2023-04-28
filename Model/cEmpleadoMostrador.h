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

    cEmpleadoMostrador(string nombre, string apellido, int numerEmpleado, const string DNI, string contacto, unsigned int numActual);
    ~cEmpleadoMostrador();
    cCliente GET_CLIENTE();
    void SET_NUMACTUAL(unsigned int numero);
    void LlamarNumSiguiente(unsigned int numero);
    void EnviarClienteOtroEmp(cCliente _cliente);

};

#endif //_CEMPLEADOMOSTRADOR_H