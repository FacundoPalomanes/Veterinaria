#include "Fecha.h"
#include <string.h>
#include "Tratamiento.h"
#include "FunctionsTratamiento.h"

class Consulta
{
private:
    int _idMascota, _idTratamiento;
    char _nombreMascota[50], _motivoConsulta[100], _diagnostico[100];
    Fecha _fechaConsulta;

public:
    /// GETTERS
    int getIdMascota() { return _idMascota; }
    int getIdTratamiento() { return _idTratamiento; }
    char *getNombreMascota() { return _nombreMascota; }
    char *getMotivoConsulta() { return _motivoConsulta; }
    char *getDiagnostico() { return _diagnostico; }
    Fecha getFechaConsulta() { return _fechaConsulta; }

    /// SETTERS
    void setIdMascota(int idMascota) { _idMascota = idMascota; }
    void setIdTratamiento(int idTratamiento) { _idTratamiento = idTratamiento; }
    void setNombreMascota(const char nombreMascota[50])
    {
        strncpy(_nombreMascota, nombreMascota, sizeof(_nombreMascota) - 1);
        _nombreMascota[sizeof(_nombreMascota) - 1] = '\0';
    }
    void setMotivoConsulta(const char motivoConsulta[100])
    {
        strncpy(_motivoConsulta, motivoConsulta, sizeof(_motivoConsulta) - 1);
        _motivoConsulta[sizeof(_motivoConsulta) - 1] = '\0';
    }
    void setDiagnostico(const char diagnostico[50])
    {
        strncpy(_diagnostico, diagnostico, sizeof(_diagnostico) - 1);
        _diagnostico[sizeof(_diagnostico) - 1] = '\0';
    }
    void setFechaConsulta(Fecha fechaConsulta)
    {
        _fechaConsulta.setAnio(fechaConsulta.getAnio());
        _fechaConsulta.setMes(fechaConsulta.getMes());
        _fechaConsulta.setDia(fechaConsulta.getDia());
    }

    void cargar()
    {
        int idMascota, idTratamiento;
        char nombreMascota[50], motivoConsulta[100], diagnostico[100];
        Fecha fechaConsulta;
        bool pacienteExiste = false;

        cout << endl
             << "ID MASCOTA: ";
        cin >> idMascota;

        pacienteExiste = validarPaciente(idMascota);
        if(pacienteExiste) {

        cout << "1- SI HAY TRATAMIENTO 2- SI NO HAY TRATAMIENTO : ";
        cin >> idTratamiento;
        while(idTratamiento != 1 || idTratamiento != 2) {
            cout << "INGRESE UNA OPCION VALIDA: ";
            cin >> idTratamiento;
        }

        if (idTratamiento == 1)
        {
            idTratamiento = agregarTratamiento();
            if (idTratamiento == -1)
            {
                cout << endl
                     << "Hubo un error creando el Tratamiento" << endl;
                return;
            }
            cin.ignore();
        }
        else
        {
            idTratamiento = 0;
        }

        cout << "NOMBRE DEL PACIENTE: ";
        cin.getline(nombreMascota, sizeof(nombreMascota));

        cout << "MOTIVO DE LA CONSULTA : ";
        cin.getline(motivoConsulta, sizeof(motivoConsulta));

        cout << "DIAGNOSTICO : ";
        cin.getline(diagnostico, sizeof(diagnostico));

        cout << "FECHA DE LA CONSULTA : ";
        fechaConsulta.cargar();

        setIdMascota(idMascota);
        setIdTratamiento(idTratamiento);
        setNombreMascota(nombreMascota);
        setMotivoConsulta(motivoConsulta);
        setDiagnostico(diagnostico);
        setFechaConsulta(fechaConsulta);
        } else {
            cout << endl << "PACIENTE NO ENCONTRADO" << endl;
        }
    }

    void mostrar()
    {
        Fecha fechaConsulta = getFechaConsulta();
        cout << "ID MASCOTA: " << getIdMascota() << endl;
        cout << "NOMBRE DE LA MASCOTA : " << getNombreMascota() << endl;
        cout << "MOTIVO DE LA CONSULTA : " << getMotivoConsulta() << endl;
        cout << "FECHA DE CONSULTA : ";
        fechaConsulta.mostrar();
        cout << "DIAGNOSTICO : " << getDiagnostico() << endl
             << endl;
        cout << "ID TRATAMIENTO : " << getIdTratamiento() << endl
             << endl;
        if (getIdTratamiento() != 0)
        {
            int decision;
            cout << "ESTA CONSULTA TIENE TRATAMIENTO 1- VERLO 2- NO VERLO : ";
            cin >> decision;
            while(decision != 1 || decision != 2) {
                cout << endl << "INGRESE UNA DECISION VALIDA : ";
                cin >> decision;
            if (decision == 1)
            {
                mostrarTratamiento(getIdTratamiento());
            }
            }
        }
    }
};
