/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, double efectivoDisponible, eNecesidad necesidad, string dni, bool facturaFisica, double MP) :DNI(dni)
{
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->efectivodisponible = efectivoDisponible;
    this->necesidad = necesidad;
    this->facturaFisica = facturaFisica;
    this->saldoMPago = MP;
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

cCarrito* cCliente::GET_CARRITO() {
    
    return &miCarrito;
}

void cCliente::AgregarProductosPerfumeria(cPerfumeria prodPerfumeria, int cantidad) {
    for (int i = 0; i < cantidad; i++)
    {
        miCarrito.SET_PRODUCTO(prodPerfumeria);
    }
    return;
}

void cCliente::AgregarGolosinas(cGolosinas golosinas, int cantidad) {    //voy agregando golosinas al carrito
   
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
cFactura cCliente ::GET_FACTURA()
{
    return this->miFactura;
}
int cCliente:: GET_NUMEROCLIENTE()
{
    return numeroCliente;
}