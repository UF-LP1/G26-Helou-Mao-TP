/**
 * Project Untitled
 */


#ifndef _CEMPLEADOORTOPEDIA_H
#define _CEMPLEADOORTOPEDIA_H

#include "cEmpleado.h"


class cEmpleadoOrtopedia: public cEmpleado {
public: 
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 */
void cEmpleadoOrtopedia(void string, void string, void int, void const string, void string);
    
structLesion GET_LESION();
    
/**
 * @param cCliente
 */
void Asesorar(void cCliente);
    
/**
 * @param cCliente
 */
void RecomendarProductos(void cCliente);
protected: 
    
void cEmpleadoOrtopedia();
};

#endif //_CEMPLEADOORTOPEDIA_H