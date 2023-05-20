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
    //metodo que va a obtener el porcentaje de descuento que le correponde a mi cliente
    cReceta _objetoReceta = misClientes.back().GET_RECETA();    
    double porcentajeAux = 0.0;

    for (cDescuento&desc:descuento) //recorro el listado de descuentos y lo comparo con el del ultimo cliente (que es con el que estoy trabajando)
    {
        if (desc.GET_OBRASOCIAL() == _objetoReceta.GET_OBRASOCIAL())    //Cuando coinciden lo igualo a la variable a devolver
        {
            porcentajeAux = desc.GET_PORCENTAJE();
            return porcentajeAux;
        }
    }

}

void cFarmaceutico:: settearDescuento ()
{   //setteo el descuento en el carrito dle ultimo cliente
    double porcentaje = ChequearDescuentos();//llamo a las otras funciones porque esta es la unica que se ejecuta en el main
    double aDescontar = calcularDescuento(porcentaje);
    misClientes.back().GET_CARRITO()->SET_DESCUENTO(aDescontar);  //aplico descuento al carrito de mi cliente
}

double cFarmaceutico::calcularDescuento(double porcentaje)
{   //metodo que calcula el monto a descontar del precio del medicamento segun su obra social
    cReceta _objetoReceta = misClientes.back().GET_RECETA();    //obtengo la receta del ultimo cliente
    double aDescontar = 0.0;
    for (cMedicamento& med: medicamentos)   //recorro el listado de medicamentos
    {
        if (med.Get_NOMBRE() == _objetoReceta.GET_MEDICAMENTO()) //coinciden
        {
            aDescontar = (med.Get_PRECIO() * porcentaje) / 100;  //calculo la cantidad a descontar
            return aDescontar;
        }
    }
}
void cFarmaceutico::AgregarProductoReceta()
{   //metodo que recorre el listado de medicamentos y compara por nombre con el que trae el cliente en su receta para añadirlo a su carrito
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
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi listado de clientes
    AgregarProductoReceta();
    settearDescuento();
    return;
}

list<cMedicamento> cFarmaceutico::GET_LISTA_MEDICAMENTOS()
{
    return this->medicamentos;
}