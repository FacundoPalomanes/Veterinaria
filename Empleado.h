#pragma once
#include "Persona.h"
#include <cstring>
#include <iostream>
#include "Fecha.h"

using namespace std;

class Empleado : public Persona
{
private:
    int _idEmpleado, _categoria;
    char _especialidad[30];
    Fecha _fechaDeIngreso;

public:
    /// GETTERS
    int getIdEmpleado() { return _idEmpleado; }
    int getCategoria() { return _categoria; }
    char *getEspecialidad() { return _especialidad; }
    Fecha getFechaDeIngreso() { return _fechaDeIngreso; }

    /// SETTERS
    void setIdEmpleado(int idEmpleado) { _idEmpleado = idEmpleado; }
    void setCategoria(int categoria) { _categoria = categoria; }
    void setEspecialidad(const char especialidad[30])
    {
        strncpy(_especialidad, especialidad, sizeof(_especialidad) - 1);
        _especialidad[sizeof(_especialidad) - 1] = '\0';
    }
    void setFechaDeIngreso(Fecha fechaDeIngreso)
    {
        _fechaDeIngreso.setAnio(fechaDeIngreso.getAnio());
        _fechaDeIngreso.setMes(fechaDeIngreso.getMes());
        _fechaDeIngreso.setDia(fechaDeIngreso.getDia());
    }

    void cargar()
    {
        int dni, telefono, categoria;
        char nombreYApellido[100], mail[100], direccion[50], especialidad[30];
        Fecha fechaDeIngreso;

        cout << "CARGAR NUEVO EMPLEADO" << endl;

        cout << "DNI : ";
        cin >> dni;
        cout << "TELEFONO : ";
        cin >> telefono;

        cin.ignore();

        cout << "NOMBRE Y APELLIDO: ";
        cin.getline(nombreYApellido, 100);

        cout << "MAIL : ";
        cin >> mail;

        cin.ignore();

        cout << "DIRECCION : ";
        cin.getline(direccion, 50);

        cout << "CATEGORIA 1. VETERINARIO - 2. ADMINISTRATIVO : ";
        cin >> categoria;
        while(categoria != 1 || categoria != 2) {
            cout << "INGRESE UNA CATEGORIA VALIDA : ";
            cin >> categoria;
        }

        cin.ignore();

        cout << "ESPECIALIDAD : ";
        cin.getline(especialidad, 30);

        cout << "INGRESAR FECHA DE INGRESO AL TRABAJO" << endl;
        fechaDeIngreso.cargar();

        setDni(dni);
        setTelefono(telefono);
        setCategoria(categoria);
        setNombreYApellido(nombreYApellido);
        setMail(mail);
        setDireccion(direccion);
        setEspecialidad(especialidad);
        setFechaDeIngreso(fechaDeIngreso);
        setEstado(true);
    }

    void mostrar()
    {
        cout << "DNI : " << getDni() << endl;
        cout << "TELEFONO : " << getTelefono() << endl;
        cout << "NOMBRE Y APELLIDO : " << getNombreYApellido() << endl;
        cout << "MAIL : " << getMail() << endl;
        cout << "DIRECCION : " << getDireccion() << endl;
        cout << "ID EMPLEADO : " << getIdEmpleado() << endl;
        cout << "CATEGORIA : " << getCategoria() << endl;
        cout << "ESPECIALIDAD : " << getEspecialidad() << endl;
        getFechaDeIngreso().mostrar();
        cout << endl
             << endl;
    }
};
