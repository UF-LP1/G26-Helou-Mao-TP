#include "funcionesMain.h"

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
	list <cOrtopedia>listaOrtopedia;
	cOrtopedia prod1(70.0, "vendas", "vendpro", vendas);
	cOrtopedia prod2(1000.0, "cabestrillo", "cabespro", cabestrillo);
	cOrtopedia prod3(600.0, "menequeras", "munepro", munequeras);
	cOrtopedia prod4(250.0, "medias", "DEMA", mediasCompresion);
	listaOrtopedia.push_back(prod1);
	listaOrtopedia.push_back(prod2);
	listaOrtopedia.push_back(prod3);
	listaOrtopedia.push_back(prod4);

	cEmpleadoOrtopedia empleadoOrt("Roberto", "Gomez", 72728, "5678909", "12345678910", listaOrtopedia);
	return empleadoOrt;
}
//creo empleado de perfumeria
cEmpleadosPerfumeria creacionEmpPerfumeria() {
	list <cPerfumeria> listaPerfumeria;
	cPerfumeria prod1(70.0, "shampoo", "garnier", shampoo);
	cPerfumeria prod2(80.0, "acondicionador", "garnier", cremaEnjuague);
	cPerfumeria prod3(600.0, "crema para el rostro", "eucerin", cremaCara);
	cPerfumeria prod4(50.0, "jabon", "dove", jabon);
	cPerfumeria prod5(100.0, "esmalte", "Sally Hansen", esmalte);
	cPerfumeria prod6(1000.5, "maquillaje", "chanel", maquillaje);
	cPerfumeria prod7(150.0, "cepillo de dientes", "colgate", cepilloDientes);
	cPerfumeria prod8(300.0, "algodon", "doncella", algodon);
	cPerfumeria prod9(200.0, "desodorante", "rexona", desodorante);
	cPerfumeria prod10(2000.0, "perfume", "calvin klein", perfume);
	listaPerfumeria.push_back(prod1);
	listaPerfumeria.push_back(prod2);
	listaPerfumeria.push_back(prod3);
	listaPerfumeria.push_back(prod4);
	listaPerfumeria.push_back(prod5);
	listaPerfumeria.push_back(prod6);
	listaPerfumeria.push_back(prod7);
	listaPerfumeria.push_back(prod8);
	listaPerfumeria.push_back(prod9);
	listaPerfumeria.push_back(prod10);

	cEmpleadosPerfumeria empleadoPerfumeria("Roberto", "Gomez", 72728, "5678909", "12345678910", listaPerfumeria);
	return empleadoPerfumeria;
}

void impresionChequeoQueAnda(cEmpleadoCaja empleadoCaja, cTicketdecompra ticket, cCliente miCliente0)
{
	cout << "\nCliente numero # " << miCliente0.GET_NUMEROCLIENTE() << endl;
	string estadoCompra = "";
	if (ticket.GET_COMPRA() == true)
		estadoCompra = "Compra exitosa";
	else
		estadoCompra = "Errores en la compra";
	cout << estadoCompra << endl;
	cout << "Precio final: " << ticket.GET_PRECIOFINAL() << endl;

	list<cProducto>productosTicket;
	productosTicket = ticket.GET_LISTAPRO();
	for (list<cProducto>::iterator it = productosTicket.begin(); it != productosTicket.end(); it++)
	{
		int i = 1;
		cout << i << "-" << it->Get_NOMBRE() << ": $" << it->Get_PRECIO() << endl;
		i++;
	}
	if (miCliente0.GET_METODO() == 0)
		cout << "Saldo final efectivo: $" << miCliente0.GET_EFECTIVO_DISPONIBLE() << endl;
	else if (miCliente0.GET_METODO() == 1)
		cout << "Saldo final tarjeta: $" << miCliente0.GET_SALDO_DISPONIBLE() << endl;
	else
		cout << "Saldo final mercado pago: $" << miCliente0.GET_SALDO_MP() << endl;
	cFactura checkeo = *miCliente0.GET_FACTURA();
	cout << checkeo.GET_MONTO() << endl;
	cout << checkeo.GET_NOMBRE() << endl;
	cout << checkeo.GET_NOMBRE() << endl;
	cout << "\nPlata actual en caja: $" << empleadoCaja.GET_PLATA() << endl;
	return;
}


cCliente atencionFarmaceutico(cCliente& clienteAux, cFarmaceutico farmaceutico)
{
	//mi cliente quiere ir a la farmacia
	farmaceutico.AtenderCliente(&clienteAux);
	clienteAux = farmaceutico.PasarClienteaCaja();
	return clienteAux;
}

cCliente atencionPerfumeria(cCliente clienteAux, cEmpleadosPerfumeria empleadoPerfumeria, unsigned int prodAllevar)
{
	//mi cliente quiere ir a perfumeria
	cPerfumeria productoPerf =empleadoPerfumeria.buscarProducto(prodAllevar);
	empleadoPerfumeria.AtenderCliente(&clienteAux, &productoPerf);
	clienteAux = empleadoPerfumeria.PasarClienteaCaja();
	return clienteAux;
}

cCliente atencionOrtopedia(cCliente clienteAux, cEmpleadoOrtopedia empleadoOrt,unsigned int prodAllevar)
{//mi cliente quiere ir a ortopedia
	cOrtopedia productoOrt = empleadoOrt.buscarProductoOrtopedia(prodAllevar);
	empleadoOrt.AtenderCliente(&clienteAux, productoOrt);
	clienteAux = empleadoOrt.PasarClienteaCaja();
	return clienteAux;
}

void imprimirProductosPerfumeria(cEmpleadosPerfumeria empleadoPerfumeria)
{
	int i = 0;
	list <cPerfumeria> listado=empleadoPerfumeria.GET_LISTADO();
	for (cPerfumeria& perf : listado)
	{
		i++;
		cout<< i<<": " << perf.Get_NOMBRE() << endl;
		
	}
	return;
}	//imprimo los productos de perfumeria para mostrarle las opciones al cliente
void imprimirProductosOrtopedia(cEmpleadoOrtopedia empleadoOrt)
{
	int i = 0;
	list <cOrtopedia> listado = empleadoOrt.GET_LISTADO_ORT();
	for (cOrtopedia& ort : listado)
	{
		i++; 
		cout << i << ": " << ort.Get_NOMBRE() << endl;
		
	}
	return;
}