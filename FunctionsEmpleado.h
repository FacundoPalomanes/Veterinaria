#include <cstdio>
#include "Empleado.h"
#include <iostream>

using namespace std;

void agregarEmpleado();
void leerEmpleado();
void listarEmpleados();
void eliminarEmpleados();
bool validarEmpleado(int idEmpleado);

void agregarEmpleado()
{
    Empleado nuevoEmpleado;
    nuevoEmpleado.cargar();

    FILE *pArchivo = fopen("Empleados.dat", "rb+");
    if (pArchivo == NULL)
    {

        nuevoEmpleado.setIdEmpleado(1);

        pArchivo = fopen("Empleados.dat", "wb");
        if (pArchivo == NULL)
        {
            cout << "Error al crear el archivo para escritura." << endl;
            system("pause");
            return;
        }
    }
    else
    {
        Empleado ultimoEmpleado;
        fseek(pArchivo, -(long int)sizeof(Empleado), SEEK_END);
        if (fread(&ultimoEmpleado, sizeof(Empleado), 1, pArchivo) == 1)
        {
            int ultimoId = ultimoEmpleado.getIdEmpleado() + 1;
            nuevoEmpleado.setIdEmpleado(ultimoId);
        }
        else
        {
            nuevoEmpleado.setIdEmpleado(1);
        }
        fclose(pArchivo);
        pArchivo = fopen("Empleados.dat", "ab");
        if (pArchivo == NULL)
        {
            cout << "Error al abrir el archivo para escritura." << endl;
            system("pause");
            return;
        }
    }

    bool ok = (fwrite(&nuevoEmpleado, sizeof(Empleado), 1, pArchivo) == 1);
    if (!ok)
    {
        cout << "Error al escribir en el archivo." << endl;
    }
    else
    {
        cout << "Empleado agregado con ID: " << nuevoEmpleado.getIdEmpleado() << endl;
    }

    fclose(pArchivo);
    return;
}

void leerEmpleado()
{
    int idEmpleado;
    cout << "ID EMPLEADO: ";
    cin >> idEmpleado;
    FILE *pArchivo = fopen("Empleados.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << endl
             << "Error al abrir el archivo para lectura." << endl;
        system("pause");
        return;
    }
    Empleado empleado;
    bool encontrado = false;
    while (fread(&empleado, sizeof(Empleado), 1, pArchivo))
    {
        if (empleado.getIdEmpleado() == idEmpleado && empleado.getEstado())
        {
            empleado.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "EMPLEADO NO ENCONTRADO" << endl;
    system("pause");
    fclose(pArchivo);
    return;
}

void listarEmpleados()
{
    FILE *pArchivo = fopen("Empleados.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << endl
             << "Error al abrir el archivo para lectura." << endl;
        system("pause");
        return;
    }
    Empleado empleado;
    while (fread(&empleado, sizeof(Empleado), 1, pArchivo))
    {
        if (empleado.getEstado())
        {
            empleado.mostrar();
        }
    }
    system("pause");
    fclose(pArchivo);
    return;
}

void eliminarEmpleados()
{
    int id;
    cout << "ID EMPLEADO: ";
    cin >> id;
    FILE *pArchivo = fopen("Empleados.dat", "rb+");
    if (pArchivo == NULL)
    {
        cout << endl
             << "Error al abrir el archivo para lectura." << endl;
        system("pause");
        return;
    }

    Empleado empleado;
    bool encontrado = false;

    while (fread(&empleado, sizeof(Empleado), 1, pArchivo) == 1)
    {
        if (empleado.getIdEmpleado() == id && empleado.getEstado())
        {
            empleado.setEstado(false);

            fseek(pArchivo, -static_cast<long>(sizeof(Empleado)), SEEK_CUR);

            fwrite(&empleado, sizeof(Empleado), 1, pArchivo);
            encontrado = true;
            break;
        }
    }

    fclose(pArchivo);

    if (encontrado)
    {
        cout << "Empleado eliminado correctamente." << endl;
    }
    else
    {
        cout << "No encontrado" << endl;
    }

    return;
}

bool validarEmpleado(int idEmpleado)
{
    FILE *pArchivo = fopen("Empleados.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return false;
    }
    Empleado empleado;
    bool encontrado = false;
    while (fread(&empleado, sizeof(Empleado), 1, pArchivo))
    {
        if (empleado.getIdEmpleado() == idEmpleado)
        {
            encontrado = true;
        }
    }
    fclose(pArchivo);
    system("pause");
    return encontrado;
}
