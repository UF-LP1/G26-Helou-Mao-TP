/**
 * Project Untitled
 */


#ifndef _CLOCAL_H
#define _CLOCAL_H

#include "cProducto.h"
#include "cEmpleado.h"

class cLocal {
private:
    string nombre;
    string direccion;
    string contacto;
    double fondos;

public:
    cLocal(string _nombre, string _direccion, string _contacto, double _fondos);
    ~cLocal();
    void AgregarTicketCompra(cTicketdecompra _ticketNuevo);

};

#endif //_CLOCAL_H