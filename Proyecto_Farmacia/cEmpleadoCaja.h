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
    vector <cCliente> clientes;
public:
    cEmpleadoCaja(string dni);
    cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, double plataCaja);
    ~cEmpleadoCaja();
    cTicketdecompra Cobrar();
    void emitirFactura(double precio);
    
    bool chequearSaldoDisponible(double montoAPagar);

    double CalculaMontoACobrar();
    void pagar( double total);
};

#endif //_CEMPLEADOCAJA_H

