/**
 * Project Untitled
 */


#ifndef _CEMPLEADOMOSTRADOR_H
#define _CEMPLEADOMOSTRADOR_H

#include "cEmpleadoLimpieza.h"


class cEmpleadoMostrador : public cEmpleado {

private:
    unsigned int numActual;
    queue<cCliente> misClientes;

public:
   
    cEmpleadoMostrador(string nombre, string apellido, int numerEmpleado, const string dni, string contacto, unsigned int numActual);
    ~cEmpleadoMostrador();
  
    void SET_NUMACTUAL(unsigned int numero);
    void LlamarNumSiguiente(unsigned int numero);
    cCliente EnviarClienteOtroEmp();
    void agregarCliente(cCliente *nuevoCliente);
    int aDondeVaCliente();

};

#endif //_CEMPLEADOMOSTRADOR_H