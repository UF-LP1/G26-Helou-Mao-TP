/**
 * Project Untitled
 */


#ifndef _CEMPLEADOLIMPIEZA_H
#define _CEMPLEADOLIMPIEZA_H

#include "cEmpleado.h"


class cEmpleadoLimpieza: public cEmpleado {
public: 
    
/**
 * @param int
 */
void SET_TURNO(void int );
    
int GET_TURNO();
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 * @param int
 */
void cEmpleadoLimpieza(void string, void string, void int, void const string, void string, void int);
protected: 
    
void cEmpleadoLimpieza();
private: 
    int truno;
};

#endif //_CEMPLEADOLIMPIEZA_H