/**
 * Project Untitled
 */


#ifndef _CCLIENTE_H
#define _CCLIENTE_H

class cCliente {
public: 
    
/**
 * @param string
 * @param string
 * @param string
 * @param eMetodo
 * @param struct
 * @param eNecesidad
 * @param const string
 */
void cCliente(void string, void string, void string, void eMetodo, void struct, void eNecesidad, void const string);
    
cCarrito GET_CARRITO();
    
/**
 * @param cProducto
 * @param int
 */
void AgregarProductosPerfumeria(void cProducto, void int );
    
/**
 * @param cProducto
 * @param int
 */
void AgregarGolosinas(void cProducto, void int);
protected: 
    
void cCliente();
private: 
    string nombre;
    string apellido;
    string contacto;
    eMetodo metodoPago;
    structLesion lesion;
    eNecesidad necesidad;
    const stirng DNI;
};

#endif //_CCLIENTE_H