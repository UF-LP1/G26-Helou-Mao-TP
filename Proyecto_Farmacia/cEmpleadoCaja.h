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
    vector <cCliente> clientes;
public:
    cEmpleadoCaja(string dni);
    cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, double plataCaja);
    ~cEmpleadoCaja();
    cTicketdecompra Cobrar(cCliente &cliente);
    void emitirFactura(double precio, cCliente& cliente);
    
    bool chequearSaldoDisponible(cCliente cliente, double montoAPagar);

    double CalculaMontoACobrar(cCarrito oCarrito);
    void pagar(cCliente& cliente, double total);
};

#endif //_CEMPLEADOCAJA_H

