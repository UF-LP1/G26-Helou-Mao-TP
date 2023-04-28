/**
 * Project Untitled
 */


#ifndef _CORTOPEDIA_H
#define _CORTOPEDIA_H

#include "cProducto.h"


class cOrtopedia: public cProducto {
public: 
    
eOrtopedia GET_TIPO();
    
/**
 * @param float
 * @param string
 * @param int
 * @param string
 * @param eOrtopedia
 */
void cOrtopedia(void float, void string, void int, void string, void eOrtopedia);
protected: 
    
void cOrtopedia();
private: 
    eOrtopedia tipoProducto;
};

#endif //_CORTOPEDIA_H