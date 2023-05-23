/**
 * Project Untitled
 */


#ifndef _CEMPLEADOORTOPEDIA_H
#define _CEMPLEADOORTOPEDIA_H

#include "cVendedor.h"


class cEmpleadoOrtopedia : public cVendedor {
private:
    list <cOrtopedia>listaOrtopedia;
   public:
    cEmpleadoOrtopedia(string dni);
    cEmpleadoOrtopedia(string nombre, string apellido, int numerEmpleado, const string dni, string contacto, list <cOrtopedia>listaOrtopedia);
    ~cEmpleadoOrtopedia();
    string Asesorar();
    string RecomendarProductos();
    void AgregarProductoCarrito(cOrtopedia producto);
    void AtenderCliente(cCliente *cliente, cOrtopedia producto);
    cOrtopedia buscarProductoOrtopedia(unsigned int prodAllevar);
    list <cOrtopedia> GET_LISTADO_ORT();
};

#endif //_CEMPLEADOORTOPEDIA_H