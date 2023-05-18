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
    void ExplicarDosificacion( cProducto _objetoProducto);
    void RecomendarRemedios();
    void ExpenderReceta();
    double ChequearDescuentos( cDescuento _objeto);
    double calcularDescuento(double porcentaje);
    void  settearDescuento( cDescuento oDescuento);
    void AgregarProductoReceta();
};

#endif //_CFARMACEUTICO_H