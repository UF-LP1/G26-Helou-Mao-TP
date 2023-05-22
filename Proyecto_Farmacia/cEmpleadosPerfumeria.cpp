/**
 * Project Untitled
 */


#include "cEmpleadosPerfumeria.h"

cEmpleadosPerfumeria::cEmpleadosPerfumeria(string dni)
    :cVendedor::cVendedor(dni)
{

}

cEmpleadosPerfumeria::cEmpleadosPerfumeria( string nombre, string apellido, int numeroEmpleado, const string dni, string contacto, list <cPerfumeria> listaPerfumeria)
    :cVendedor( nombre, apellido, numeroEmpleado, dni, contacto)
{
    this->listaPerfumeria = listaPerfumeria;
}

cEmpleadosPerfumeria::~cEmpleadosPerfumeria() {

}
void cEmpleadosPerfumeria::Asesorar()       //asesoramos sobre productos random
{
    int random;
    random = rand() % 3;
    switch (random)
    {
    case 0:
        cout << "Este shampoo es bueno para cuero cabelludo graso" << endl;
        break;
    case 1:
        cout << "El secadoor de pelo conviene utilizarlo diez minutos luego del lavado" << endl;
        break;
    case 2:
        cout << "Dentro de los desodorantes el mas recomendado es de la marca Rexona" << endl;
    default:
        cout << "Lamentamos decir que no tenemos el producto deseado" << endl;
    }
}
void cEmpleadosPerfumeria::AgregarProductoCarrito(cPerfumeria &producto)     //agregamos productos al carrito de a uno
{
    misClientes.back().GET_CARRITO()->SET_PRODUCTO(&producto);
}
void cEmpleadosPerfumeria::AtenderCliente(cCliente* cliente, cPerfumeria* producto) {
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi vector de clientes
    AgregarProductoCarrito(*producto);
    Asesorar();
    return;
}

list<cPerfumeria> cEmpleadosPerfumeria::GET_LISTADO()
{
    return this->listaPerfumeria;
}

cPerfumeria cEmpleadosPerfumeria::buscarProducto (unsigned int prodAllevar)
{
    prodAllevar = prodAllevar - 1;
    for (cPerfumeria& perf : this->listaPerfumeria)
    {
        if (prodAllevar == perf.GET_TIPO())
        {
            return perf;
        }
    }
}