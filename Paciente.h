#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Paciente
{
private:
    int _idMascota, _edadMascota, _dniDuenio;
    char _nombreMascota[50], _animal[50], _raza[50], _sexo;
    bool _estado, _estadoReproductivo;

public:
    /// GETTERS
    int getIdMascota() { return _idMascota; }
    int getEdadMascota() { return _edadMascota; }
    int getDniDuenio() { return _dniDuenio; }
    char *getNombreMascota() { return _nombreMascota; }
    char *getAnimal() { return _animal; }
    char *getRaza() { return _raza; }
    char getSexo() { return _sexo; }
    bool getEstado() { return _estado; }
    bool getEstadoReproductivo() { return _estadoReproductivo; }

    /// SETTERS
    void setIdMascota(int idMascota) { _idMascota = idMascota; }
    void setEdadMascota(int edadMascota) { _edadMascota = edadMascota; }
    void setDniDuenio(int dniDuenio) { _dniDuenio = dniDuenio; }
    void setNombreMascota(const char nombreMascota[50])
    {
        strncpy(_nombreMascota, nombreMascota, sizeof(_nombreMascota) - 1);
        _nombreMascota[sizeof(_nombreMascota) - 1] = '\0';
    }
    void setAnimal(const char animal[50])
    {
        strncpy(_animal, animal, sizeof(_animal) - 1);
        _animal[sizeof(_animal) - 1] = '\0';
    }
    void setRaza(const char raza[50])
    {
        strncpy(_raza, raza, sizeof(_raza) - 1);
        _raza[sizeof(_raza) - 1] = '\0';
    }
    void setSexo(const char sexo) { _sexo = sexo; }
    void setEstado(bool estado) { _estado = estado; }
    void setEstadoReproductivo(bool estadoReproductivo) { _estadoReproductivo = estadoReproductivo; }

    /// Functions
    void mostrar()
    {
        cout << "ID MASCOTA: " << getIdMascota() << endl;
        cout << "EDAD MASCOTA : " << getEdadMascota() << endl;
        cout << "DNI DEL DUENIO: " << getDniDuenio() << endl;
        cout << "NOMBRE DEL PACIENTE : " << getNombreMascota() << endl;
        cout << "ANIMAL : " << getAnimal() << endl;
        cout << "RAZA : " << getRaza() << endl;
        cout << "SEXO : " << getSexo() << endl;
        cout << "ESTADO : " << getEstado() << endl;
        if (getEstadoReproductivo())
        {
            cout << "ESTADO REPRODUCTIVO: NO CASTRADO" << endl
                 << endl;
        }
        else
        {
            cout << "ESTADO REPRODUCTIVO: CASTRADO" << endl
                 << endl;
        }
    }

    void cargar()
    {
        int edadMascota = 0, dniDuenio;
        char nombreMascota[50], animal[50], raza[50], sexo;
        int estadoReproductivo;
        bool edadCorrecta = false, sexoCorrecto = false, estadoReproductivoCorrecto = false;

        while(!edadCorrecta) {
                cout << "EDAD MASCOTA : ";
                cin >> edadMascota;
                if(edadMascota < 100 && edadMascota > 0) {
                    edadCorrecta = true;
                }
        }
        cout << "DNI DEL DUENIO : ";
        cin >> dniDuenio;


        cin.ignore();

        cout << "NOMBRE DEL PACIENTE: ";
        cin.getline(nombreMascota, sizeof(nombreMascota));

        cout << "ANIMAL : ";
        cin.getline(animal, sizeof(animal));

        cout << "RAZA : ";
        cin.getline(raza, sizeof(raza));

        cout << "SEXO ('F' o 'M'): ";
        cin >> sexo;
        while(!sexoCorrecto) {
            if(sexo == 'F' || sexo == 'M') {
            sexoCorrecto = true;
            } else {
            cout << endl <<  "INGRESE UNA LETRA VALIDA ('F' o 'M'):";
            cin >> sexo;
            }
        }

        cout << "ESTADO REPRODUCTIVO (1 - NO CASTRADO, 0 - CASTRADO): ";
        cin >> estadoReproductivo;
        while(!estadoReproductivoCorrecto) {
                if(estadoReproductivo == 1 || estadoReproductivo == 0) {
                    estadoReproductivoCorrecto = true;
                } else {
                    cout << endl <<  "INGRESE UN VALOR VALIDO (1 - NO CASTRADO, 0 - CASTRADO): ";
                    cin >>estadoReproductivo;
                }
        }

        setEdadMascota(edadMascota);
        setDniDuenio(dniDuenio);
        setNombreMascota(nombreMascota);
        setAnimal(animal);
        setRaza(raza);
        setSexo(sexo);
        setEstado(true);
        setEstadoReproductivo(estadoReproductivo);
    }
};
