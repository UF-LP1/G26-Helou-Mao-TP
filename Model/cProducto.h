/**
 * Project Untitled
 */


#ifndef _CPRODUCTO_H
#define _CPRODUCTO_H

class cProducto {
public: 
    
float Get_PRECIO();
    
string Get_NOMBRE();
    
/**
 * @param float
 * @param string 
 * @param int
 * @param string
 */
void cProducto(void float, void string , void int, void string);
protected: 
    float precio;
    string nombre;
    int cantidad;
    string marca;
    
void cProducto();
};

#endif //_CPRODUCTO_H