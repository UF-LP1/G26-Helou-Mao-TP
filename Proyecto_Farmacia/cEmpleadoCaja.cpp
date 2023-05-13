//empeado caja cpp


#include "cEmpleadoCaja.h"

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
    total = total - oCarrito.GET_DESCUENTOMED();    //e reseto el descuento
    return total;   //devuelvo el total
}

bool cEmpleadoCaja::chequearSaldoDisponible(cCliente cliente, double montoAPagar)  //para poder cobrarle al cliente voy  atener que chequear si tiene suficiente saldo 
{
    int metodoAux = cliente.GET_METODO();   //obtengo el metodo de pago del cliente
    
    if (metodoAux == 0) //paga en efectivo
    {
        double efectivoDisponible = cliente.GET_EFECTIVO_DISPONIBLE(); //obtengo el efectivo disponible
        if (montoAPagar > efectivoDisponible )
            return false;   //saldo insuficiente
        else
            return true;    //todo ok, voy a pagar
    }
    else if (metodoAux==1)  //paga con tarjeta
    {
        double saldoDisponible = cliente.GET_SALDO_DISPONIBLE();  //obtengo el saldo disponible en tarjeta
        if (montoAPagar > saldoDisponible) //si el monto a pagar supera el saldo disponible en tarjeta
            return false;   //saldo insuficiente
        else
            return true;    //todo ok, puedo ir a cobrar
    }
    else //paga con mercado pago
    {
        double saldoMP = cliente.GET_SALDO_MP(); //obtengo el saldo disponible en mercado pago
        if (montoAPagar > saldoMP)
            return false;   //saldo insuficiente
        else
            return true;    //todo ok, voy a pagar

    }
}

cTicketdecompra cEmpleadoCaja::Cobrar(cCliente &cliente)
{
    cCarrito carritoAux = cliente.GET_CARRITO();
    double precioTotal = CalculaMontoACobrar(carritoAux);   //obtengo el monto total a pagar

    bool chequearSaldoAux = chequearSaldoDisponible(cliente, precioTotal); //chequeo que el cliente tenga saldo suficiente
    

    if (chequearSaldoAux == false)
    {
        cTicketdecompra ticketERROR(false, precioTotal, cliente.GET_DNI(), this->nombre, this->apellido, this->numeroEmpleado, cliente.GET_NOMBRE(), cliente.GET_APELLIDO(), cliente.GET_CARRITO().GET_LISTAPRODUCTOS()); //aca tirariamos un THROW SALDO INSUFICIENTE pero no lo podes usar para este tp
        return ticketERROR; //el false incial determina que la compra no se pudo realizar
    }
    else
    {
        cTicketdecompra ticketAux(true,precioTotal, cliente.GET_DNI(), this->nombre, this->apellido,this->numeroEmpleado, cliente.GET_NOMBRE(), cliente.GET_APELLIDO(), cliente.GET_CARRITO().GET_LISTAPRODUCTOS()); //construyoelticket de compra
        this->plataCaja = this->plataCaja + precioTotal;    //sumo al dinero en caja lo que acabo de cobrar
        emitirFactura(precioTotal, cliente);    //le seteo la factur al cliente
        return ticketAux;   //devuelvo el ticket
    }
         
    
}

void cEmpleadoCaja::emitirFactura(double precio, cCliente &cliente) { //le agrego la factura al cliente
    string apeAux = cliente.GET_APELLIDO();
    string nomAux = cliente.GET_NOMBRE();
    bool formatoAux = cliente.GET_FORMATO();
    vector <cProducto> listaProds = cliente.GET_CARRITO().GET_LISTAPRODUCTOS();
    cFactura facturaAux(precio,nomAux, apeAux,formatoAux, listaProds);
    cliente.SET_FACTURA(facturaAux);
    return;
}

