/**
 * Project Untitled
 */


#ifndef _CFACTURA_H
#define _CFACTURA_H
#include"Headers.h"

class cFactura {
private:
    float monto;
    string nombreCliente;
    string fecha;
    bool formato;

public:
    cFactura(float _monto, string _nombreCliente, string _fecha, bool _formato);
    ~cFactura();
    bool GET_FORMATO();
    void SET_FORMATO(bool _nuevoFormato);

};

#endif //_CFACTURA_H