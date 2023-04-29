/**
 * Project Untitled
 */


#ifndef _CFARMACEUTICO_H
#define _CFARMACEUTICO_H

#include "cEmpleado.h"


class cFarmaceutico : public cEmpleado {
 
private:
    vector<cDescuento> descuento;
   
public:

    cFarmaceutico(string dni);
    cFarmaceutico(vector<cDescuento> descuento, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cFarmaceutico();
    vector<cDescuento> GET_DESCUENTO();
    cProducto GET_MEDICAMENTO();
    void ExplicarDosificacion(cReceta _objetoReceta, cProducto _objetoProducto);
    void RecomendarRemedios(cCliente _miCliente);
    void ExpenderReceta(cReceta _objetoReceta);
    float ChequearDescuentos(cReceta _objetoReceta, cDescuento _objeto);

};

#endif //_CFARMACEUTICO_H