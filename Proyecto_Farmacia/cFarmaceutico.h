/**
 * Project Untitled
 */


#ifndef _CFARMACEUTICO_H
#define _CFARMACEUTICO_H

#include "cEmpleadosPerfumeria.h"


class cFarmaceutico : public cVendedor {
 
private:
    list<cMedicamento> medicamentos;
    list<cDescuento> descuento;
   
public:

    cFarmaceutico(string dni);
    cFarmaceutico(list<cDescuento> descuento,list <cMedicamento> medicamento, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cFarmaceutico();
    //cDescuento GET_DESCUENTO(string obraSocial);
    void ExplicarDosificacion( cProducto _objetoProducto);
    void RecomendarRemedios();
    void ExpenderReceta();
    double ChequearDescuentos();
    double calcularDescuento(double porcentaje);
    void  settearDescuento( );
    void AgregarProductoReceta();
    void AtenderCliente(cCliente *cliente);
};

#endif //_CFARMACEUTICO_H