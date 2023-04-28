/**
 * Project Untitled
 */


#ifndef _CMEDICAMENTO_H
#define _CMEDICAMENTO_H

#include "cProducto.h"


class cMedicamento: public cProducto {
public: 
    
/**
 * @param float
 * @param string
 * @param int
 * @param string
 * @param int
 * @param bool
 */
void cMedicamento(void float, void string, void int, void string, void int, void bool);
protected: 
    
void cMedicamento();
private: 
    int dosis;
    bool ventaLibre;
};

#endif //_CMEDICAMENTO_H