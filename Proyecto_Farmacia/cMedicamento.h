/**
 * Project Untitled
 */


#ifndef _CMEDICAMENTO_H
#define _CMEDICAMENTO_H

#include "cGolosinas.h"



class cMedicamento : public cProducto {

private:
    int dosis;
    bool ventaLibre;
    

public:
    cMedicamento(double _precio, string _nombre, string _marca, int _dosis, bool _ventaLibre);
    ~cMedicamento(); 
    bool GET_VENTA_LIBRE();
};

#endif //_CMEDICAMENTO_H