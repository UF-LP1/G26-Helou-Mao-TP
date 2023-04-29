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
    cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, double plataCaja);
    ~cEmpleadoCaja();
    double CalculaMontoACobrar(cCarrito oCarrito);
    cTicketdecompra Cobrar(cCliente cliente);
    bool chequearSaldoDisponible(cCliente cliente, double montoAPagar);
    void emitirFactura(double precio, cCliente cliente);
    
};

#endif //_CEMPLEADOCAJA_H

