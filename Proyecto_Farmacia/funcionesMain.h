#pragma once
#include "Headers.h"
#include "cEmpleadoMostrador.h"
#include "cTicketdecompra.h"
#include "cLocal.h"

cFarmaceutico creacionFarmaceutico();
cEmpleadoCaja creacionEmpleadoCaja();
cEmpleadoMostrador creacionEmpMostrador();
cEmpleadoOrtopedia creacionEmpOrto();
cEmpleadosPerfumeria creacionEmpPerfumeria();
void impresionChequeoQueAnda(cEmpleadoCaja empleadoCaja, cTicketdecompra ticket, cCliente miCliente0);
cCliente atencionOrtopedia(cCliente clienteAux, cEmpleadoOrtopedia empleadoOrt, unsigned int prodAllevar);
cCliente atencionPerfumeria(cCliente clienteAux, cEmpleadosPerfumeria empleadoPerfumeria, unsigned int prodAllevar);
cCliente atencionFarmaceutico(cCliente& clienteAux, cFarmaceutico farmaceutico);
void imprimirProductosPerfumeria(cEmpleadosPerfumeria empleadoPerfumeria);
void imprimirProductosOrtopedia(cEmpleadoOrtopedia empleadoOrt);
void imprimirNecesidad();
void opcionesMetodo();
eMetodo casteoMetodo(int metodoAux);
void imprimirGolosinas(list<cGolosinas> listaGolosinas);
list<cGolosinas> creacionGolosinas();
void imprimirCarrito(cCliente miCliente0);