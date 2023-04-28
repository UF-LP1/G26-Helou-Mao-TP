/**
 * Project Untitled
 */


#ifndef _CPRODUCTO_H
#define _CPRODUCTO_H

#include"Headers.h"

class cProducto {

protected:
    float precio;
    string nombre;
    int cantidad;
    string marca;

public:
    cProducto(float _precio, string _nombre, int _cantidad, string marca);
    ~cProducto();
    float Get_PRECIO();
    string Get_NOMBRE();

};

#endif //_CPRODUCTO_H