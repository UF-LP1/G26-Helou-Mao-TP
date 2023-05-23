/**
 * Project Untitled
 */


#ifndef _CEMPLEADOCAJA_H
#define _CEMPLEADOCAJA_H

#include "cFarmaceutico.h"
#include "eMetodo.h"


class cEmpleadoCaja : public cEmpleado {
private:
    double plataCaja;
    list <cCliente> clientes;
public:
    cEmpleadoCaja(string dni);
    cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, double plataCaja);
    ~cEmpleadoCaja();
    cTicketdecompra Cobrar(cCliente* cliente);
    void emitirFactura(double precio);
    void AtenderCliente(cCliente *cliente);
    bool chequearSaldoDisponible(double montoAPagar);
    double GET_PLATA();
    double CalculaMontoACobrar();
    list <cCliente> GET_CLIENTES();

};

#endif //_CEMPLEADOCAJA_H

