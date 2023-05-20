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
int cCliente::cantClientes = 1;

using namespace std;
int main()
{
	//creo el local
	cLocal miLocal("Feriliffa", "Corrientes Y Callao", "21356776", 200000.0);
	//creacion de empleados
	cEmpleadoCaja empleadoCaja = creacionEmpleadoCaja();
	cEmpleadoMostrador empleadoMostrador = creacionEmpMostrador();
	cFarmaceutico farmaceutico = creacionFarmaceutico();
	cEmpleadosPerfumeria empleadoPerfumeria = creacionEmpPerfumeria();
	cEmpleadoOrtopedia empleadoOrt = creacionEmpOrto();

	list<cFactura> facturaPrueba;

	//creo los productos que se van a llevar los clientes
	cPerfumeria productoPerf(70.0, "shampoo", "garnier", cremaEnjuague);
	cOrtopedia productoOrt(250.0, "medias", "DEMA", mediasCompresion);
	cGolosinas golosinas(120.0, "conChicle", "popstar", chupetin);

	//creo carrito
	cCarrito carritoCliente;
	cReceta receta("osde", "ibupirac", 2);

	//creo clientes
	cCliente miCliente0(carritoCliente, "Guadaalupe", "Helou", "11 2283-2778", mercadoPago, 1000.0, 3000.0, farmacia, "45671572", true, 4000.0, receta);
	cCliente miCliente1(carritoCliente, "Valentina", "Mao", "maovalentina@mail", efectivo, 100.0, 50.0, perfumeria, "45783437", true, 3.0);
	cCliente miCliente2(carritoCliente, "Guadaalupe", "Helou", "11 2283-2778", tarjeta, 1000.0, 3000.0, ortopedia, "45671572", true, 4000.0);
	cCliente miCliente3(carritoCliente, "Valentina", "Mao", "maovalentina@mail", efectivo, 100.0, 100, perfumeria, "45783437", true, 3.0);
	//clientes llegan al local
	miLocal.agregarCliente(miCliente0);
	miLocal.agregarCliente(miCliente1);
	miLocal.agregarCliente(miCliente2);
	miLocal.agregarCliente(miCliente3);
	//local me pasa a mostrador el primer cliente a ser atendiido
	cCliente clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado y donde mandarlo
	int necesidadCliente = empleadoMostrador.aDondeVaCliente();
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	if (necesidadCliente == 0)
	{
		//mi cliente quiere ir a la farmacia
		farmaceutico.AtenderCliente(&clienteAux);
		clienteAux = farmaceutico.PasarClienteaCaja();
	}
	else if (necesidadCliente == 1)
	{
		//mi cliente quiere ir a perfumeria
		empleadoPerfumeria.AtenderCliente(&clienteAux,&productoPerf);
		clienteAux = empleadoPerfumeria.PasarClienteaCaja();
	}
	else if (necesidadCliente == 2)
	{
		//mi cliente quiere ir a ortopedia
		empleadoOrt.AtenderCliente(&clienteAux, &productoOrt);
		clienteAux = empleadoOrt.PasarClienteaCaja();
	}
		//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	cTicketdecompra ticket;
	try {
		ticket = empleadoCaja.Cobrar();

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}

				//termina de atender el primer cliente, pasa al segundo
	clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado y donde mandarlo
	necesidadCliente = empleadoMostrador.aDondeVaCliente();
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	if (necesidadCliente == 0)
	{
		//mi cliente quiere ir a la farmacia
		farmaceutico.AtenderCliente(&clienteAux);
		clienteAux = farmaceutico.PasarClienteaCaja();
	}
	else if (necesidadCliente == 1)
	{
		//mi cliente quiere ir a perfumeria
		empleadoPerfumeria.AtenderCliente(&clienteAux, &productoPerf);
		clienteAux = empleadoPerfumeria.PasarClienteaCaja();
	}
	else if (necesidadCliente == 2)
	{
		//mi cliente quiere ir a ortopedia
		empleadoOrt.AtenderCliente(&clienteAux, &productoOrt);
		clienteAux = empleadoOrt.PasarClienteaCaja();
	}
	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	//implemento funcion cobrar

	cTicketdecompra ticket1;
	try {
		ticket1= empleadoCaja.Cobrar();

	}
	catch (exception *e)
	{
		cout << "EXCEPCION" << e->what() << endl;
		
	}
	
				//siguiente cliente
	clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado y donde mandarlo
	necesidadCliente = empleadoMostrador.aDondeVaCliente();
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	if (necesidadCliente == 0)
	{
		//mi cliente quiere ir a la farmacia
		farmaceutico.AtenderCliente(&clienteAux);
		clienteAux = farmaceutico.PasarClienteaCaja();
	}
	else if (necesidadCliente == 1)
	{
		//mi cliente quiere ir a perfumeria
		empleadoPerfumeria.AtenderCliente(&clienteAux, &productoPerf);
		clienteAux = empleadoPerfumeria.PasarClienteaCaja();
	}
	else if (necesidadCliente == 2)
	{
		//mi cliente quiere ir a ortopedia
		empleadoOrt.AtenderCliente(&clienteAux, &productoOrt);
		clienteAux = empleadoOrt.PasarClienteaCaja();
	}
	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	//implemento funcion cobrar

	cTicketdecompra ticket2;
	try {
		ticket2 = empleadoCaja.Cobrar();

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}
				//siguiente cliente
	clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado y donde mandarlo
	necesidadCliente = empleadoMostrador.aDondeVaCliente();
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	if (necesidadCliente == 0)
	{
		//mi cliente quiere ir a la farmacia
		farmaceutico.AtenderCliente(&clienteAux);
		clienteAux = farmaceutico.PasarClienteaCaja();
	}
	else if (necesidadCliente == 1)
	{
		//mi cliente quiere ir a perfumeria
		empleadoPerfumeria.AtenderCliente(&clienteAux, &productoPerf);
		clienteAux = empleadoPerfumeria.PasarClienteaCaja();
	}
	else if (necesidadCliente == 2)
	{
		//mi cliente quiere ir a ortopedia
		empleadoOrt.AtenderCliente(&clienteAux, &productoOrt);
		clienteAux = empleadoOrt.PasarClienteaCaja();
	}
	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	//implemento funcion cobrar

	cTicketdecompra ticket3;
	try {
		ticket3 = empleadoCaja.Cobrar();

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}

	impresionChequeoQueAnda(empleadoCaja, ticket, miCliente0);
	impresionChequeoQueAnda(empleadoCaja, ticket1, miCliente1);
	impresionChequeoQueAnda(empleadoCaja, ticket2, miCliente2);
	impresionChequeoQueAnda(empleadoCaja, ticket3, miCliente3);
} 

