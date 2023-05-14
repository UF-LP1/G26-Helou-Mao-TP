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
    cPerfumeria(double _precio, string _nombre, string _marca, ePerfumeria _tipoProduct);
    ~cPerfumeria();
    ePerfumeria GET_TIPO();

};

#endif //_CPERFUMERIA_H