/**
 * Project Untitled
 */


#ifndef _CEMPLEADO_H
#define _CEMPLEADO_H

class cEmpleado {
public: 
    
/**
 * @param cCliente
 */
void AtenderCliente(void cCliente);
    
/**
 * @param cProducto
 * @param int
 * @param float
 */
float CalculaMontoACobrar(void cProducto, void int, void float);
    
/**
 * @param float
 * @param cProducto
 * @param cCliente
 * @param int
 */
cTicketdecompra EmitirTicket(void float, void cProducto, void cCliente, void int);
    
/**
 * @param ccProducto
 * @param cCarrito
 */
void AgregarProductoCarrito(void ccProducto, void cCarrito);
    
/**
 * @param cCliente
 */
void PasarClienteaCaja(void cCliente);
    
/**
 * @param string
 * @param string
 * @param int
 * @param const string
 * @param string
 */
void cEmpleado(void string, void string, void int, void const string, void string);
protected: 
    string nombre;
    string apellido;
    int numeroEmpleado;
    const string DNI;
    string contacto;
    
void cEmpleado();
};

#endif //_CEMPLEADO_H