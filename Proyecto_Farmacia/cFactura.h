/**
 * Project Untitled
 */


#ifndef _CFACTURA_H
#define _CFACTURA_H
#include"Headers.h"
#include "cProducto.h"

class cFactura {
private:
    double monto;
    string nombreCliente;
    string apellidoCliente;
    bool formato;
    list<cProducto> productosComprados;

public:
    cFactura();
    cFactura(double _monto, string nombreCliente, string apellidoCliente, bool _formato, list<cProducto> _productosComprados);
    ~cFactura();
    double GET_MONTO();
    string GET_NOMBRE();
    bool GET_FORMATO();
    void SET_FORMATO(bool _nuevoFormato);
    void SET_NOMBRECLIENTE(string _nuevoNombreCliente);
    void SET_APELLIDOCLIENTE(string _nuevoApellidoCliente);
    void SET_MONTO(double _nuevomonto);


};

#endif //_CFACTURA_H