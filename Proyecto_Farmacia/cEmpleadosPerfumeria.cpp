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
string cEmpleadosPerfumeria::Asesorar()       //asesoramos sobre productos random
{
    int random;
    string impresion;
    random = rand() % 3;
    switch (random)
    {
    case 0:
        impresion = "Este shampoo es bueno para cuero cabelludo graso";
        break;
    case 1:
        impresion = "El secadoor de pelo conviene utilizarlo diez minutos luego del lavado";
        break;
    case 2:
        impresion = "Dentro de los desodorantes el mas recomendado es de la marca Rexona";
        break;
    default:
        impresion = "Lamentamos decir que no tenemos el producto deseado";
        break;
    }
    return impresion;
}
void cEmpleadosPerfumeria::AgregarProductoCarrito(cPerfumeria &producto)     //agregamos productos al carrito de a uno
{
    this->misClientes.back().GET_CARRITO()->SET_PRODUCTO(&producto);
}
void cEmpleadosPerfumeria::AtenderCliente(cCliente* cliente, cPerfumeria* producto) {
    cVendedor::AtenderCliente(cliente);     //agrego el nuevo cliente al final de mi vector de clientes
    AgregarProductoCarrito(*producto);
    return;
}

list<cPerfumeria> cEmpleadosPerfumeria::GET_LISTADO()
{
    return this->listaPerfumeria;
}

cPerfumeria cEmpleadosPerfumeria::buscarProducto (unsigned int prodAllevar)
{
    //busco el producto que quiere el cliente entre los productos del empleado
    prodAllevar = prodAllevar - 1; //resto uno porque el cliente elije a partir del uno y yo tengo productos a partir del 0
    for (cPerfumeria& perf : this->listaPerfumeria)
    {
        if (prodAllevar == perf.GET_TIPO())
        {
            return perf;
        }
    }
}