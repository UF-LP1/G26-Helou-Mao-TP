#include "cVendedor.h"

cVendedor::cVendedor(string dni)
    :cEmpleado::cEmpleado(dni)
{
}

cVendedor::cVendedor(string nombre, string apellido, int numeroEmpleado, string dni, string contacto)
    :cEmpleado(nombre, apellido, numeroEmpleado, dni, contacto)
{
}

cVendedor::~cVendedor() {

}
void cVendedor::AtenderCliente(cCliente *cliente) { 
    this->misClientes.push_back(*cliente);   //agrego el nuevo cliente al final de mi vector de clientes
    return; 
}

cCliente cVendedor::PasarClienteaCaja() //agarro el ultimo cliente que atendi para devolverlo y en el main pasarselo a la caja
{    
    return misClientes.back();
}