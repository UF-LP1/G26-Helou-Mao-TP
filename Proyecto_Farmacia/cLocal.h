/**
 * Project Untitled
 */


#ifndef _CLOCAL_H
#define _CLOCAL_H

#include "cProducto.h"
#include "cEmpleado.h"

class cLocal {
private:
    //hay que agregarle algun contenedor en el que esten los tickets de compra de toodos los clientes(preferentemente en algun orden tippo abc)
    string nombre;
    string direccion;
    string contacto;
    double fondos;
    queue<cCliente> clientesEspera; 
    vector<cTicketdecompra> misTickets;


public:
    cLocal(string _nombre, string _direccion, string _contacto, double _fondos);
    ~cLocal();
    void AgregarTicketCompra(cTicketdecompra _ticketNuevo);
    void agregarCliente(cCliente nuevoCliente);
    cCliente PasarClienteMostrador();
    void agregarTicket(cTicketdecompra ticketNuevo); 

};

#endif //_CLOCAL_H