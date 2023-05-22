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
    auxProds = clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS();//copio en un aux mi lista de productos

    double total = 0.0;  //valor  devolver para cobrar
    for (list < cProducto>::iterator it = auxProds.begin(); it != auxProds.end(); it++)   //recorro el auxiliar de productos
    {
        total = total + it->Get_PRECIO();   //voy sumando precio de cada unidad que tengo 
    }
    total = total - clientes.back().GET_CARRITO()->GET_DESCUENTOMED();    //le resto el descuento
    return total;   //devuelvo el total
}

bool cEmpleadoCaja::chequearSaldoDisponible( double montoAPagar)  //para poder cobrarle al cliente voy  atener que chequear si tiene suficiente saldo 
{
   
    int metodoAux = clientes.back().GET_METODO();   //obtengo el metodo de pago del cliente
    double saldoDisponible = 0.0;
   
    if (metodoAux == 0) //paga en efectivo
        saldoDisponible = clientes.back().GET_EFECTIVO_DISPONIBLE(); //obtengo el efectivo disponible
    else if (metodoAux==1)  //paga con tarjeta
        saldoDisponible = clientes.back().GET_SALDO_DISPONIBLE();  //obtengo el saldo disponible en tarjeta
    else //paga con mercado pago
         saldoDisponible = clientes.back().GET_SALDO_MP(); //obtengo el saldo disponible en mercado pago
    
    //chequeo si alcanza para pagar
    if (montoAPagar <= saldoDisponible)
        return true;
    else
        return false;
        
}

void cEmpleadoCaja::emitirFactura(double precio) { //le agrego la factura al cliente
    
    //copio los datos de mi cliente para pasarlos a la factura

    string apeAux = clientes.back().GET_APELLIDO();
    string nomAux = clientes.back().GET_NOMBRE();
    bool formatoAux = clientes.back().GET_FORMATO();
    list <cProducto> listaProds = clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS();
        //creo la factura con los datos que guarde arriba
    //cFactura *facturaAux= clientes.back().GET_FACTURA();
    //facturaAux->SET_FORMATO(formatoAux);
    //facturaAux->SET_MONTO(precio);
    //facturaAux->SET_NOMBRECLIENTE(nomAux);
    //facturaAux->SET_APELLIDOCLIENTE(apeAux);
    cFactura facturaAux(precio, nomAux, apeAux, formatoAux, listaProds);
    clientes.back().SET_FACTURA(facturaAux);
    //le guardo al cliente la factura que acabo de crear
    return;
}
cTicketdecompra cEmpleadoCaja::Cobrar()
{
  
    double precioTotal = CalculaMontoACobrar();   //obtengo el monto total a pagar
    bool chequearSaldoAux = chequearSaldoDisponible( precioTotal); //chequeo que el cliente tenga saldo suficiente
    
    if (chequearSaldoAux == false)// significa que al cliente no le alcanza la plata
    {
        throw new exception(" Saldo insuficiente");
    }
    else //al cliente le alcanza la plata
    {
            //creo un ticket de compra con mis datos
        cTicketdecompra ticketAux(true,precioTotal, clientes.back().GET_DNI(), this->nombre, this->apellido,this->numeroEmpleado, clientes.back().GET_NOMBRE(), clientes.back().GET_APELLIDO(), clientes.back().GET_CARRITO()->GET_LISTAPRODUCTOS()); //construyoelticket de compra
        this->plataCaja = this->plataCaja + precioTotal;    //sumo al dinero en caja lo que acabo de cobrar
        try
        {
            clientes.back().pagar(precioTotal);
        }
        catch (exception* e)
        {
            throw e;
        }
         //le va a restar la plata al cliente
        emitirFactura(precioTotal);    //le seteo la factur al cliente
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
