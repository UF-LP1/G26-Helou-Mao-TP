/**
 * Project Untitled
 */


#ifndef _CGLOSINAS_H
#define _CGLOSINAS_H

#include "cProducto.h"


class cGlosinas: public cProducto {
public: 
    
/**
 * @param float
 * @param string
 * @param int
 * @param string
 * @param eGolosinas
 */
void cGolosinas(void float, void string, void int, void string, void eGolosinas);
protected: 
    
void cGolosinas();
private: 
    eGolosinas tipoGolosina;
};

#endif //_CGLOSINAS_H