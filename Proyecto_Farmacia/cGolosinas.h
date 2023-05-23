/**
 * Project Untitled
 */


#ifndef _CGLOSINAS_H
#define _CGLOSINAS_H

#include "cProducto.h"
#include "eGolosinas.h"


class cGolosinas : public cProducto {
private:
    eGolosinas tipoGolosina;
public:
    cGolosinas(double _precio, string _nombre, string _marca, eGolosinas _tipoGolosinas);
    ~cGolosinas();
    eGolosinas GET_TIPO();
};

#endif //_CGLOSINAS_H 