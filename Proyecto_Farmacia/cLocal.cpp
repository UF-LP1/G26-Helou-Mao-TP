/**
 * Project Untitled
 */


#include "cLocal.h"

cLocal::cLocal(string _nombre, string _direccion, string _contacto, double _fondos) {
    this->nombre = _nombre;
    this->direccion = _direccion;
    this->contacto = _contacto;
    this->fondos = _fondos;
}

cLocal::~cLocal() {

}

void cLocal::AgregarTicketCompra(cTicketdecompra _ticketNuevo) {
    return;
}
void cLocal::agregarCliente(cCliente nuevoCliente)
{
    this->clientesEspera.push(nuevoCliente);//lo agrego al final de mi cola

}
cCliente cLocal::PasarClienteMostrador()
{
  
    cCliente siguiente = this->clientesEspera.front();//copio el primer cliente de la cola
      clientesEspera.pop();
      return siguiente;
}
void cLocal::agregarTicket(cTicketdecompra ticketNuevo)
{
    misTickets.push_back(ticketNuevo);
}

