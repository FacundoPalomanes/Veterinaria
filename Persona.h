#pragma once
#include <cstring>

using namespace std;

class Persona
{
private:
    int _dni, _telefono;
    char _nombreYApellido[100], _mail[100], _direccion[50];
    bool _estado;

public:
    /// GETTERS
    int getDni() { return _dni; }
    int getTelefono() { return _telefono; }
    char *getNombreYApellido() { return _nombreYApellido; }
    char *getMail() { return _mail; }
    char *getDireccion() { return _direccion; }
    bool getEstado() { return _estado; }

    /// SETTERS
    void setDni(int dni) { _dni = dni; }
    void setTelefono(int telefono) { _telefono = telefono; }
    void setNombreYApellido(const char nombreYApellido[100])
    {
        strncpy(_nombreYApellido, nombreYApellido, sizeof(_nombreYApellido) - 1);
        _nombreYApellido[sizeof(_nombreYApellido) - 1] = '\0';
    }
    void setMail(const char mail[100])
    {
        strncpy(_mail, mail, sizeof(_mail) - 1);
        _mail[sizeof(_mail) - 1] = '\0';
    }
    void setDireccion(const char direccion[100])
    {
        strncpy(_direccion, direccion, sizeof(_direccion) - 1);
        _direccion[sizeof(_direccion) - 1] = '\0';
    }
    void setEstado(bool estado) { _estado = estado; }

    void cargar(int dni)
    {
        int telefono;
        char nombreYApellido[100], mail[100], direccion[50];
        cout << "TELEFONO : ";
        cin >> telefono;
        cin.ignore();
        cout << "NOMBRE DEL DUENIO : ";
        cin.getline(nombreYApellido, sizeof(nombreYApellido));
        cout << "MAIL : ";
        cin.getline(mail, sizeof(mail));
        cout << "DIRECCION : ";
        cin.getline(direccion, sizeof(direccion));

        setDni(dni);
        setTelefono(telefono);
        setNombreYApellido(nombreYApellido);
        setMail(mail);
        setDireccion(direccion);
        setEstado(true);
    }

    void mostrar()
    {
        int dni, telefono;
        char nombreYApellido[100], mail[100], direccion[50];
        cout << endl
             << "DNI : " << getDni() << endl;
        cout << "TELEFONO : " << getTelefono() << endl;
        cout << "NOMBRE DEL DUENIO : " << getNombreYApellido() << endl;
        cout << "MAIL : " << getMail() << endl;
        cout << "DIRECCION : " << getDireccion() << endl;
    }
};
