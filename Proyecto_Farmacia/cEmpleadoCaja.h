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
    cEmpleadoCaja( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cEmpleadoCaja();
   
    void Cobrar(float precioTotal, cCliente cliente);
    void emitirFactura(float precio, cProducto producto, cCliente cliente, int cantidad);
};

#endif //_CEMPLEADOCAJA_H

