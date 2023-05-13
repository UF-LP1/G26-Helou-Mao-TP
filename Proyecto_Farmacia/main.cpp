#include "Headers.h"
#include "cEmpleadoCaja.h"
#include "cTicketdecompra.h"


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


	//creo carrito, cliente y empleado caja con los datos que tengo
	cCarrito carritoCliente(productosCarrito, 300.0);
	string nombreCliente = "guadalupe";
	string apellidoCliente = "guadalupe";
	string ndniCliente = "guadalupe";
	string contactoCliente = "guadalupe";
	double saldoDisp = 1000.0;
	double efectDisp = 3000.0;
	eNecesidad necesidad = farmacia;
	eMetodo metodo = mercadoPago;
	double saldoMp = 4000.0;

	//no sabemos que problema hay con el constructor de cliente, no llegamos
	
	cCliente pruebaFinal(carritoCliente, nombreCliente, apellidoCliente, contactoCliente, metodo, saldoDisp, efectDisp, necesidad, ndniCliente, true, saldoMp);
	string nombreEmp = "Roberto";
	string apellidoEmp = "gGomez";
	string ndniEmp = "356527";
	string contactoEmp = "telefono";
	double plataMiCaja = 15000;
	cEmpleadoCaja miEmpleado(nombreEmp, apellidoEmp, 72728, ndniEmp, contactoEmp, plataMiCaja);


	//implemento funcion cobrar
	cTicketdecompra ticketPrueba = miEmpleado.Cobrar(pruebaFinal);

	//para chequear que funciona imprimo el ticket
	cout << "Compra exitosa:" << ticketPrueba.GET_COMPRA();
	cout << "\n Precio final: " << ticketPrueba.GET_COMPRATOTAL()<<endl;

	vector<cProducto>productosTicket;
	productosTicket = ticketPrueba.GET_LISTAPRO();
	for (int i = 0; i < productosTicket.size(); i++)
	{
		cout << i+1 << "-" << productosTicket[i].Get_PRECIO()<<endl;
	}
	cFactura checkeo = pruebaFinal.GET_FACTURA();
	cout << checkeo.GET_MONTO()<<endl;
	cout << checkeo.GET_NOMBRE() << endl;
	
}