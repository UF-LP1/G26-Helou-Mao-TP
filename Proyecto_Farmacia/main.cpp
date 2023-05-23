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

	//creo las golosinas
	list<cGolosinas> listaGolosinas = creacionGolosinas();
	//creo carrito
	cCarrito carritoCliente;
	cReceta receta("osde", "ibupirac", 2);

	//permito que el usuario cree el cliente
	string nombre = "";
	string apellido = "";
	string contacto = "maovalentina@mail";
	string DNI = "5463289";
	string metodoAux = "";
	int metodoInt = -1;
	string saldoAux = "0.0";
	int saldoParteEntera = 0;
	double saldoParteDecimal = 0.0;
	int decimalesCont = 0;
	bool decimal = false;
	double saldoDisponible = 0.0;
	cout << "Ingrese sus datos para registrarse" << endl;
	cout << "Nombre: " << endl;
	cin >> nombre;
	cout << "Apellido: " << endl;
	cin >> apellido;
	do {
		opcionesMetodo();
		cin >> metodoAux;
		if (metodoAux[0] >= '0' && metodoAux[0] <= '9')	//si metio un numero entonces lo transformo para mandarlo a atencion ortopedia
		{
			metodoInt = stoi(metodoAux);	//transformo el string a int
			metodoInt = metodoInt - 1;
		}
	} while (metodoInt < 0 || metodoInt>2);


	eMetodo metodo = casteoMetodo(metodoInt);

	do {
		cout << "Ingrese el saldo disponible del metodo de pago del cliente: " << endl;
		cin >> saldoAux;
		for (int i = 0; i < saldoAux.length(); i++)
		{
			if ((saldoAux[i] >= '0' && saldoAux[0] <= '9') || saldoAux[i] == '.')	//chequeo que ponga numeros o un . para separar en decimales
			{
				if (saldoAux[i] == '.')	//si encuentra el punto cambio disponibe a true para qu lo ar¿gregue a la partre decimal del numero
					decimal = true;

				else
				{
					if (!decimal)	//si continua en la parte entera (todavia no aparecio ningun un punto)
						saldoParteEntera = saldoParteEntera * 10 + (saldoAux[i] - '0');
					else
					{
						//encontro el punto
						saldoParteDecimal = saldoParteDecimal * 10 + (saldoAux[i] - '0');	//agrego a la parte decimal
						decimalesCont++;	//cuento la cantidad de numeros despues de la coma porque voy a tener que elevar la potencia de q10 esa cantidad de veces para correrlo la cantidad neecessaria					}
					}
				}
					
			}
		}

	} while (saldoParteEntera == 0);
	saldoDisponible = saldoParteEntera + saldoParteDecimal / pow(10,decimalesCont);	//dividimos en parte decimal y parte entera porque no se puede chequear que un double sea == 0.0
	
	int necesidadCliente = -1;
	string necesidadAux = " ";
	//le doy al cliente las opciones de sectores donde comprar
	do {
		imprimirNecesidad();
		cin >> necesidadAux;
		if (necesidadAux[0] >= '0' && necesidadAux[0] <= '9')	//chequeo que meta numeros
		{
			necesidadCliente = stoi(necesidadAux);
			necesidadCliente = necesidadCliente - 1;
		}
		
	} while (necesidadCliente > 2 || necesidadCliente < 0);//para asegurarme que ingresa un numero valido

	cCliente miCliente0(carritoCliente, nombre, apellido, contacto, metodo, saldoDisponible, DNI, false);
	//creo cliente
	if (necesidadCliente == 0)
		miCliente0.SET_RECETA(receta);

	//clientes llegan al local
	miLocal.agregarCliente(miCliente0);

	//local me pasa a mostrador el primer cliente a ser atendiido
	cCliente clienteAux = miLocal.PasarClienteMostrador();
	empleadoMostrador.agregarCliente(&clienteAux);	//agrego al cliente al registro del empleado de mostrador

	//empleado mostrador me pasa el proximo empleado 

	string imprimir = "";
	clienteAux = empleadoMostrador.EnviarClienteOtroEmp();
	unsigned int prodAllevar = 0;
	bool deseaContinuar = true;
	string input;

	if (necesidadCliente == 0) //mi cliente quiere ir a la farmacia
	{
		clienteAux = atencionFarmaceutico(clienteAux, farmaceutico);

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
			} while ((prodAllevar == 0 || prodAllevar > 4) && input != "Listo");
			if (input != "Listo")
				clienteAux = atencionOrtopedia(clienteAux, empleadoOrt, prodAllevar);
		} while (input != "Listo");
	}

	int golosinas = -1;
	string golosinasAux = "";
	do {
		cout << "Si desea ingresar alguna golosina ingrese 1, si no lo desea ingrese 2 " << endl;
		cin >> golosinasAux;
		if (golosinasAux[0] >= '0' && golosinasAux[0] <= '9')	//cheque que meta numeros
		{
			golosinas = stoi(golosinasAux);
		}
	} while (golosinas != 1 && golosinas != 2);
	int golosinaDeseada = 0;
	if (golosinas == 1)
	{
		cout << "\nIngrese Listo cuando desee finalizar la compra" << endl;
		imprimirGolosinas(listaGolosinas);
		do
		{

			do
			{
				cout << "Elija el producto que desea llevar (numero del 1 al 4):" << endl;
				cin >> input;
				golosinaDeseada = 0;	//lo reseto para que no lo guarde en caso de que no ponga numeros ni listo
				if (input[0] >= '0' && input[0] <= '9')	//si metio un numero valido entonces lo transformo para mandarlo a atencion ortopedia
					prodAllevar = stoi(input);	//transformo el string a int
			} while ((prodAllevar == 0 || prodAllevar > 4) && input != "Listo");	//metio un dato invalido (basura)
			if (input != "Listo")	//si pidio un producto lo agrego al carrito
			{//si desea eliminar algun producto ingrese el numero del producto, si quiere continuar ingrese 0
				clienteAux.AgregarGolosinas(prodAllevar, listaGolosinas);
			}
		} while (input != "Listo");	//terminamos el loop, no quiere mas productos

	}
	int eliminar = 0;
	string eliminarAux = "";
	int prodEliminar = 0;
	do {
		cout << "Si desea eliminar algun producto ingrese 1, si no lo desea ingrese 2 " << endl;
		cin >> eliminarAux;
		if (eliminarAux[0] >= '0' && eliminarAux[0] <= '9')	//cehqueo que met numeros
		{
			eliminar = stoi(eliminarAux);
		}
	} while (eliminar != 1 && eliminar != 2);

	if (eliminar == 1)
	{

		do
		{
			do
			{
				cout << "\nIngrese Listo cuando desee proseguir con la compra" << endl;
				imprimirCarrito(clienteAux);
				cout << "Elija el producto que desea eliminar:" << endl;
				cin >> input;
				prodEliminar = 0;	//lo reseto para que no lo guarde en caso de que no ponga numeros ni listo
				if (input[0] >= '0' && input[0] <= '9')	//si metio un numero valido entonces lo transformo para mandarlo a atencion ortopedia
					prodEliminar = stoi(input);	//transformo el string a int
			} while ((prodEliminar == 0 || prodEliminar > 4) && input != "Listo");	//metio un dato invalido (basura)
			if (input != "Listo")	//si pidio un producto lo agrego al carrito
			{//si desea eliminar algun producto ingrese el numero del producto, si quiere continuar ingrese 0
				clienteAux.GET_CARRITO()->EliminarProductos(prodEliminar);
			}
		} while (input != "Listo");	//terminamos el loop, no quiere mas productos
	}

	//paso cliente aux al empleado de caja para que pueda cobrar
	empleadoCaja.AtenderCliente(&clienteAux);

	//implemento funcion cobrar

	cTicketdecompra ticket1;
	try {
		ticket1 = empleadoCaja.Cobrar(&miCliente0);

	}
	catch (exception* e)
	{
		cout << "EXCEPCION" << e->what() << endl;

	}
	miLocal.AgregarTicketCompra(ticket1);
	impresionChequeoQueAnda(empleadoCaja, ticket1, miCliente0);
	return 0;
}

