#include "Headers.h"
#include "cEmpleadoCaja.h"


int main()
{
	vector<cFactura> facturaPrueba;
	vector<cProducto>productosCarrito;

	cProducto Nuevo(70.0, "champu", "garnier");
	cProducto Nuevo2(250.0, "ibuprofeno", "actron");
	cProducto Nuevo3(120.0, "esmalte", "pirulo");

	productosCarrito.push_back(Nuevo);
	productosCarrito.push_back(Nuevo2);
	productosCarrito.push_back(Nuevo3);
	productosCarrito.push_back(Nuevo3);



	cCarrito carritoCliente(productosCarrito, 300);
	cCliente pruebaFinal(carritoCliente, "Guadalupe", "Helou", "200564", 2, 1000.0, 3000.0, 2, "46353626", true);

	cEmpleadoCaja miEmpleado("Roberto", "Gomez", 4789, "2198652", "telefono");
	miEmpleado.Cobrar(pruebaFinal);

	
}