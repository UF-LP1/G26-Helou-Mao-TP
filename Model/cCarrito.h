/**
 * Project Untitled
 */


#ifndef _CCARRITO_H
#define _CCARRITO_H

class cCarrito {
public: 
    
cProducto GET_LISTAPRODUCTOS();
    
/**
 * @param float
 */
void SET_PRECIOCARRITO(void float);
    
/**
 * @param float
 * @param int
 */
void cCarrito(void float, void int);
    
/**
 * @param cProductos
 * @param int
 */
void AgregarProductos(void cProductos, void int);
    
/**
 * @param cProductos
 * @param int
 */
void EliminarProductos(void cProductos, void int );
protected: 
    
void cCarrito();
private: 
    float precioCarrito;
    int cantidad;
};

#endif //_CCARRITO_H