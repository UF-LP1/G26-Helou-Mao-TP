/**
 * Project Untitled
 */


#ifndef _CFACTURA_H
#define _CFACTURA_H
#include"Headers.h"
#include "cProducto.h"

class cFactura {
private:
    float monto;
    string nombreCliente;
    string apellidoCliente;
    string fecha;
    bool formato;
    vector<cProducto> productosComprados;

public:
    cFactura(float _monto, string nombreCliente, string apellidoCliente,string _fecha, bool _formato, vector<cProducto> _productosComprados);
    ~cFactura();
    bool GET_FORMATO();
    void SET_FORMATO(bool _nuevoFormato);

};

#endif //_CFACTURA_H