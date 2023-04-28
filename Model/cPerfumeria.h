/**
 * Project Untitled
 */


#ifndef _CPERFUMERIA_H
#define _CPERFUMERIA_H

#include "cProducto.h"


class cPerfumeria: public cProducto {
public: 
    
ePerfumeria GET_TIPO();
    
/**
 * @param float
 * @param string
 * @param int
 * @param string
 * @param ePerfumeria
 */
void cPerfumeria(void float, void string, void int, void string, void ePerfumeria);
protected: 
    
void cPerfumeria();
private: 
    ePerfumeria tipoProducto;
};

#endif //_CPERFUMERIA_H