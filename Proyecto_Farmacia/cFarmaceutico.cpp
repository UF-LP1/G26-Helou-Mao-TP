/**
 * Project Untitled
 */


#include "cFarmaceutico.h"

cFarmaceutico::cFarmaceutico(string dni)
    :cVendedor::cVendedor(dni)
{

}

cFarmaceutico::cFarmaceutico( vector<cDescuento>descuent, vector<cMedicamento> medicamento, string nombre, string apellido, int numeroEmpleado, string dni, string contacto)
    :cVendedor( nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->descuento = descuent;
}

cFarmaceutico::~cFarmaceutico() {

}

cDescuento cFarmaceutico::GET_DESCUENTO(string obraSocial) {
    
    for (int i = 0; i < this->descuento.size(); i++)
    {
        if (descuento[i].GET_OBRASOCIAL() == obraSocial)
        {
            return descuento[i];
        }
    }
   
}

void cFarmaceutico::ExplicarDosificacion(cReceta _objetoRec, cProducto _objProducto) {
    return;
}

void cFarmaceutico::RecomendarRemedios(cCliente miCliente) {
    return;
}

void cFarmaceutico::ExpenderReceta(cReceta miReceta) {
    return;
}

double cFarmaceutico::ChequearDescuentos(cReceta _objetoReceta, cDescuento _objetoDescuento) {

    double porcentajeAux = 0.0;
    for (int i = 0; i < this->descuento.size(); i++)
    {
        if (descuento[i].GET_OBRASOCIAL() == _objetoReceta.GET_OBRASOCIAL())
        {
            porcentajeAux = descuento[i].GET_PORCENTAJE();
            return porcentajeAux;
        }
    }

}

double cFarmaceutico::calcularDescuento(double porcentaje, cReceta oReceta)
{
    double aDescontar = 0.0;
    for (int i = 0; i < this->medicamentos.size(); i++)
    {
        if (medicamentos[i].Get_NOMBRE() == oReceta.GET_MEDICAMENTO())
        {
            aDescontar = (medicamentos[i].Get_PRECIO()*porcentaje)/100;  //descuento el porcentaje
            return aDescontar;
        }
    }
}
void cFarmaceutico:: settearDescuento(cReceta oReceta, cDescuento oDescuento)
{
    double porcentaje = ChequearDescuentos(oReceta, oDescuento);//llamo a las otras funciones porque esta es la unica que se ejecut en el main
    double aDescontar = calcularDescuento(porcentaje, oReceta);
    int ultPos = clientes.size();   //obtengo el tamaño de mi vector para poder trabajar co nel ultimo cliente
    cCarrito* carritoAux = clientes[ultPos].GET_CARRITO();
    carritoAux->SET_DESCUENTO(aDescontar);  //aplico descuento al carrito de mi cliente
}