/**
 * Project Untitled
 */


#ifndef _CPRODUCTO_H
#define _CPRODUCTO_H

#include"Headers.h"

class cProducto {

protected:
    double precio;
    string nombre;
    string marca;

public:
    cProducto();
    cProducto(double _precio, string _nombre,  string marca);
    ~cProducto();
    double Get_PRECIO();
    string GET_MARCA();
    string Get_NOMBRE();

};

#endif //_CPRODUCTO_H