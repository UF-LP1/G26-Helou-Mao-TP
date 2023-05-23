/**
 * Project Untitled
 */

#ifndef _CCLIENTE_H
#define _CCLIENTE_H

#include "eNecesidad.h"
#include "eMetodo.h"
#include "cReceta.h"
#include "cCarrito.h"
#include "cFactura.h"


class cCliente {
private:
    static int cantClientes;
    int numeroClientes;
    cFactura miFactura;
    cCarrito miCarrito;
    string nombre;
    string apellido;
    string contacto;
    eMetodo metodoPago;
    double saldoDisponible;
    const string DNI;
    bool facturaFisica;
    cReceta miReceta;
public:
    cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago,double saldoDisponible,  const string dni, bool facturaFisica,cReceta receta);
    cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible,   const string dni, bool facturaFisica);
    cCliente(string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, const string dni, bool facturaFisica);
    ~cCliente();
    int GET_NUMEROCLIENTE();
    cCarrito *GET_CARRITO();
    bool GET_FORMATO();
    eMetodo GET_METODO();
    void SET_FACTURA(cFactura nuevaFactura);
    void AgregarProductosPerfumeria(cPerfumeria *prodPerfumeria, int cantidad);
    void AgregarGolosinas(int prodAllevar, list<cGolosinas>listaGolosinas);
    string GET_DNI();
    cFactura *GET_FACTURA();
    string GET_APELLIDO();
    string GET_NOMBRE();
    double GET_SALDO_DISPONIBLE();
    void SET_SALDO(double *saldoDisponible);
    cReceta GET_RECETA();
    cCliente& operator=(const cCliente&);
    void pagar(double montoTotal);
    void SET_RECETA(cReceta nuevaReceta);
};

#endif //_CCLIENTE_H
