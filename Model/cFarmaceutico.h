/**
 * Project Untitled
 */


#ifndef _CFARMACEUTICO_H
#define _CFARMACEUTICO_H

#include "cEmpleado.h"


class cFarmaceutico: public cEmpleado {
public: 
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 */
void cFarmaceutico(void string, void string, void int, void const string, void string);
    
cDescuento GET_LISTADESCUENTOS();
    
cReceta GET_RECETA();
    
cProducto GET_MEDICAMENTO();
    
/**
 * @param cReceta
 * @param cProducto
 */
void ExplicarDosificacion(void cReceta, void cProducto);
    
/**
 * @param cCliente
 */
void RecomendarRemedios(void cCliente);
    
/**
 * @param cReceta
 */
void ExpenderReceta(void cReceta);
    
/**
 * @param cReceta
 * @param cDescuentos
 */
float ChequearDescuentos(void cReceta, void cDescuentos);
protected: 
    
void cFarmaceutico();
};

#endif //_CFARMACEUTICO_H