/**
 * Project Untitled
 */


#ifndef _CFARMACEUTICO_H
#define _CFARMACEUTICO_H

#include "cVendedor.h"


class cFarmaceutico : public cVendedor {
 
private:
    vector<cMedicamento> medicamentos;
    vector<cDescuento> descuento;
   
public:

    cFarmaceutico(string dni);
    cFarmaceutico(vector<cDescuento> descuento,vector <cMedicamento> medicamento, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cFarmaceutico();
    cDescuento GET_DESCUENTO(string obraSocial);
    void ExplicarDosificacion(cReceta _objetoReceta, cProducto _objetoProducto);
    void RecomendarRemedios(cCliente _miCliente);
    void ExpenderReceta(cReceta _objetoReceta);
    double ChequearDescuentos(cReceta _objetoReceta, cDescuento _objeto);
    double calcularDescuento(double porcentaje, cReceta oReceta);
    void  settearDescuento(cReceta oReceta, cDescuento oDescuento);

};

#endif //_CFARMACEUTICO_H