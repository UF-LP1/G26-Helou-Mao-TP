/**
 * Project Untitled
 */


#ifndef _CFARMACEUTICO_H
#define _CFARMACEUTICO_H

#include "cEmpleado.h"


class cFarmaceutico : public cEmpleado {
public:
    cFarmaceutico(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto);
    ~cFarmaceutico();
    cDescuento GET_LISTADESCUENTOS();
    cReceta GET_RECETA();
    cProducto GET_MEDICAMENTO();
    void ExplicarDosificacion(cReceta _objetoReceta, cProducto _objetoProducto);
    void RecomendarRemedios(cCliente _miCliente);
    void ExpenderReceta(cReceta _objetoReceta);
    float ChequearDescuentos(cReceta _objetoReceta, cDescuento _objeto);

};

#endif //_CFARMACEUTICO_H