/**
 * Project Untitled
 */

#ifndef _CCLIENTE_H
#define _CCLIENTE_H

#include "eNecesidad.h"
#include "eMetodo.h"
#include "cReceta.h"
#include "cCarrito.h"
#include "cNumeroCliente.h"
#include "cFactura.h"


class cCliente {
private:
    vector<cFactura>miFactura;
    cCarrito miCarrito;
    string nombre;
    string apellido;
    string contacto;
    eMetodo metodoPago;
    eNecesidad necesidad;
    const string DNI;
    bool facturaFisica;
public:
    cCliente(vector<cFactura>miFactura,cCarrito miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, eNecesidad necesidad, const string dni, bool facturaFisica);
    ~cCliente();
    cCarrito GET_CARRITO();
    bool GET_FORMATO();
    void AgregarProductosPerfumeria(cProducto prodPerfumeria, int cantidad);
    void AgregarGolosinas(cProducto golosinas, int cantidad);
    string GET_DNI();

};

#endif //_CCLIENTE_H
//como para agregar algo, en la factura puedo poner cuanta plata desconte por obra social
//ideas :::::voy a necesitar una funcion agregar cliente en los empleados, clientes puede ser una pila y voy viendo el de arriba
//en cobrar llamo a la funcion emitir factura, le voy a tener que pasar a cobrar el cliente, de ahi saco su carrrito, su metodo de pago
//¿¿¿¿como veo la cantidad de cada producto???? podriamos hacer que lo imprima, usando un cont en una de las librerias(no me avuerdo cual)
// problema::no se como hariamos para que esa cantidad quede registrada en el ticket o algo
//emito el ticket, voy a devolverlo asi dsp puedo agregarselo al local desde el main
/// puedo hacer que se impriman en pantalla las cosas importantes para comprobar que funciona