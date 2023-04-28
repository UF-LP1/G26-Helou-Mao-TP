/**
 * Project Untitled
 */


#ifndef _CTICKETDECOMPRA_H
#define _CTICKETDECOMPRA_H

class cTicketdecompra {
public: 
    
float GET_TOTAL();
    
/**
 * @param float
 */
void SET_TOTAL(void float);
    
/**
 * @param float
 * @param string
 */
void cTicketdecompra(void float, void string);
protected: 
    
void cTicketdecompra();
private: 
    float precioTotal;
    string DNI;
};

#endif //_CTICKETDECOMPRA_H