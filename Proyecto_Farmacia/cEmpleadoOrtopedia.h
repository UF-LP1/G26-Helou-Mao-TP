/**
 * Project Untitled
 */


#ifndef _CEMPLEADOORTOPEDIA_H
#define _CEMPLEADOORTOPEDIA_H

#include "cVendedor.h"


class cEmpleadoOrtopedia : public cVendedor {
   public:
    cEmpleadoOrtopedia(string dni);
    cEmpleadoOrtopedia( string nombre, string apellido, int numerEmpleado, const string dni, string contacto);
    ~cEmpleadoOrtopedia();
    void Asesorar();
    void RecomendarProductos();
    void AgregarProductoCarrito(cOrtopedia producto);
    

};

#endif //_CEMPLEADOORTOPEDIA_H