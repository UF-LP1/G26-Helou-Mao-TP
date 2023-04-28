/**
 * Project Untitled
 */


#ifndef _CPERFUMERIA_H
#define _CPERFUMERIA_H

#include "cProducto.h"
#include "ePerfumeria.h"


class cPerfumeria : public cProducto {

private:
    ePerfumeria tipoProducto;

public:
    cPerfumeria(float _precio, string _nombre, int _cantidad, string _marca, ePerfumeria _tipoProduct);
    ~cPerfumeria();
    ePerfumeria GET_TIPO();

};

#endif //_CPERFUMERIA_H