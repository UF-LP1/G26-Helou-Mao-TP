/**
 * Project Untitled
 */


#ifndef _CEMPLEADOCAJA_H
#define _CEMPLEADOCAJA_H

#include "cEmpleado.h"
#include "eMetodo.h"


class cEmpleadoCaja : public cEmpleado {
private:
    double plataCaja;
public:
    cEmpleadoCaja(string dni);
    cEmpleadoCaja(cCliente** lCliente, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, double plataCaja);
    ~cEmpleadoCaja();
    float CalculaMontoACobrar(cCarrito oCarrito);
    cTicketdecompra Cobrar(cCliente cliente);
    void emitirFactura(float precio, cProducto producto, cCliente cliente, int cantidad);
};

#endif //_CEMPLEADOCAJA_H

