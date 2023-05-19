/**
 * Project Untitled
 */


#include "cFarmaceutico.h"
    //constructor por defeccto de farmaceutico
cFarmaceutico::cFarmaceutico(string dni)
    :cVendedor::cVendedor(dni)
{

}
    //constructor de farmaceutico con todos sus datos
cFarmaceutico::cFarmaceutico( list<cDescuento>descuent, list<cMedicamento> medicamento, string nombre, string apellido, int numeroEmpleado, string dni, string contacto)
    :cVendedor( nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->descuento = descuent;
    this->medicamentos = medicamento;
}

cFarmaceutico::~cFarmaceutico() {

}

//cDescuento cFarmaceutico::GET_DESCUENTO(string obraSocial) {
//    
//    for (list<cDescuento>::iterator it=descuento.begin(); it!=descuento.end(); it++)
//    {
//        if (it->GET_OBRASOCIAL() == obraSocial)
//        {
//            return *it;
//        }
//    }
//   
//}

void cFarmaceutico::ExplicarDosificacion( cProducto _objProducto) {
    return;
}

void cFarmaceutico::RecomendarRemedios() {
    return;
}

void cFarmaceutico::ExpenderReceta() {
    return;
}

double cFarmaceutico::ChequearDescuentos( ) {

    /*list<cCliente> ::iterator it = misClientes.end();*/
    cReceta _objetoReceta = misClientes.back().GET_RECETA();
    double porcentajeAux = 0.0;
    for (cDescuento&desc:descuento)
    {
        if (desc.GET_OBRASOCIAL() == _objetoReceta.GET_OBRASOCIAL())
        {
            porcentajeAux = desc.GET_PORCENTAJE();
            return porcentajeAux;
        }
    }

}


void cFarmaceutico:: settearDescuento ()
{
    double porcentaje = ChequearDescuentos();//llamo a las otras funciones porque esta es la unica que se ejecut en el main
    double aDescontar = calcularDescuento(porcentaje);
   misClientes.back().GET_CARRITO()->SET_DESCUENTO(aDescontar);  //aplico descuento al carrito de mi cliente
}
double cFarmaceutico::calcularDescuento(double porcentaje)
{
    cReceta _objetoReceta = misClientes.back().GET_RECETA();
    double aDescontar = 0.0;
    for (cMedicamento& med: medicamentos)
    {
        if (med.Get_NOMBRE() == _objetoReceta.GET_MEDICAMENTO())
        {
            aDescontar = (med.Get_PRECIO() * porcentaje) / 100;  //descuento el porcentaje
            return aDescontar;
        }
    }
}
void cFarmaceutico::AgregarProductoReceta()
{
    cReceta auxReceta = misClientes.back().GET_RECETA();

    for (cMedicamento& med: medicamentos)
    {
        if (med.Get_NOMBRE() == auxReceta.GET_MEDICAMENTO())
        {
           misClientes.back().GET_CARRITO()->SET_PRODUCTO(&med);
        }
    }
   
}
void cFarmaceutico::AtenderCliente(cCliente *cliente) {
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi vector de clientes
    AgregarProductoReceta();
    settearDescuento();
    return;
}