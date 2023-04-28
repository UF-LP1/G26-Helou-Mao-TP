/**
 * Project Untitled
 */


#ifndef _CORTOPEDIA_H
#define _CORTOPEDIA_H

#include "cProducto.h"
#include "eOrtopedia.h"

class cOrtopedia : public cProducto {
private:
    eOrtopedia tipoProducto;

public:
    cOrtopedia(float _precio, string _nombre, int _cantidad, string _marca, eOrtopedia _tipoProduct);
    ~cOrtopedia();
    eOrtopedia GET_TIPO();
};

#endif //_CORTOPEDIA_H