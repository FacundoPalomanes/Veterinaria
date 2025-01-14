#include <iostream>
#include "FunctionsEmpleado.h"
#include "FunctionsPaciente.h"
#include "FunctionsConsulta.h"
#include "FunctionsTurnero.h"

using namespace std;

void menu();
void seleccionIndividual(int opcion);
void empleados();
void pacientes();
void turnos();

void menu()
{
    cout << endl
         << "INGRESE LA OPCION QUE DESEA" << endl;
    cout << "---------------------------" << endl;
    cout << "1. VETERINARIA" << endl;
    cout << "2. ADMINISTRATIVO" << endl;
    cout << "0. SALIR" << endl
         << endl;
    cout << "OPCION A INGRESAR: ";
}

void seleccionIndividual(int decision)
{
    int segundaDecision;
    while (true)
    {
        switch (decision)
        {
        case 1:
        {
            system("cls");
            cout << endl
                 << "OPCION MARCADA: VETERINARIA" << endl;
            cout << "---------------------------" << endl;
            cout << "1. PACIENTES" << endl;
            cout << "2. AGREGAR CONSULTA" << endl;
            cout << "3. BUSCAR CONSULTA POR ID DEL ANIMAL" << endl;
            cout << "4. BUSCAR MASCOTAS DE UNA PERSONA" << endl;
            cout << "0. VOLVER AL MENU" << endl
                 << endl;
            cout << "OPCION A INGRESAR: ";
            cin >> segundaDecision;

            switch (segundaDecision)
            {
            case 1:
                pacientes();
                break;
            case 2:
                agregarConsulta();
                break;
            case 3:
                buscarConsulta();
                break;
            case 4:
                buscarMascotasPorDni();
                break;
            case 0:
                system("cls");
                return;
            }
        }
        break;
        case 2:
        {
            system("cls");
            cout << endl
                 << "OPCION MARCADA: ADMINISTRACION" << endl;
            cout << "---------------------------" << endl;
            cout << "1. TURNOS" << endl;
            cout << "2. EMPLEADOS" << endl;
            cout << "3. BUSCAR DUENIO POR DNI" << endl;
            cout << "0. VOLVER AL MENU" << endl
                 << endl;
            cout << "OPCION A INGRESAR: ";

            cin >> segundaDecision;

            switch (segundaDecision)
            {
            case 1:
                turnos();
                break;
            case 2:
                empleados();
                break;
            case 3:
                leerDuenio();
                break;
            case 0:
                system("cls");
                return;
            }
        }
        break;
        }
    }
}

void empleados()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "MENU EMPLEADOS" << endl;
        cout << "------------------" << endl;
        cout << "1. AGREGAR EMPLEADO" << endl;
        cout << "2. LISTA DE EMPLEADOS" << endl;
        cout << "3. BUSCAR EMPLEADO" << endl;
        cout << "4. ELIMINAR EMPLEADO" << endl;
        cout << "0. VOLVER AL MENU" << endl
             << endl;
        cout << "OPCION A INGRESAR: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarEmpleado();
            break;
        case 2:
            listarEmpleados();
            break;
        case 3:
            leerEmpleado();
            break;
        case 4:
            eliminarEmpleados();
            break;
        case 0:
            return;
        }
    }
}

void pacientes()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "MENU PACIENTES" << endl;
        cout << "------------------" << endl;
        cout << "1. INGRESAR NUEVO PACIENTE" << endl;
        cout << "2. BUSCAR PACIENTE POR ID" << endl;
        cout << "3. ELIMINAR PACIENTE POR ID" << endl;
        cout << "4. LISTADO DE PACIENTES" << endl;
        cout << "0. VOLVER AL MENU" << endl
             << endl;
        cout << "OPCION A INGRESAR: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarNuevoPaciente();
            break;
        case 2:
            leerPaciente();
            break;
        case 3:
            eliminarPaciente();
            break;
        case 4:
            listarPacientes();
            break;
        case 0:
            return;
        }
    }
}

void turnos()
{
    int opcion;
    while (true)
    {
        system("cls");
        cout << "MENU TURNOS" << endl;
        cout << "------------------" << endl;
        cout << "1. AGREGAR UN TURNO" << endl;
        cout << "2. VER TURNOS ASIGNADOS POR MES" << endl;
        cout << "0. VOLVER AL MENU" << endl
             << endl;
        cout << "OPCION A INGRESAR: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            agregarTurno();
            break;
        case 2:
            verTurnosPorMes();
            break;
        case 0:
            return;
        }
    }
}