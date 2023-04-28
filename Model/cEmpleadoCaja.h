/**
 * Project Untitled
 */


#ifndef _CEMPLEADOCAJA_H
#define _CEMPLEADOCAJA_H

#include "cEmpleado.h"


class cEmpleadoCaja: public cEmpleado {
public: 
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 */
void cEmpleadoCaja(void string, void string, void int, void const string, void string);
    
eMetodo GET_METODOPAGO();
    
eFormato GET_FORMATO();
    
cCarrito GET_CARRITO();
    
/**
 * @param float
 */
void Cobrar(void float );
    
/**
 * @param cCarritoExtras
 * @param cCliente
 */
cTicketdecompra AgregarTicketCaja(void cCarritoExtras, void cCliente);
protected: 
    
void cEmpleadoCaja();
};

#endif //_CEMPLEADOCAJA_H