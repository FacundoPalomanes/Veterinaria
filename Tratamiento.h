#pragma once
#include <cstring>

using namespace std;

class Tratamiento
{
private:
    int _idTratamiento;
    char _descripcion[100], _indicaciones[100];

public:
    /// GETTERS
    int getIdTratamiento() { return _idTratamiento; }
    char *getIndicacion() { return _indicaciones; }
    char *getDescripcion() { return _descripcion; }

    /// SETTERS
    void setIdTratamiento(int idTratamiento) { _idTratamiento = idTratamiento; }
    void setIndicacion(const char indicaciones[100])
    {
        strncpy(_indicaciones, indicaciones, sizeof(_indicaciones) - 1);
        _indicaciones[sizeof(_indicaciones) - 1] = '\0';
    }
    void setDescripcion(const char descripcion[100])
    {
        strncpy(_descripcion, descripcion, sizeof(_descripcion) - 1);
        _descripcion[sizeof(_descripcion) - 1] = '\0';
    }

    void mostrar()
    {
        cout << endl
             << "INDICACIONES : " << getIndicacion();
        cout << endl
             << "DESCRIPCION : " << getDescripcion() << endl;
    }

    void cargar()
    {
        char descripcion[100], indicaciones[100];
        cout << "INDICACIONES : ";
        cin >> indicaciones;
        cout << "DESCRIPCION : ";
        cin >> descripcion;
        setIndicacion(indicaciones);
        setDescripcion(descripcion);
    }
};
