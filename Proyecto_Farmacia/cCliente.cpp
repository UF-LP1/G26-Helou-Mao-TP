/**
 * Project Untitled
 */


#include "cCliente.h"



cCliente::cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, string dni, bool facturaFisica,cReceta receta) :DNI(dni)
{
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->facturaFisica = facturaFisica;
    this->numeroClientes = cantClientes;
    this->miReceta = receta;
    cantClientes++; 
}

//constructor cuando mi cliente no tiene receta
cCliente::cCliente(cCarrito _miCarrito, string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, string dni, bool facturaFisica) :DNI(dni)
{
    this->miCarrito = _miCarrito;
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->facturaFisica = facturaFisica;
    this->numeroClientes = cantClientes;
    cantClientes++;
}
//constructor cuando mi cliente no tiene carrito ni receta
cCliente::cCliente (string nombre, string apellido, string contacto, eMetodo metodoPago, double saldoDisponible, const string dni, bool facturaFisica)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->contacto = contacto;
    this->metodoPago = metodoPago;
    this->saldoDisponible = saldoDisponible;
    this->facturaFisica = facturaFisica;
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

void cCliente::AgregarGolosinas( int prodAllevar, list<cGolosinas>listaGolosinas) {    //voy agregando golosinas al carrito
   
    prodAllevar = prodAllevar - 1; //resto uno porque el cliente elije a partir del uno y yo tengo productos a partir del 0
    for (cGolosinas& gols : listaGolosinas)
    {
        if (prodAllevar == gols.GET_TIPO())
        {
            GET_CARRITO()->SET_PRODUCTO(&gols);
            return;
        }
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

cFactura* cCliente ::GET_FACTURA()
{
    return &miFactura;
}
int cCliente:: GET_NUMEROCLIENTE()
{
    return numeroClientes;
}

void cCliente::SET_SALDO(double *saldoDisponible)
{
    this->saldoDisponible = *saldoDisponible;
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
        //DNI = cliente.DNI;
        miReceta = cliente.miReceta;
    }
    return *this;
}

void cCliente::pagar(double montoTotal) //va a descontar de la billetera del cliente la plata que gasto
{
    //al cliente que esta en mi vector le resto lo que le cobre
  
        this->saldoDisponible = (this->saldoDisponible - montoTotal);
}
void cCliente::SET_RECETA(cReceta nuevaReceta)
{
    this->miReceta = nuevaReceta;
}