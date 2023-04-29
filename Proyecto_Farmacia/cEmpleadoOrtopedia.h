/**
 * Project Untitled
 */


#ifndef _CEMPLEADOORTOPEDIA_H
#define _CEMPLEADOORTOPEDIA_H

#include "cEmpleado.h"


class cEmpleadoOrtopedia : public cEmpleado {

public:
    cEmpleadoOrtopedia(string dni);
    cEmpleadoOrtopedia(cCliente** lCliente, string nombre, string apellido, int numerEmpleado, const string dni, string contacto);
    ~cEmpleadoOrtopedia();
    void Asesorar(cCliente cliente);
    void RecomendarProductos(cCliente cliente);
};

#endif //_CEMPLEADOORTOPEDIA_H