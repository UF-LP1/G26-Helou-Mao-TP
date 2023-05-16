/**
 * Project Untitled
 */


#ifndef _CEMPLEADOSPERFUMERIA_H
#define _CEMPLEADOSPERFUMERIA_H

#include "cVendedor.h"


class cEmpleadosPerfumeria : public cVendedor {
public:
	cEmpleadosPerfumeria(string dni);
	cEmpleadosPerfumeria( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto);
	~cEmpleadosPerfumeria();
	void Asesorar(cCliente cliente);

};

#endif //_CEMPLEADOSPERFUMERIA_H