cFarmaceutico creacionFarmaceutico()
{
	//creo listas y variables que necesito para farmaceutico
	list<cMedicamento>medicamentosFarmaceutico;
	cMedicamento medicamento1(700.0, "ibupirac", "actron", 3, false);
	cMedicamento medicamento2(1000.0, "descongestivo", "refenex", 10, true);
	medicamentosFarmaceutico.push_back(medicamento1);
	medicamentosFarmaceutico.push_back(medicamento2);
	list<cDescuento>descuentosFarmaceutico;
	cDescuento descuento1(20.0, "osde");
	cDescuento descuento2(5.0, "medife");
	descuentosFarmaceutico.push_back(descuento1);
	descuentosFarmaceutico.push_back(descuento2);
	//creo empleado de farmacia
	cFarmaceutico farmaceutico(descuentosFarmaceutico, medicamentosFarmaceutico, "Roberto", "Gomez", 72728, "5678909", "12345678910");
	return farmaceutico;
}
//creo empleado de caja
cEmpleadoCaja creacionEmpleadoCaja() {
	cEmpleadoCaja empleadoCaja("Roberto", "Gomez", 72728, "5678909", "12345678910", 15000.0);
	return empleadoCaja;
}

//creo empleado de mostrador
cEmpleadoMostrador creacionEmpMostrador() {
	cEmpleadoMostrador empleadoMostrador("Roberto", "Gomez", 72728, "5678909", "12345678910", 0);
	return empleadoMostrador;
}
//creo empleado ortopedia
cEmpleadoOrtopedia creacionEmpOrto() {
	cEmpleadoOrtopedia empleadoOrt("Roberto", "Gomez", 72728, "5678909", "12345678910");
	return empleadoOrt;
}
//creo empleado de perfumeria
cEmpleadosPerfumeria creacionEmpPerfumeria() {
	cEmpleadosPerfumeria empleadoPerfumeria("Roberto", "Gomez", 72728, "5678909", "12345678910");
	return empleadoPerfumeria;
}

void impresionChequeoQueAnda(cEmpleadoCaja empleadoCaja,cTicketdecompra ticket, cCliente miCliente0)
{
	cout << "\nCliente numero # " << miCliente0.GET_NUMEROCLIENTE()<<endl;
	string estadoCompra = "";
	if (ticket.GET_COMPRA() == true)
		estadoCompra = "Compra exitosa";
	else
		estadoCompra = "Errores en la compra";
	cout << estadoCompra<< endl;
	cout << "Precio final: " << ticket.GET_PRECIOFINAL() << endl;

	list<cProducto>productosTicket;
	productosTicket = ticket.GET_LISTAPRO();
	for (list<cProducto>::iterator it=productosTicket.begin(); it != productosTicket.end();it++)
	{
		int i = 1;
		cout <<i << "-" << it->Get_NOMBRE() << ": $" << it->Get_PRECIO() << endl;
		i++;
	}
	if(miCliente0.GET_METODO() == 0)
		cout << miCliente0.GET_EFECTIVO_DISPONIBLE() << endl;
	else if(miCliente0.GET_METODO() == 1)
		cout << "Saldo metodo de pago: $"<<miCliente0.GET_SALDO_DISPONIBLE() << endl;
	else
		cout << miCliente0.GET_SALDO_MP() << endl;
	cFactura checkeo = *miCliente0.GET_FACTURA();
	cout << checkeo.GET_MONTO() << endl;
	cout << checkeo.GET_NOMBRE() << endl;
	cout << checkeo.GET_NOMBRE() << endl;
	cout << "\nPlata actual en caja: $"<<empleadoCaja.GET_PLATA() << endl;
	return;
}