/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, double efectivoDisponible, string dni, bool facturaFisica, double MP,cReceta receta) :DNI(dni)
{
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->efectivodisponible = efectivoDisponible;
    this->facturaFisica = facturaFisica;
    this->saldoMPago = MP;
    this->numeroClientes = cantClientes;
    this->miReceta = receta;
    cantClientes++; 
}

//constructor cuando mi cliente no tiene receta
cCliente::cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, double efectivoDisponible,string dni, bool facturaFisica, double MP) :DNI(dni)
{
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->efectivodisponible = efectivoDisponible;
    this->facturaFisica = facturaFisica;
    this->saldoMPago = MP;
    this->numeroClientes = cantClientes;
    cantClientes++;
}
//constructor cuando mi cliente no tiene carrito ni receta
cCliente::cCliente( string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, double efectivoDisponible,  string dni, bool facturaFisica, double MP) :DNI(dni)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->efectivodisponible = efectivoDisponible;
    this->facturaFisica = facturaFisica;
    this->saldoMPago = MP;
    this->numeroClientes = cantClientes;
    cantClientes++;
}



cCliente::~cCliente() 
{

}
bool cCliente:: GET_FORMATO()
{
    return this->facturaFisica;
}
string cCliente::GET_DNI() {
    return this->DNI;
}
eMetodo cCliente::GET_METODO()
{
    return this->metodoPago;
}
//devuelve el carrito como puntero asi podemos modificarlo
cCarrito* cCliente::GET_CARRITO() {
    
    return &miCarrito;
}
void cCliente::AgregarProductosPerfumeria(cPerfumeria *prodPerfumeria, int cantidad)     //agrego a mi carrito los productos de perfumeria
{
    //hago un for que se repite igual de cantidad de veces como productos quiero agregar
    for (int i = 0; i < cantidad; i++)
    {
        miCarrito.SET_PRODUCTO(prodPerfumeria);
    }
    return;
}

void cCliente::AgregarGolosinas(cGolosinas *golosinas, int cantidad) {    //voy agregando golosinas al carrito
   
    //hago un for que se repite igual de cantidad de veces como productos quiero agregar
    for (int i = 0; i < cantidad; i++)
    {
        miCarrito.SET_PRODUCTO(golosinas);
    }
    return;
}
string cCliente::GET_NOMBRE()
{
    return this->nombre;
}
string cCliente::GET_APELLIDO()
{
    return this->apellido;
}
void cCliente::SET_FACTURA(cFactura nuevaFactura)
{
    this->miFactura=nuevaFactura;
}
double cCliente::GET_SALDO_DISPONIBLE()
{
    return this->saldoDisponible;
}
double cCliente::GET_EFECTIVO_DISPONIBLE()
{
    return this->efectivodisponible;
}
double cCliente::GET_SALDO_MP()
{
    return this->saldoMPago;
}
cFactura* cCliente ::GET_FACTURA()
{
    return &miFactura;
}
int cCliente:: GET_NUMEROCLIENTE()
{
    return numeroClientes;
}

void cCliente::SET_MP(double* saldoMP)
{
    this->saldoMPago = *saldoMP;
}
void cCliente::SET_SALDO(double *saldoDisponible)
{
    this->saldoDisponible = *saldoDisponible;
}
void cCliente:: SET_EFECTIVO(double *efectivoDisponible)
{
    this->efectivodisponible = *efectivoDisponible;
}
cReceta cCliente::GET_RECETA()
{
    return this->miReceta;
}
cCliente& cCliente::operator=(const cCliente& cliente)  //lo hacemos para poder usarlo en el main para probar las funciones
{
    if (&cliente != this)
    {
        nombre = cliente.nombre;
        apellido = cliente.apellido;
        numeroClientes = cliente.numeroClientes;
        miFactura = cliente.miFactura;
        miCarrito = cliente.miCarrito;
        contacto = cliente.contacto;
        metodoPago = cliente.metodoPago;
        saldoDisponible = cliente.saldoDisponible;
        efectivodisponible = cliente.efectivodisponible;
        //DNI = cliente.DNI;
        saldoMPago = cliente.saldoMPago;
        miReceta = cliente.miReceta;
    }
    return *this;
}

void cCliente::pagar(double montoTotal) //va a descontar de la billetera del cliente la plata que gasto
{
    //al cliente que esta en mi vector le resto lo que le cobre
    switch (this->metodoPago)
    {
    case 0: //si pago en efectivo
        this->efectivodisponible= (this->efectivodisponible- montoTotal);
        break;
    case 1: //si pago con tarjeta
        this->saldoDisponible = (this->saldoDisponible - montoTotal);
        break;
    case 2: //si pago con mp
        this->saldoMPago = (this->saldoMPago - montoTotal);
        break;
    default:
        throw new exception("Mal registrado el metodo de pago");    //imposible que entre aca, pero por las dudas chequeo este error
    }
}