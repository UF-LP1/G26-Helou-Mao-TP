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
    int aux = misClientes.size();
    misClientes[aux].GET_CARRITO()->GET_LISTAPRODUCTOS().push_back (producto);
}
void cEmpleadoOrtopedia::RecomendarProductos()      //usamos random para hecerle alguna recomendacion al cliente
{
    int random;
    random = rand() % 3;
    switch (random)
    {
    case 0:
        cout << "Mira que buenas estas nuevas muletas" << endl;
        break;
    case 1:
        cout << "Acaban de entrar unas muñeras de ultima tecnologia" << endl;
        break;
    case 2:
        cout << "Con este cabestrillo non vas a sentir molestias" << endl;
    default:
        cout << "Lamentamos decir que no tenemos el producto deseado" << endl;
    }
    return;
}