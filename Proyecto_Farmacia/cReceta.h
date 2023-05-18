/**
 * Project Untitled
 */


#ifndef _CRECETA_H
#define _CRECETA_H
#include"Headers.h"

class cReceta {
private:
    string ObraSocial;
    string Medicamento;
    int Dosis;

public:
    cReceta();
    cReceta(string _obraSoc, string _medicamento, int _dosis);
    ~cReceta();
    int GET_DOSIS();
    string GET_MEDICAMENTO();
    string GET_OBRASOCIAL();

};

#endif //_CRECETA_H