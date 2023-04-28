/**
 * Project Untitled
 */


#ifndef _CEMPLEADOCAJA_H
#define _CEMPLEADOCAJA_H

#include "cEmpleado.h"
#include "eMetodo.h"


class cEmpleadoCaja : public cEmpleado {
public:
    cEmpleadoCaja(string dni);
    cEmpleadoCaja(list <cCliente>cliente, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cEmpleadoCaja();
   
    void Cobrar(float precioTotal);
    cTicketdecompra AgregarTicketCaja(cCarrito carrito, cCliente cliente);

};

#endif //_CEMPLEADOCAJA_H