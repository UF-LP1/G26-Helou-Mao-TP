/**
 * Project Untitled
 */


#include "cEmpleadoOrtopedia.h"

cEmpleadoOrtopedia::cEmpleadoOrtopedia(string dni)  //constructor por defecto
    :cVendedor::cVendedor(dni)
{

}
    

cEmpleadoOrtopedia::cEmpleadoOrtopedia( string nombre, string apellido, int numerEmpleado, const string dni, string contacto, list <cOrtopedia>listaOrtopedia)
    :cVendedor(nombre, apellido, numerEmpleado, dni, contacto)
{
    this->listaOrtopedia = listaOrtopedia;
}

cEmpleadoOrtopedia::~cEmpleadoOrtopedia() {

}

string cEmpleadoOrtopedia::Asesorar()     //con random asesoramos sobre productos random
{
    int random;
    string consejos = "";
    random = rand() % 3;
    switch (random)
    {
    case 0:
        consejos = "Esta rodillera conviene usarla todo el dia para mas eficiencia";
        break;
    case 1:
        consejos = "Las vendas van a ser mas utiles si se aplican sobre la piel mojada";
        break;
    case 2:
        consejos = "El andador se puede doblar para que sea mas practico de transportar" ;
    default:
        consejos = "Lamentamos decir que no tenemos el producto deseado" ;
    }
    return consejos;
}

void cEmpleadoOrtopedia::AgregarProductoCarrito(cOrtopedia producto)    //se agrega el producto de ortopedia deseado en el carrito del cliente
{
    this->misClientes.back().GET_CARRITO()->SET_PRODUCTO(&producto);
}
string cEmpleadoOrtopedia::RecomendarProductos()      //usamos random para hecerle alguna recomendacion al cliente
{
    int random;
    string impresion="";
    random = rand() % 3;
    switch (random)
    {
    case 0:
        impresion="Mira que buenas estas nuevas muletas";
        break;
    case 1:
        impresion = "Acaban de entrar unas muñequeras de ultima tecnologia";
        break;
    case 2:
        impresion= "Con este cabestrillo no vas a sentir molestias" ;
        break;
    default:
        impresion="Lamentamos decir que no tenemos el producto deseado" ;
        break;
    }
    return impresion;
}
void cEmpleadoOrtopedia::AtenderCliente(cCliente *cliente, cOrtopedia producto) {
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi vector de clientes
    AgregarProductoCarrito(producto);
    return;
}

cOrtopedia cEmpleadoOrtopedia::buscarProductoOrtopedia(unsigned int prodAllevar)  
{
    //busco entre los productos que tiene el ortopedista, el que quiere mi cliente
    prodAllevar = prodAllevar - 1;//resto uno porque al cliente le enumero los productos desde el 1 y yo los tengo enumerados desde 0
    for (cOrtopedia& ort : this->listaOrtopedia)
    {
        if (prodAllevar == ort.GET_TIPO())
        {
            return ort;//encuentro el producto y lo devuelvo
        }
    }
}
list <cOrtopedia> cEmpleadoOrtopedia::GET_LISTADO_ORT()
{
    return this->listaOrtopedia;
}