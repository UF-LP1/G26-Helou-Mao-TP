
#ifndef _CEMPLEADO_H
#define _CEMPLEADO_H
#include "cTicketdecompra.h"
#include "cDescuento.h"
#include "cCliente.h"
#include "Headers.h"

class cEmpleado {

protected:

    string nombre;
    string apellido;
    int numeroEmpleado;
    const string DNI;
    string contacto;

public:

    cEmpleado(string nombre, string apellido, int numeroEmpleado, const string DNI, string contacto);
    ~cEmpleado();
    void AtenderCliente(cCliente cliente);
    float CalculaMontoACobrar(cProducto producto, int cantidad, float precio);
    cTicketdecompra EmitirTicket(float precio, cProducto producto, cCliente cliente, int cantidad);
    void AgregarProductoCarrito(cProducto producto, cCarrito carrito);
    void PasarClienteaCaja(cCliente cliente);

};

#endif //_CEMPLEADO_H