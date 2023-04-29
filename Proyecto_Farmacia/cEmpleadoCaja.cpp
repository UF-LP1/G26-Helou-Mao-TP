/**
 * Project Untitled
 */


#include "cEmpleadoCaja.h"

cEmpleadoCaja::cEmpleadoCaja(string dni)
    :cEmpleado::cEmpleado(dni)
{

}

cEmpleadoCaja::cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, string dni, string contacto)
:cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
    {
    }

cEmpleadoCaja::~cEmpleadoCaja() {

}



void cEmpleadoCaja::Cobrar(float precioTotal, cCliente cliente) {

    //vamos a crear el ticket y llamar a emitir factura
    //vamos al cliente a agregarle una factura
    //despues desde el main, el ticket que se creo se lo agrega a local
    //necesito fecha, eso no se como lo saco.....
    //devuelve ticket de compra, lo pongo en void para que no salte error
    return;
}

void cEmpleadoCaja::emitirFactura(float precio, cProducto producto, cCliente cliente, int cantidad) {
    
    return;
}
