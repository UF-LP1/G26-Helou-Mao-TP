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
	cCliente miCliente0(carritoCliente, "Guadalupe", "Helou", "11 2283-2778", efectivo, 1000.0, 3000.0, "45671572", true, 4000.0, receta);

	//clientes llegan al local
	miLocal.agregarCliente(miCliente0);

	
	//local me pasa a mostrador el primer cliente a ser atendiido
	cCliente clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado 
	int necesidadCliente = 0;
	string imprimir = "";
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	unsigned int prodAllevar = 0;
	bool deseaContinuar=true;
	string input;
	//le doy al cliente las opciones de sectores donde comprar
	do {
		imprimirNecesidad();
		cin >> necesidadCliente;
		necesidadCliente = necesidadCliente - 1;
	} while (necesidadCliente > 2|| necesidadCliente<0);//para asegurarme que ingresa un numero valido


	if (necesidadCliente == 0) //mi cliente quiere ir a la farmacia
	{
		clienteAux = atencionFarmaceutico( clienteAux,  farmaceutico);
	
	}
	else if (necesidadCliente == 1)//mi cliente quiere ir a perfumeria
	{
		imprimir = empleadoPerfumeria.Asesorar();//imprimo para cumplir con la consigna
		cout << imprimir << endl;
	
		cout << "\nIngrese 'Listo' cuando desee finalizar la compra" << endl;
		imprimirProductosPerfumeria(empleadoPerfumeria);//le ofrezco al cliente los productos disponibles
		do
		{
			do 
			{
				cout << "Elija el producto que desea llevar (numero del 1 al 10):" << endl;
				cin >> input;
				prodAllevar = 0;	//lo reseto para que no lo guarde en caso de que no ponga numeros ni listo
				if (input[0] >= '0' && input[0] <= '9')	//si metio un numero valido entonces lo transformo para mandarlo a atencion ortopedia
					prodAllevar = stoi(input);	//transformo el string a int
			} while ((prodAllevar == 0 || prodAllevar > 10) && input != "Listo");	//metio un dato invalido (basura)
			if (input != "Listo")	//si pidio un producto lo agrego al carrito

				//si desea eliminar algun producto ingrese el numero del producto, si quiere continuar ingrese 0
				clienteAux = atencionPerfumeria(clienteAux, empleadoPerfumeria, prodAllevar);
		} while (input != "Listo");	//terminamos el loop, no quiere mas productos
	}
	else if (necesidadCliente == 2)//mi cliente quiere ir a ortopedia
	{
		//imprimo para cumplir con la consigna
		imprimir = empleadoOrt.Asesorar();
		cout << imprimir << endl;
		imprimir = empleadoOrt.RecomendarProductos();
		cout << imprimir << endl;

		cout << "\nIngrese Listo cuando desee finalizar la compra" << endl;
		imprimirProductosOrtopedia(empleadoOrt);//le ofreco al cliente los prodctos disponibles
		
		do
		{	
			do {
				cout << "Elija el producto que desea llevar (numero del 1 al 4):" << endl;
				cin >> input;
				prodAllevar = 0;	//lo reseto para que no lo guarde en caso de que no ponga numeros ni listo
				if (input[0] >= '0' && input[0] <= '9')	//si metio un numero entonces lo transformo para mandarlo a atencion ortopedia
					prodAllevar = stoi(input);
			} while ((prodAllevar == 0 || prodAllevar > 4) && input!="Listo");
			if (input != "Listo")
				clienteAux = atencionOrtopedia(clienteAux, empleadoOrt, prodAllevar);
		} while (input != "Listo");
	}

	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);
	//implemento funcion cobrar

	cTicketdecompra ticket1;
	try {
		ticket1= empleadoCaja.Cobrar(&miCliente0);

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}
	miLocal.AgregarTicketCompra(ticket1);
	impresionChequeoQueAnda(empleadoCaja, ticket1, miCliente0);
	return 0;
} 

