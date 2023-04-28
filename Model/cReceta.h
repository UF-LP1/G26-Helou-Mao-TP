/**
 * Project Untitled
 */


#ifndef _CRECETA_H
#define _CRECETA_H

class cReceta {
public: 
    
/**
 * @param string
 * @param string
 * @param string
 * @param int
 */
void cReceta(void string, void string, void string, void int);
    
int GET_DOSIS();
    
string GET_MEDICAMENTO();
    
string GET_OBRASOCIAL();
protected: 
    
void cReceta();
private: 
    string ObraSocial;
    string Medicamento;
    int Dosis;
};

#endif //_CRECETA_H