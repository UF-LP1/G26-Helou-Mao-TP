/**
 * Project Untitled
 */


#ifndef _CEMPLEADOLIMPIEZA_H
#define _CEMPLEADOLIMPIEZA_H

#include "cEmpleado.h"


class cEmpleadoLimpieza : public cEmpleado {
private:
    int turno;

public:
    cEmpleadoLimpieza(string nombre, string apellido, int numeroEmpleado,  string dni, string contacto, int turno);
    ~cEmpleadoLimpieza();
    void SET_TURNO(int _turnoNuevo);
    int GET_TURNO();
};

#endif //_CEMPLEADOLIMPIEZA_H