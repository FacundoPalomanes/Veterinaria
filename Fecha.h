#pragma once
#include <iostream>

using namespace std;

class Fecha
{
private:
    int _dia, _mes, _anio;

public:
    // CONSTRUCTOR
    Fecha() {};
    Fecha(int dia, int mes, int anio)
    {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }
    /// GETTERS
    int getDia() { return _dia; }
    int getMes() { return _mes; }
    int getAnio() { return _anio; }

    /// SETTERS
    void setDia(int dia) { _dia = dia; }
    void setMes(int mes) { _mes = mes; }
    void setAnio(int anio) { _anio = anio; }

    /// FUNCTIONS
    void mostrar()
    {
        cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
    }

    void cargar()
    {
        int dia, mes, anio;
        cout << "Ingresar el dia: ";
        cin >> dia;
        cout << "Ingresar el mes: ";
        cin >> mes;
        cout << "Ingresar el anio: ";
        cin >> anio;

        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }
};
