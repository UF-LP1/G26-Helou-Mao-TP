
#ifndef _CEMPLEADO_H
#define _CEMPLEADO_H
#include "cTicketdecompra.h"
#include "cDescuento.h"
#include "cCliente.h"
#include "Headers.h"

class cEmpleado {

protected:
    cCliente** lClientes;
    string nombre;
    string apellido;
    int numeroEmpleado;
    const string DNI;
    string contacto;

public:
    cEmpleado(string dni);
    cEmpleado(cCliente **lClientes, string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
    ~cEmpleado();
    void AtenderCliente(cCliente cliente);
    void AgregarProductoCarrito(cProducto producto, cCarrito carrito);
    void PasarClienteaCaja(cCliente cliente);

};

#endif //_CEMPLEADO_H