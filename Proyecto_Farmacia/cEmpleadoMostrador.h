/**
 * Project Untitled
 */


#ifndef _CEMPLEADOMOSTRADOR_H
#define _CEMPLEADOMOSTRADOR_H

#include "cVendedor.h"


class cEmpleadoMostrador : public cVendedor {

private:
    unsigned int numActual;

public:
   
    cEmpleadoMostrador( string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual);
    ~cEmpleadoMostrador();
  
    void SET_NUMACTUAL(unsigned int numero);
    void LlamarNumSiguiente(unsigned int numero);
    void EnviarClienteOtroEmp(cCliente _cliente);

};

#endif //_CEMPLEADOMOSTRADOR_H