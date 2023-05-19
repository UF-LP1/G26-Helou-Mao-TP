/**
 * Project Untitled
 */


#ifndef _CTICKETDECOMPRA_H
#define _CTICKETDECOMPRA_H
#include "cPerfumeria.h"


class cTicketdecompra {
private:
    bool compraExitosa;
    double precioTotal;
    string DNI;
    string nombreEmpleado;
    string apellidoEmpleado;
    int numeroEmpleado;
    string nombreCliente;
    string apellidoCliente;
    list<cProducto> productosComprados;

public:
    cTicketdecompra();
    cTicketdecompra(bool compraExitosa,double _precioTotal, string _dni, string nombreEmpleado, string apellidoEmpleado, int numeroEmpleado, string nombreCliente, string apellidoCliente, list<cProducto> productosComprados);
    ~cTicketdecompra();
    bool GET_COMPRA();
    double GET_PRECIOFINAL();
    list<cProducto> GET_LISTAPRO();
    void SET_TOTAL(double _nuevoTotal);
};

#endif //_CTICKETDECOMPRA_H