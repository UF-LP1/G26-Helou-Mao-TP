//empeado caja cpp


#include "cEmpleadoCaja.h"


cEmpleadoCaja::cEmpleadoCaja(string dni)//constructor cuando no tiene plata
    :cEmpleado::cEmpleado(dni)
{
    this->plataCaja = 0.0;
}

cEmpleadoCaja::cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, string dni, string contacto, double plataCaja) //constructor cuando tiene plata
:cEmpleado( nombre, apellido, numeroEmpleado, dni, contacto)
    {
    this->plataCaja = plataCaja;
    }

cEmpleadoCaja::~cEmpleadoCaja() {

}


double cEmpleadoCaja::CalculaMontoACobrar() {   //calculo el monto a cobrar para usar la funcion cobrar

    list<cProducto> auxProds; //la memoria se libera automaticamente
    auxProds = this->clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS();//copio en un aux mi lista de productos

    double total = 0.0;  //valor devolver para cobrar
    for (list < cProducto>::iterator it = auxProds.begin(); it != auxProds.end(); it++)   //recorro el auxiliar de productos
    {
        total = total + it->Get_PRECIO();   //voy sumando precio de cada unidad que tengo 
    }
    total = total - this->clientes.back().GET_CARRITO()->GET_DESCUENTOMED();    //le resto el descuento
    return total;   //devuelvo el total con el descuento ya restado
}

bool cEmpleadoCaja::chequearSaldoDisponible( double montoAPagar)  //para poder cobrarle al cliente voy  atener que chequear si tiene suficiente saldo 
{
    double saldoDisponible = 0.0;
    saldoDisponible = this->clientes.back().GET_SALDO_DISPONIBLE();  //obtengo el saldo disponible en tarjeta
    
    //chequeo si alcanza para pagar
    if (montoAPagar <= saldoDisponible)
        return true;
    else
        return false;
        
}

void cEmpleadoCaja::emitirFactura(double precio) { //le agrego la factura al cliente
    
    //copio los datos de mi cliente para pasarlos a la factura

    string apeAux = this->clientes.back().GET_APELLIDO();
    string nomAux = this->clientes.back().GET_NOMBRE();
    bool formatoAux = this->clientes.back().GET_FORMATO();
    list <cProducto> listaProds = this->clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS();
    cFactura facturaAux(precio, nomAux, apeAux, formatoAux, listaProds);
    this->clientes.back().SET_FACTURA(facturaAux);
    //le guardo al cliente la factura que acabo de crear
    return;
}
cTicketdecompra cEmpleadoCaja::Cobrar(cCliente *cliente)
{
  
    double precioTotal = CalculaMontoACobrar();   //obtengo el monto total a pagar
    bool chequearSaldoAux = chequearSaldoDisponible(precioTotal); //chequeo que el cliente tenga saldo suficiente
    
    if (chequearSaldoAux == false)// significa que al cliente no le alcanza la plata
    {
        throw new exception(" Saldo insuficiente"); //la compra no va a poder ser realizada
    }
    else //al cliente le alcanza la plata
    {
            //creo un ticket de compra con mis datos
        cTicketdecompra ticketAux(true,precioTotal, this->clientes.back().GET_DNI(), this->nombre, this->apellido,this->numeroEmpleado, clientes.back().GET_NOMBRE(), clientes.back().GET_APELLIDO(), clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS()); //construyoelticket de compra
        this->plataCaja = this->plataCaja + precioTotal;    //sumo al dinero en caja lo que acabo de cobrar
       
        this->clientes.back().pagar(precioTotal);   //llamo la funcion pagar de cliente para poder restarle la plata que va a gastar
         //le va a restar la plata al cliente
        emitirFactura(precioTotal);    //le seteo la factura al cliente
        *cliente = this->clientes.back();//asi tambien se modifica el cliente que recibo del main (es el mismo solo que despues voy a chequear con el del main)
        return ticketAux;   //devuelvo el ticket para despues agregarlo al local
    }

         
}

void cEmpleadoCaja::AtenderCliente(cCliente *cliente) {
    this->clientes.push_back(*cliente);   //agrego el nuevo cliente al final de mi vector de clientes
    return;
}
double cEmpleadoCaja::GET_PLATA()
{
    return this->plataCaja;
}
list <cCliente> cEmpleadoCaja::GET_CLIENTES()
{
    return this->clientes;
}