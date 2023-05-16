
#ifndef _CEMPLEADO_H
#define _CEMPLEADO_H
#include "cTicketdecompra.h"
#include "cDescuento.h"
#include "cCliente.h"
#include "Headers.h"

class cEmpleado {

protected:
    //tendriamos un listado de clientes, en funcioon cobrar no es relevante pero a futuro habria que agregarlo
    string nombre;
    string apellido;
    int numeroEmpleado;
    const string DNI;
    string contacto;

public:
    cEmpleado(string dni);
    cEmpleado( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cEmpleado();
};

#endif //_CEMPLEADO_H