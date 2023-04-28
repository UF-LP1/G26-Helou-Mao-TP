/**
 * Project Untitled
 */


#ifndef _CEMPLEADOMOSTRADOR_H
#define _CEMPLEADOMOSTRADOR_H

#include "cEmpleado.h"


class cEmpleadoMostrador: public cEmpleado {
public: 
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 * @param unsigned int
 */
void cEmpleadoMostrador(void string, void string, void int, void const string, void string, void unsigned int);
    
cCliente GET_CLIENTE();
    
/**
 * @param unsigned int
 */
void SET_NUMACTUAL(void unsigned int);
    
/**
 * @param unsigned int
 */
void LlamarNumSiguiente(void unsigned int);
    
/**
 * @param cCliente
 */
void EnviarClienteOtroEmp(void cCliente);
protected: 
    
void cEmpleadoMostrador();
private: 
    unsigned int numActual;
};

#endif //_CEMPLEADOMOSTRADOR_H