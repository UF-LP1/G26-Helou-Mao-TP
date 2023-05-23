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
	cout << "\nCliente numero # " << miCliente0.GET_NUMEROCLIENTE() << endl;//imprimo el numero de cliente
	string estadoCompra = "";
	if (ticket.GET_COMPRA() == true)//si la compra anduvo pongo que fue exitosa
		estadoCompra = "Compra exitosa";
	else
		estadoCompra = "Errores en la compra";//si algo salio mal durante la compra imprimo que fue fallida
	cout << estadoCompra << endl;
	cout << "Precio final: " << ticket.GET_PRECIOFINAL() << endl;//imprimo el precio final de la compra

	list<cProducto>productosTicket;
	int i = 1;
	productosTicket = ticket.GET_LISTAPRO();
	for (list<cProducto>::iterator it = productosTicket.begin(); it != productosTicket.end(); it++)//recorro la lista de productos que se llevo el cliente
	{
		cout << i << "-" << it->Get_NOMBRE() << ": $" << it->Get_PRECIO() << endl;//imprimo nombre y precio de cada producto
		i++;
	}
	//chequeo como pago mi cliente e imprimo el saldo actual 

	cout << "Saldo final : $" << miCliente0.GET_SALDO_DISPONIBLE() << endl;
	//copio la factura del cliente para imprimie algunos datos tambien
	cFactura facturaCheckeo = *miCliente0.GET_FACTURA();
	cout << "\nFACTURA:" << endl;
	cout << "Monto: "<<facturaCheckeo.GET_MONTO() << endl;
	cout <<"Nombre cliente: " << facturaCheckeo.GET_NOMBRE() << endl;
	cout <<"Apellido cliente: " << facturaCheckeo.GET_APELLIDO() << endl;
	cout << "\nPlata actual en caja (local): $" << empleadoCaja.GET_PLATA() << endl;
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
void imprimirNecesidad()
{
	cout << "Elija su necesidad:" << endl;
	cout << "1: Farmacia" << endl;
	cout << "2: Perfumeria" << endl;
	cout << "3: Ortopedia" << endl;
}
void opcionesMetodo()
{
	cout << "Ingrese el metodo pago del cliente: " << endl;
	cout << "1: Efectivo" << endl;
	cout << "2: Tarjeta" << endl;
	cout << "3: Mercado pago" << endl;
}
eMetodo catsteoMetodo(int metodoAux)
{
	eMetodo metodo;
	switch (metodoAux)
	{
	case 0:
		metodo = efectivo;
		break;
	case 1:
		metodo = tarjeta;
		break;
	case 2:
		metodo = mercadoPago;
		break;
	}
	return metodo;
}
list<cGolosinas> creacionGolosinas()//caramelos, chicles, chupetin, chocolate
{
	list <cGolosinas>listaGolosinas;
	cGolosinas prod1(70.0, "caramelos", "billiken", caramelos);
	cGolosinas prod2(1000.0, "chicles", "beldent", chicles);
	cGolosinas prod3(600.0, "chupetin", "pico dulce", chupetin);
	cGolosinas prod4(250.0, "chocolate", "tobleron", chocolate);
	listaGolosinas.push_back(prod1);
	listaGolosinas.push_back(prod2);
	listaGolosinas.push_back(prod3);
	listaGolosinas.push_back(prod4);
	return listaGolosinas;
}
void imprimirGolosinas(list<cGolosinas>listaGolosinas)
{
	int i = 0;
	for (cGolosinas& gols : listaGolosinas)
	{
		i++;
		cout << i << ": " << gols.Get_NOMBRE() << endl;
	}
	return;

}
void imprimirCarrito(cCliente miCliente0)
{
	list<cProducto> listaProds= miCliente0.GET_CARRITO()->GET_LISTAPRODUCTOS();
	int i = 0;
	for (cProducto& prods : listaProds)
	{
		i++;
		cout << i << ": " << prods.Get_NOMBRE() << endl;
	}
	return;
}