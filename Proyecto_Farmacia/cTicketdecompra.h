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

public:
    cTicketdecompra(float _precioTotal, string _dni);
    ~cTicketdecompra();
    float GET_TOTAL();
    void SET_TOTAL(float _nuevoTotal);
};

#endif //_CTICKETDECOMPRA_H