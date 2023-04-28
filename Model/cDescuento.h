/**
 * Project Untitled
 */


#ifndef _CDESCUENTO_H
#define _CDESCUENTO_H
#include "cCliente.h"

class cDescuento {
private:
    float porcentaje;
    string obraSocial;

public:
    cDescuento(float porcentaje, string obraSocial);
    ~cDescuento();
    float GET_PORCENTAJE();
    string GET_OBRASOCIAL();
};

#endif //_CDESCUENTO_H