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
    int aux = clientes.size();

    vector<cProducto> auxProds; //la memoria se libera automaticamente
    auxProds = clientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS();//copio en un aux mi lista de productos
    int i;
    double total = 0.0;  //valor  devolver para cobrar
    for (i = 0; i < auxProds.size(); i++)   //recorro el auxiliar de productos
    {
        total = total + auxProds[i].Get_PRECIO();   //voy sumando precio de cada unidad que tengo 
    }
    total = total - clientes[aux].GET_CARRITO()->GET_DESCUENTOMED();    //le resto el descuento
    return total;   //devuelvo el total
}

bool cEmpleadoCaja::chequearSaldoDisponible( double montoAPagar)  //para poder cobrarle al cliente voy  atener que chequear si tiene suficiente saldo 
{
    int aux = clientes.size();
    int metodoAux = clientes[aux].GET_METODO();   //obtengo el metodo de pago del cliente
    double saldoDisponible = 0.0;
   
    if (metodoAux == 0) //paga en efectivo
        saldoDisponible = clientes[aux].GET_EFECTIVO_DISPONIBLE(); //obtengo el efectivo disponible
    else if (metodoAux==1)  //paga con tarjeta
        saldoDisponible = clientes[aux].GET_SALDO_DISPONIBLE();  //obtengo el saldo disponible en tarjeta
    else //paga con mercado pago
         saldoDisponible = clientes[aux].GET_SALDO_MP(); //obtengo el saldo disponible en mercado pago
    
    //chequeo si alcanza para pagar
    if (montoAPagar <= saldoDisponible)
        return true;
    else
        return false;
        
}

void cEmpleadoCaja::emitirFactura(double precio) { //le agrego la factura al cliente
    int aux = clientes.size();
        //copio los datos de mi cliente para pasarlos a la factura
    string apeAux = clientes[aux].GET_APELLIDO();
    string nomAux = clientes[aux].GET_NOMBRE();
    bool formatoAux = clientes[aux].GET_FORMATO();
    vector <cProducto> listaProds = clientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS();
        //creo la factura con los datos que guarde arriba
    cFactura facturaAux(precio, nomAux, apeAux, formatoAux, listaProds);
    clientes[aux].SET_FACTURA(facturaAux); //le guardo al cliente la factura que acabo de crear
    return;
}
cTicketdecompra cEmpleadoCaja::Cobrar()
{
    int aux = clientes.size();
  
    double precioTotal = CalculaMontoACobrar();   //obtengo el monto total a pagar
    bool chequearSaldoAux = chequearSaldoDisponible( precioTotal); //chequeo que el cliente tenga saldo suficiente
    
    if (chequearSaldoAux == false)// significa que al cliente no le alcanza la plata
    {
        throw new exception(" Saldo insuficiente");
    }
    else //al cliente le alcanza la plata
    {
            //creo un ticket de compra con mis datos
        cTicketdecompra ticketAux(true,precioTotal, clientes[aux].GET_DNI(), this->nombre, this->apellido,this->numeroEmpleado, clientes[aux].GET_NOMBRE(), clientes[aux].GET_APELLIDO(), clientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS()); //construyoelticket de compra
        this->plataCaja = this->plataCaja + precioTotal;    //sumo al dinero en caja lo que acabo de cobrar
        try
        {
            pagar(precioTotal);
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
void cEmpleadoCaja::pagar( double total)    //va a restarle la plata al cliente
{
    int aux = clientes.size();
    int metodo = clientes[aux].GET_METODO();
    double saldo = 0.0;//inicializo en 0

        //al cliente que esta en mi vector le resto lo que le cobre
    switch (metodo)
    {
    case 0: //si pago en efectivo
        saldo = clientes[aux].GET_EFECTIVO_DISPONIBLE() - total;    
        clientes[aux].SET_EFECTIVO(saldo);
        break;
    case 1: //si pago con tarjeta
        saldo = clientes[aux].GET_SALDO_DISPONIBLE() - total;
        clientes[aux].SET_SALDO(saldo);
        break;
    case 2: //si pago con mp
        saldo = clientes[aux].GET_SALDO_MP() - total;
        clientes[aux].SET_MP(saldo);
        break;
    default:
        throw new exception("Mal registrado el metodo de pago"); 
    }
}
void cEmpleadoCaja::AtenderCliente(cCliente cliente) {
    this->clientes.push_back(cliente);   //agrego el nuevo cliente al final de mi vector de clientes
    return;
}