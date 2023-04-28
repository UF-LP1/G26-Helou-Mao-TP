/**
 * Project Untitled
 */


#ifndef _CEMPLEADOCAJA_H
#define _CEMPLEADOCAJA_H

#include "cEmpleado.h"
#include "eMetodo.h"


class cEmpleadoCaja : public cEmpleado {
public:
    cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto);
    ~cEmpleadoCaja();
    eMetodo GET_METODOPAGO();
    bool GET_FORMATO();
    cCarrito GET_CARRITO();
    void Cobrar(float precioTotal);
    cTicketdecompra AgregarTicketCaja(cCarrito carrito, cCliente cliente);

};

#endif //_CEMPLEADOCAJA_H