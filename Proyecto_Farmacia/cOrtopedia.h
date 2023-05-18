/**
 * Project Untitled
 */


#ifndef _CORTOPEDIA_H
#define _CORTOPEDIA_H


#include "eOrtopedia.h"
#include "cMedicamento.h"

class cOrtopedia : public cProducto {
private:
    eOrtopedia tipoProducto;

public:
    cOrtopedia(double _precio, string _nombre, string _marca, eOrtopedia _tipoProduct);
    ~cOrtopedia();
    eOrtopedia GET_TIPO();
};

#endif //_CORTOPEDIA_H