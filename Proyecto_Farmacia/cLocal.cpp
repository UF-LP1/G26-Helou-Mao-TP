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
    this->misTickets.push_back(_ticketNuevo);   //agrego a mi vector de tickets el ticket nuevo
    return;
}
void cLocal::agregarCliente(cCliente nuevoCliente)
{
    this->clientesEspera.push(nuevoCliente);    //lo agrego al final de mi cola

}
cCliente cLocal::PasarClienteMostrador()
{
    cCliente siguiente = this->clientesEspera.front();  //copio el primer cliente de la cola
      clientesEspera.pop();  //saco el cliente que tengo adelante asi la fila avanza
      return siguiente;
}
cTicketdecompra cLocal::GET_ULIMOTICKET()
{
    return this->misTickets.back();
}

