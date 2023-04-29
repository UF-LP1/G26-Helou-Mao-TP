/**
 * Project Untitled
 */


#ifndef _CDESCUENTO_H
#define _CDESCUENTO_H
#include "cCliente.h"

class cDescuento {
private:

    double porcentaje;
    string obraSocial;

public:
    cDescuento(double porcentaje, string obraSocial);
    ~cDescuento();
    double GET_PORCENTAJE();
    string GET_OBRASOCIAL();
};

#endif //_CDESCUENTO_H