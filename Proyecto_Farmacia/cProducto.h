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
    virtual double Get_PRECIO();
    virtual string GET_MARCA();
    virtual string Get_NOMBRE();

};

#endif //_CPRODUCTO_H