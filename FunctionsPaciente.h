#include <cstdio>
#include "Paciente.h"
#include "Persona.h"

using namespace std;

void agregarNuevoPaciente();
void leerPaciente();
void listarPacientes();
void eliminarPaciente();
void agregarDuenio(Persona duenio);
void leerDuenio();
void buscarMascotasPorDni();
bool validarPaciente(int idMascota);
bool validarDuenio(int dni);

void agregarNuevoPaciente()
{
    Paciente nuevoPaciente;
    bool validacion = false;

    nuevoPaciente.cargar();
    validacion = validarDuenio(nuevoPaciente.getDniDuenio());
    if(!validacion)
    {
        Persona nuevaPersona;
        nuevaPersona.cargar(nuevoPaciente.getDniDuenio());
        agregarDuenio(nuevaPersona);
    }

    FILE *pArchivo = fopen("Pacientes.dat", "rb+");
    if (pArchivo == NULL)
    {

        nuevoPaciente.setIdMascota(1);

        pArchivo = fopen("Pacientes.dat", "wb");
        if (pArchivo == NULL)
        {
            cout << "Error al crear el archivo para escritura." << endl;
            return;
        }
    }
    else
    {
        Paciente ultimoPaciente;
        fseek(pArchivo, -(long int)sizeof(Paciente), SEEK_END);
        if (fread(&ultimoPaciente, sizeof(Paciente), 1, pArchivo) == 1)
        {
            int ultimoId = ultimoPaciente.getIdMascota() + 1;
            nuevoPaciente.setIdMascota(ultimoId);
        }
        else
        {
            nuevoPaciente.setIdMascota(1);
        }
        fclose(pArchivo);

        pArchivo = fopen("Pacientes.dat", "ab");
        if (pArchivo == NULL)
        {
            cout << "Error al abrir el archivo para escritura." << endl;
            return;
        }
    }

    bool ok = (fwrite(&nuevoPaciente, sizeof(Paciente), 1, pArchivo) == 1);
    if (!ok)
    {
        cout << "Error al escribir en el archivo." << endl;
    }
    else
    {
        cout << "Paciente agregado con ID: " << nuevoPaciente.getIdMascota() << endl;
    }

    fclose(pArchivo);
}

void leerPaciente()
{
    int idMascota;
    cout << "INGRESAR ID DE MASCOTA: ";
    cin >> idMascota;
    FILE *pArchivo = fopen("Pacientes.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }
    Paciente paciente;
    bool encontrado = false;
    while (fread(&paciente, sizeof(Paciente), 1, pArchivo))
    {
        if (paciente.getIdMascota() == idMascota && paciente.getEstado())
        {
            paciente.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "EMPLEADO NO ENCONTRADO" << endl;
    fclose(pArchivo);
    system("pause");
    return;
}

void listarPacientes()
{
    FILE *pArchivo = fopen("Pacientes.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }
    Paciente paciente;
    while (fread(&paciente, sizeof(Paciente), 1, pArchivo))
    {
        if (paciente.getEstado())
        {
            paciente.mostrar();
        }
    }
    system("pause");
    fclose(pArchivo);
    return;
}

void eliminarPaciente()
{
    int id;
    cout << "INGRESAR ID DE MASCOTA: ";
    cin >> id;
    FILE *pArchivo = fopen("Pacientes.dat", "rb+");
    if (pArchivo == NULL)
    {
        cout << "Error: no se pudo abrir el archivo para actualizar." << endl;
        system("pause");
        return;
    }

    Paciente paciente;
    bool encontrado = false;

    while (fread(&paciente, sizeof(Paciente), 1, pArchivo) == 1)
    {
        if (paciente.getIdMascota() == id)
        {
            paciente.setEstado(false);

            fseek(pArchivo, -static_cast<long>(sizeof(Paciente)), SEEK_CUR);

            fwrite(&paciente, sizeof(Paciente), 1, pArchivo);
            encontrado = true;
            break;
        }
    }

    fclose(pArchivo);

    if (encontrado)
    {
        cout << "Estado actualizado correctamente." << endl;
    }
    else
    {
        cout << "No encontrado" << endl;
    }
    system("pause");
    return;
}

void agregarDuenio(Persona duenio)
{
    FILE *pArchivo = fopen("Duenio.dat", "ab");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }

    bool ok = (fwrite(&duenio, sizeof(Persona), 1, pArchivo) == 1);
    if (ok)
    {
        cout << endl
             << "Duenio agregado con exito." << endl;
    }
    else
    {
        cout << endl
             << "Error al escribir en el archivo." << endl;
    }
    system("pause");
    fclose(pArchivo);
}

void buscarMascotasPorDni()
{
    int dni;
    cout << "INGRESAR DNI DEL DUENIO: ";
    cin >> dni;
    FILE *pArchivo = fopen("Pacientes.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }
    Paciente paciente;
    bool encontrado = false;
    while (fread(&paciente, sizeof(Paciente), 1, pArchivo))
    {
        if (paciente.getDniDuenio() == dni)
        {
            paciente.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "MASCOTAS NO ENCONTRADAS" << endl;
    fclose(pArchivo);
    system("pause");
    return;
}

void leerDuenio()
{
    int dni;
    cout << "INGRESAR DNI DEL DUENIO: ";
    cin >> dni;
    FILE *pArchivo = fopen("Duenio.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }
    Persona persona;
    bool encontrado = false;
    while (fread(&persona, sizeof(Persona), 1, pArchivo))
    {
        if (persona.getDni() == dni)
        {
            persona.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "DUENIO NO ENCONTRADO" << endl;
    fclose(pArchivo);
    system("pause");
    return;
}

bool validarPaciente(int idMascota)
{

    FILE *pArchivo = fopen("Pacientes.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return false;
    }
    Paciente paciente;
    bool encontrado = false;
    while (fread(&paciente, sizeof(Paciente), 1, pArchivo))
    {
        if (paciente.getIdMascota() == idMascota && paciente.getEstado())
        {
            encontrado = true;
        }
    }
    fclose(pArchivo);
    system("pause");
    return encontrado;

}

bool validarDuenio(int dni)
{
    FILE *pArchivo = fopen("Duenio.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return false;
    }
    Persona persona;
    bool encontrado = false;
    while (fread(&persona, sizeof(Persona), 1, pArchivo))
    {
        if (persona.getDni() == dni)
        {
            encontrado = true;
        }
    }
    fclose(pArchivo);
    system("pause");
    return encontrado;
}
