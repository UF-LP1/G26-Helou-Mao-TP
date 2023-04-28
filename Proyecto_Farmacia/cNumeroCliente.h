/**
 * Project Untitled
 */


#ifndef _CNUMEROCLIENTE_H
#define _CNUMEROCLIENTE_H

class cNumeroCliente {
private:
    int numero;

public:
    cNumeroCliente(int _numeroActual);
    ~cNumeroCliente();
    int GET_NUMERO();
    void SET_NUMERO(int _numeroNuevo);

};

#endif //_CNUMEROCLIENTE_H