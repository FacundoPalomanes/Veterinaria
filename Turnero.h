#include "Fecha.h"

class Turnero
{
private:
    int _idMascota, _dniDuenio, _idEmpleado;
    char _horario[6];
    Fecha _fechaAsignada;

public:
    /// GETTERS
    char *getHorario() { return _horario; }
    int getIdMascota() { return _idMascota; }
    int getDniDuenio() { return _dniDuenio; }
    int getIdEmpleado() { return _idEmpleado; }
    Fecha getFechaAsignada() { return _fechaAsignada; }

    /// SETTERS
    char *setHorario(const char horario[6])
    {
        strncpy(_horario, horario, sizeof(_horario) - 1);
        _horario[sizeof(_horario) - 1] = '\0';
    }
    void setIdMascota(int idMascota) { _idMascota = idMascota; }
    void setDniDuenio(int dniDuenio) { _dniDuenio = dniDuenio; }
    void setIdEmpleado(int idEmpleado) { _idEmpleado = idEmpleado; }
    void setFechaConsulta(Fecha fechaAsignada)
    {
        _fechaAsignada.setAnio(fechaAsignada.getAnio());
        _fechaAsignada.setMes(fechaAsignada.getMes());
        _fechaAsignada.setDia(fechaAsignada.getDia());
    }

    bool cargar()
    {
        char horario[6];
        int idMascota, dniDuenio, idEmpleado;
        Fecha fechaAsignada;

        cout << "INGRESAR ID DE LA MASCOTA: ";
        cin >> idMascota;
        if (!validarPaciente(idMascota))
        {
            cout << endl
                 << "MASCOTA NO ENCONTRADO" << endl;
                 system("pause");
            return false;
        }

        cout << "INGRESAR DNI DEL DUENIO : ";
        cin >> dniDuenio;
        if (!validarDuenio(dniDuenio))
        {
            cout << endl
                 << "DUENIO NO ENCONTRADO" << endl;
                 system("pause");
            return false;
        }

        cout << "INGRESAR ID DEL EMPLEADO : ";
        cin >> idEmpleado;
        if (!validarEmpleado(idEmpleado))
        {
            cout << endl
                 << "DUENIO NO ENCONTRADO" << endl;
                 system("pause");
            return false;
        }
        cout << endl
             << "INGRESAR HORARIO : ";
        cin >> horario;
        cout << "INGRESAR FECHA DE CONSULTA : ";
        fechaAsignada.cargar();

        setFechaConsulta(fechaAsignada);
        setHorario(horario);
        setIdMascota(idMascota);
        setDniDuenio(dniDuenio);
        setIdEmpleado(idEmpleado);
        return true;
    }
    void mostrar()
    {
        Fecha fechaAsignada;
        fechaAsignada = getFechaAsignada();
        cout << endl
             << "HORARIO : " << getHorario() << endl;
        cout << "ID DE LA MASCOTA : " << getIdMascota() << endl;
        cout << "DNI DEL DUENIO : " << getDniDuenio() << endl;
        cout << "ID DEL EMPLEADO : " << getIdEmpleado() << endl;
        cout << "FECHA DE CONSULTA : ";
        fechaAsignada.mostrar();
    }
};
