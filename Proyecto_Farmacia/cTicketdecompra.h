/**
 * Project Untitled
 */


#ifndef _CTICKETDECOMPRA_H
#define _CTICKETDECOMPRA_H
#include "cProducto.h"


class cTicketdecompra {
private:
    float precioTotal;
    string DNI;
    string nombreEmpleado;
    string apellidoEmpleado;
    int numeroEmpleado;
    string nombreCliente;
    string apellidoCliente;
    vector<cProducto> productosComprados;

public:
    cTicketdecompra(float _precioTotal, string _dni, string nombreEmpleado, string apellidoEmpleado, int numeroEmpleado, string nombreCliente, string apellidoCliente, vector<cProducto> productosComprados);
    ~cTicketdecompra();
    float GET_TOTAL();
    void SET_TOTAL(float _nuevoTotal);
};

#endif //_CTICKETDECOMPRA_H