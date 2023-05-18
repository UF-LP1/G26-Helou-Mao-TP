#include "Headers.h"
#include "cEmpleadoCaja.h"
#include "cTicketdecompra.h"
int cCliente::cantClientes = 1;


int main()
{
	vector<cFactura> facturaPrueba;
	vector<cProducto>productosCarrito;

	cProducto Nuevo(70.0, "shampoo", "garnier");
	cProducto Nuevo2(250.0, "ibuprofeno", "actron");
	cProducto Nuevo3(120.0, "esmalte", "Sally Hansen");

	productosCarrito.push_back(Nuevo);
	productosCarrito.push_back(Nuevo2);
	productosCarrito.push_back(Nuevo3);
	productosCarrito.push_back(Nuevo3);


	//creo carrito
	cCarrito carritoCliente(productosCarrito, 300.0);
	
	//creo cliente 0
	string nombreCliente = "Guadalupe";
	string apellidoCliente = "Helou";
	string ndniCliente = "45671572";
	string contactoCliente = "11 2283-2778";
	double saldoDisp = 1000.0;
	double efectDisp = 3000.0;
	eNecesidad necesidad = farmacia;
	eMetodo metodo = mercadoPago;
	double saldoMp = 4000.0;
	cCliente miCliente(carritoCliente, nombreCliente, apellidoCliente, contactoCliente, metodo, saldoDisp, efectDisp, necesidad, ndniCliente, true, saldoMp);

	//creo cliente 1
	string nombreCliente1 = "Guadalupe";
	string apellidoCliente1 = "Helou";
	string ndniCliente1 = "45671572";
	string contactoCliente1 = "11 2283-2778";
	double saldoDisp1 = 100.0;
	double efectDisp1 = 50.0;
	eNecesidad necesidad1 = farmacia;
	eMetodo metodo1 = mercadoPago;
	double saldoMp1 = 3.0;
	cCliente miCliente1(carritoCliente, nombreCliente1, apellidoCliente1, contactoCliente1, metodo1, saldoDisp1, efectDisp1, necesidad1, ndniCliente1, true, saldoMp1);

	//creo empleado de caja
	string nombreEmp = "Roberto";
	string apellidoEmp = "Gomez";
	string ndniEmp = "356527";
	string contactoEmp = "11 2556-2998";
	double plataMiCaja = 15000;
	cEmpleadoCaja miEmpleado(nombreEmp, apellidoEmp, 72728, ndniEmp, contactoEmp, plataMiCaja);


	//implemento funcion cobrar
	
	
	cTicketdecompra ticketPrueba = miEmpleado.Cobrar(miCliente);
	try {
		cTicketdecompra ticket= miEmpleado.Cobrar(miCliente);
		cTicketdecompra ticket1=miEmpleado.Cobrar(miCliente1);
	}
	catch (exception *e)
	{
		cout << "EXCEPCION" << e->what() << endl;
		
	}
	//try {
	//	cTicketdecompra ticket = miEmpleado.Cobrar(miCliente);
	//	cTicketdecompra ticket1 = miEmpleado.Cobrar(miCliente1);
	//}
	//catch (exception* e1)
	//{
	//	cout << "EXCEPCION" << e1->what() << endl;

	//}

	//para chequear que funciona imprimo el ticket
	cout << "Compra exitosa:" << ticketPrueba.GET_COMPRA();
	cout << "\n Precio final: " << ticketPrueba.GET_PRECIOFINAL() << endl;

	vector<cProducto>productosTicket;
	productosTicket = ticketPrueba.GET_LISTAPRO();
	for (int i = 0; i < productosTicket.size(); i++)
	{
		cout << i+1 << "-" << productosTicket[i].Get_PRECIO()<<endl;
	}
	cFactura checkeo = miCliente.GET_FACTURA();
	cout << checkeo.GET_MONTO()<<endl;
	cout << checkeo.GET_NOMBRE() << endl;
	
} 