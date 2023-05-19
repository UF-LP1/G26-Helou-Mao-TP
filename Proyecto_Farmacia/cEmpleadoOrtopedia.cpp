/**
 * Project Untitled
 */


#include "cEmpleadoOrtopedia.h"

cEmpleadoOrtopedia::cEmpleadoOrtopedia(string dni)
    :cVendedor::cVendedor(dni)
{

}
    

cEmpleadoOrtopedia::cEmpleadoOrtopedia( string nombre, string apellido, int numerEmpleado, const string dni, string contacto)
    :cVendedor(nombre, apellido, numerEmpleado, dni, contacto)
{

}

cEmpleadoOrtopedia::~cEmpleadoOrtopedia() {

}

void cEmpleadoOrtopedia::Asesorar()     //con random asesoramos sobre productos random
{
    int random;
    random = rand() % 3;
    switch (random)
    {
    case 0:
        cout << "Esta rodillera conviene usarla todo el dia para mas eficiencia" << endl;
        break;
    case 1:
        cout << "Las vendas van a ser mas utiles si se aplican sobre la piel mojada" << endl;
        break;
    case 2:
        cout << "El andador se puede doblar para que sea mas practico de transportar" << endl;
    default:
        cout << "Lamentamos decir que no tenemos el producto deseado" << endl;
    }

}

void cEmpleadoOrtopedia::AgregarProductoCarrito(cOrtopedia producto)    //se agrega el producto de ortopedia deseado en nuestro carrito
{
    list<cCliente>::iterator it = misClientes.end();
    it->GET_CARRITO()->GET_LISTAPRODUCTOS().push_back (producto);
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
        impresion = "Acaban de entrar unas muñeras de ultima tecnologia";
        break;
    case 2:
        impresion= "Con este cabestrillo non vas a sentir molestias" ;
        break;
    default:
        impresion="Lamentamos decir que no tenemos el producto deseado" ;
    }
    return impresion;
}
void cEmpleadoOrtopedia::AtenderCliente(cCliente *cliente, cOrtopedia producto) {
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi vector de clientes
    AgregarProductoCarrito(producto);
    Asesorar();
    return;
}