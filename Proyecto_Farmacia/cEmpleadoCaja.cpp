//empeado caja cpp


#include "cEmpleadoCaja.h"
#include <exception>

cEmpleadoCaja::cEmpleadoCaja(string dni)
    :cEmpleado::cEmpleado(dni)
{
    this->plataCaja = 0.0;
}

cEmpleadoCaja::cEmpleadoCaja(string nombre, string apellido, int numeroEmpleado, string dni, string contacto, double plataCaja)
:cEmpleado( nombre, apellido, numeroEmpleado, dni, contacto)
    {
    this->plataCaja = plataCaja;
    }

cEmpleadoCaja::~cEmpleadoCaja() {

}


double cEmpleadoCaja::CalculaMontoACobrar(cCarrito oCarrito) {   //calculo el monto a cobrar para usar la funcion cobrar
    vector<cProducto> auxProds; //la memoria se libera automaticamente
    auxProds = oCarrito.GET_LISTAPRODUCTOS();
    int i;
    double total = 0.0;  //valor  devolver para cobrar
    for (i = 0; i < auxProds.size(); i++)
    {
        total = total + auxProds[i].Get_PRECIO();   //voy sumando precio de cada unidad que tengo 
    }
    total = total - oCarrito.GET_DESCUENTOMED();    //le resto el descuento
    return total;   //devuelvo el total
}

bool cEmpleadoCaja::chequearSaldoDisponible(cCliente cliente, double montoAPagar)  //para poder cobrarle al cliente voy  atener que chequear si tiene suficiente saldo 
{
    int metodoAux = cliente.GET_METODO();   //obtengo el metodo de pago del cliente
    double saldoDisponible = 0.0;
   
    if (metodoAux == 0) //paga en efectivo
        saldoDisponible = cliente.GET_EFECTIVO_DISPONIBLE(); //obtengo el efectivo disponible
    else if (metodoAux==1)  //paga con tarjeta
        double saldoDisponible = cliente.GET_SALDO_DISPONIBLE();  //obtengo el saldo disponible en tarjeta
    else //paga con mercado pago
        double saldoDisponible = cliente.GET_SALDO_MP(); //obtengo el saldo disponible en mercado pago
    
    //chequeo si alcanza para pagar
    if (montoAPagar <= saldoDisponible)
        return true;
    else
        return false;
        
}

void cEmpleadoCaja::emitirFactura(double precio, cCliente& cliente) { //le agrego la factura al cliente
    string apeAux = cliente.GET_APELLIDO();
    string nomAux = cliente.GET_NOMBRE();
    bool formatoAux = cliente.GET_FORMATO();
    vector <cProducto> listaProds = cliente.GET_CARRITO()->GET_LISTAPRODUCTOS();
    cFactura facturaAux(precio, nomAux, apeAux, formatoAux, listaProds);
    cliente.SET_FACTURA(facturaAux);
    return;
}
cTicketdecompra cEmpleadoCaja::Cobrar(cCliente &cliente)
{
    cCarrito *carritoAux = cliente.GET_CARRITO();
    double precioTotal = CalculaMontoACobrar(*carritoAux);   //obtengo el monto total a pagar

    bool chequearSaldoAux = chequearSaldoDisponible(cliente, precioTotal); //chequeo que el cliente tenga saldo suficiente
    

    if (chequearSaldoAux == false)
    {
        throw new exception("Saldo insuficiente");
        //cTicketdecompra ticketERROR(false, precioTotal, cliente.GET_DNI(), this->nombre, this->apellido, this->numeroEmpleado, cliente.GET_NOMBRE(), cliente.GET_APELLIDO(), cliente.GET_CARRITO().GET_LISTAPRODUCTOS()); //aca tirariamos un THROW SALDO INSUFICIENTE pero no lo podes usar para este tp
        //return ticketERROR; //el false incial determina que la compra no se pudo realizar
    }
    else
    {
        cTicketdecompra ticketAux(true,precioTotal, cliente.GET_DNI(), this->nombre, this->apellido,this->numeroEmpleado, cliente.GET_NOMBRE(), cliente.GET_APELLIDO(), cliente.GET_CARRITO()->GET_LISTAPRODUCTOS()); //construyoelticket de compra
        this->plataCaja = this->plataCaja + precioTotal;    //sumo al dinero en caja lo que acabo de cobrar
        emitirFactura(precioTotal, cliente);    //le seteo la factur al cliente
        return ticketAux;   //devuelvo el ticket
    }
         
    
}

