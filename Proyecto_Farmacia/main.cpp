#include "Headers.h"
#include "cEmpleadoMostrador.h"
#include "cTicketdecompra.h"
#include "cLocal.h"
int cCliente::cantClientes = 1;

using namespace std;
int main()
{
	vector<cFactura> facturaPrueba;

		//creo los productos que se van a llevar los clientes
	cPerfumeria productoPerf(70.0, "shampoo", "garnier", cremaEnjuague);
	cOrtopedia productoOrt(250.0, "ibuprofeno", "actron", mediasCompresion);
	cGolosinas golosinas(120.0, "esmalte", "Sally Hansen", chupetin);

		//creo carrito
	cCarrito carritoCliente;
	cReceta receta("osde", "ibupirac", 2);

		//creo cliente 0
	cCliente miCliente0(carritoCliente, "Guadaalupe", "Helou", "11 2283-2778", mercadoPago, 1000.0, 3000.0, farmacia, "45671572", true, 4000.0, receta);

		//creo cliente 1
	cCliente miCliente1(carritoCliente, "Valentina", "Mao", "maovalentina@mail", mercadoPago, 100.0, 50.0, perfumeria, "45783437", true, 3.0);

		//creo empleado de caja
	cEmpleadoCaja empleadoCaja("Roberto", "Gomez", 72728, "5678909", "12345678910", 15000.0);

		//creo empleado de perfumeria
	cEmpleadosPerfumeria empleadoPerfumeria("Roberto", "Gomez", 72728, "5678909", "12345678910");

	//creo empleado de mostrador
	cEmpleadoMostrador empleadoMostrador("Roberto", "Gomez", 72728, "5678909", "12345678910",0);

		//creo vectores y variables que necesito para farmaceutico
	vector<cMedicamento>medicamentosFarmaceutico;
	cMedicamento medicamento1(700.0,"ibupirac","actron",3,false);
	cMedicamento medicamento2(1000.0, "descongestivo", "refenex", 10, true);
	medicamentosFarmaceutico.push_back(medicamento1);
	medicamentosFarmaceutico.push_back(medicamento2);
	vector<cDescuento>descuentosFarmaceutico;
	cDescuento descuento1(20.0, "osde");
	cDescuento descuento2(5.0, "medife");
	descuentosFarmaceutico.push_back(descuento1);
	descuentosFarmaceutico.push_back(descuento2);

		//creo empleado de farmacia
	cFarmaceutico empleadoFarmacia(descuentosFarmaceutico, medicamentosFarmaceutico, "Roberto", "Gomez", 72728, "5678909", "12345678910");

		//creo el local
	cLocal miLocal("farmaciaViernes", "corrientesYCallao", "21356776", 200000.0);

		//clientes llegan al local
	miLocal.agregarCliente(miCliente0);
	miLocal.agregarCliente(miCliente1);

		//local me pasa a mostrador el primer cliente a ser atendiido
	cCliente clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(clienteAux);

		//empleado mostrador me pasa el proximo empleado y donde mandarlo
	cCliente clienteAux2 = (cCliente)empleadoMostrador.EnviarClienteOtroEmp();
	int necesidadCliente = empleadoMostrador.aDondeVaCliente();
	if (necesidadCliente == 0)
	{
		//mi cliente quiere ir a la farmacia
		empleadoFarmacia.AtenderCliente(clienteAux2);
		cCliente clienteAux3 = empleadoFarmacia.PasarClienteaCaja();
	}
	else if (necesidadCliente == 1)
	{
		//mi cliente quiere ir a perfumeria
	}
		//implemento funcion cobrar
	cTicketdecompra ticketPrueba = empleadoCaja.Cobrar();
	try {
		cTicketdecompra ticket= empleadoCaja.Cobrar();
		cTicketdecompra ticket1=empleadoCaja.Cobrar();
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
	cFactura checkeo = miCliente0.GET_FACTURA();
	cout << checkeo.GET_MONTO()<<endl;
	cout << checkeo.GET_NOMBRE() << endl;
	
} 