/**
 * Project Untitled
 */


#ifndef _CFACTURA_H
#define _CFACTURA_H

class cFactura {
public: 
    
bool GET_FORMATO();
    
/**
 * @param bool
 */
void SET_FORMATO(void bool );
    
/**
 * @param float
 * @param string
 * @param string
 * @param bool
 */
void cFactura(void float, void string, void string, void bool);
protected: 
    
void cFactura();
private: 
    float monto;
    string nombreCliente;
    string fecha;
    bool formato;
};

#endif //_CFACTURA_H