/**
 * Project Untitled
 */


#include "cEmpleadoCaja.h"

cEmpleadoCaja::cEmpleadoCaja(string dni)
    :cEmpleado::cEmpleado(dni)
{
    this->plataCaja = 0.0;
}

cEmpleadoCaja::cEmpleadoCaja(cCliente** lCliente,string nombre, string apellido, int numeroEmpleado, string dni, string contacto, double plataCaja)
:cEmpleado(lCliente, nombre, apellido, numeroEmpleado, dni, contacto)
    {
    this->plataCaja = plataCaja;
    }

cEmpleadoCaja::~cEmpleadoCaja() {

}


float cEmpleadoCaja::CalculaMontoACobrar(cCarrito oCarrito) {
    vector<cProducto> auxProds; //la memoria se libera automaticamente
    auxProds = oCarrito.GET_LISTAPRODUCTOS();
    int i;
    float total = 0.0;  //valor  devolver para cobrar
    for (i = 0; i < auxProds.size(); i++)
    {
        total = total + auxProds[i].Get_PRECIO();   //voy sumando precio de acda unidad que tengo 
    }
    return total;   //devuelvo el total
}
//cTicketdecompra cEmpleadoCaja::Cobrar(cCliente cliente) {
//    float montoTotal = CalculaMontoACobrar(cliente.GET_CARRITO());  //le paso el carrito de este cliente específico para obtener su saldo
//    //vamos a crear el ticket y llamar a emitir factura
//    //vamos al cliente a agregarle una factura
//    //despues desde el main, el ticket que se creo se lo agrega a local
//    //necesito fecha, eso no se como lo saco.....
//    //devuelve ticket de compra, lo pongo en void para que no salte error
//    retu;
//}

void cEmpleadoCaja::emitirFactura(float precio, cProducto producto, cCliente cliente, int cantidad) {
    
    return;
}
