#include "funcionesMain.h"

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

	//creo carrito
	cCarrito carritoCliente;
	cReceta receta("osde", "ibupirac", 2);

	//creo clientes
	cCliente miCliente0(carritoCliente, "Guadaalupe", "Helou", "11 2283-2778", efectivo, 1000.0, 3000.0, farmacia, "45671572", true, 4000.0, receta);

	//clientes llegan al local
	miLocal.agregarCliente(miCliente0);

	
	//local me pasa a mostrador el primer cliente a ser atendiido
	cCliente clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado y donde mandarlo
	int necesidadCliente = empleadoMostrador.aDondeVaCliente();
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	unsigned int prodAllevar = 0;
	
	if (necesidadCliente == 0) //mi cliente quiere ir a la farmacia
	{
		clienteAux = atencionFarmaceutico( clienteAux,  farmaceutico);
	
	}
	else if (necesidadCliente == 1)	//mi cliente quiere ir a perfumeria
	{
		imprimirProductosPerfumeria(empleadoPerfumeria);//le ofreco al cliente los prodctos disponibles
		do
		{
			cout << "Elija el producto que desea llevar (numero del 1 al 10):" << endl;
			cin >> prodAllevar;

		} while (prodAllevar == 0 || prodAllevar > 10);
		atencionPerfumeria(clienteAux, empleadoPerfumeria, prodAllevar);

	}
		
	else if (necesidadCliente == 2)//mi cliente quiere ir a ortopedia
	{
		imprimirProductosOrtopedia(empleadoOrt);//le ofreco al cliente los prodctos disponibles
		do {
			cout << "Elija el producto que desea llevar (numero del 1 al 4):" << endl;
			cin >> prodAllevar;
		} while (prodAllevar == 0 || prodAllevar > 4);
		atencionOrtopedia(clienteAux, empleadoOrt, prodAllevar);
	}
	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	//implemento funcion cobrar

	cTicketdecompra ticket1;
	try {
		ticket1= empleadoCaja.Cobrar();

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}

	impresionChequeoQueAnda(empleadoCaja, ticket1, miCliente0);
	return 0;
} 

