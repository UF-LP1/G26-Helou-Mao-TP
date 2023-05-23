/**
 * Project Untitled
 */


#ifndef _CEMPLEADOSPERFUMERIA_H
#define _CEMPLEADOSPERFUMERIA_H

#include "cEmpleadoOrtopedia.h"


class cEmpleadosPerfumeria : public cVendedor {
private:
	list <cPerfumeria> listaPerfumeria;
public:
	cEmpleadosPerfumeria(string dni);
	cEmpleadosPerfumeria( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, list <cPerfumeria> listaPerfumeria);
	~cEmpleadosPerfumeria();
	string Asesorar();
	void AgregarProductoCarrito(cPerfumeria &producto);
	void AtenderCliente(cCliente *cliente, cPerfumeria *producto);
	list<cPerfumeria> GET_LISTADO();
	cPerfumeria buscarProducto(unsigned int prodAllevar);
};

#endif //_CEMPLEADOSPERFUMERIA_H