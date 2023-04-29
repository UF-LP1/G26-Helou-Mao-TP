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
    cGolosinas(float _precio, string _nombre, int _cantidad, string _marca, eGolosinas _tipoGolosinas);
    ~cGolosinas();
};

#endif //_CGLOSINAS_H