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
    static int numeroCliente;
    cFactura miFactura;
    cCarrito miCarrito;
    string nombre;
    string apellido;
    string contacto;
    eMetodo metodoPago;
    double saldoDisponible;
    double efectivodisponible;
    eNecesidad necesidad;
    const string DNI;
    bool facturaFisica;
    double saldoMPago;
public:
    cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago,double saldoDisponible, double efectivoDisponible, eNecesidad necesidad, const string dni, bool facturaFisica,double MP);
    ~cCliente();
    static int GET_NUMEROCLIENTE();
    cCarrito GET_CARRITO();
    bool GET_FORMATO();
    eMetodo GET_METODO();
    void SET_FACTURA(cFactura nuevaFactura);
    void AgregarProductosPerfumeria(cProducto prodPerfumeria, int cantidad);
    void AgregarGolosinas(cProducto golosinas, int cantidad);
    string GET_DNI();
    cFactura GET_FACTURA();
    string GET_APELLIDO();
    string GET_NOMBRE();
    double GET_SALDO_DISPONIBLE();
    double GET_EFECTIVO_DISPONIBLE();
    double GET_SALDO_MP();

};

#endif //_CCLIENTE_H
