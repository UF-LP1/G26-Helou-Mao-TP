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

void cFarmaceutico::ExplicarDosificacion( cProducto _objProducto) {
    return;
}

void cFarmaceutico::RecomendarRemedios() {
    return;
}

void cFarmaceutico::ExpenderReceta() {
    return;
}

double cFarmaceutico::ChequearDescuentos( cDescuento _objetoDescuento) {

    int aux = misClientes.size();
    cReceta _objetoReceta = misClientes[aux].GET_RECETA();
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

double cFarmaceutico::calcularDescuento(double porcentaje)
{
    int aux = misClientes.size();
    cReceta _objetoReceta = misClientes[aux].GET_RECETA();
    double aDescontar = 0.0;
    for (int i = 0; i < this->medicamentos.size(); i++)
    {
        if (medicamentos[i].Get_NOMBRE() == _objetoReceta.GET_MEDICAMENTO())
        {
            aDescontar = (medicamentos[i].Get_PRECIO()*porcentaje)/100;  //descuento el porcentaje
            return aDescontar;
        }
    }
}
void cFarmaceutico:: settearDescuento (cDescuento oDescuento)
{
   
    double porcentaje = ChequearDescuentos(oDescuento);//llamo a las otras funciones porque esta es la unica que se ejecut en el main
    double aDescontar = calcularDescuento(porcentaje);
    int ultPos = misClientes.size();   //obtengo el tamaño de mi vector para poder trabajar co nel ultimo cliente
    
    cCarrito* carritoAux = misClientes[ultPos].GET_CARRITO();
    carritoAux->SET_DESCUENTO(aDescontar);  //aplico descuento al carrito de mi cliente
}
void cFarmaceutico::AgregarProductoReceta()
{
    int aux = misClientes.size();
    cReceta auxReceta = misClientes[aux].GET_RECETA();
    for (int i = 0; i < this->medicamentos.size(); i++)
    {
        if (medicamentos[i].Get_NOMBRE() == auxReceta.GET_MEDICAMENTO())
        {
            misClientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS().push_back(medicamentos[i]);
        }
    }
}
 