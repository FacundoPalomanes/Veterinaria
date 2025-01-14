#include "Tratamiento.h"
#include <cstdio>
#include <iostream>

using namespace std;

int agregarTratamiento();
void mostrarTratamiento(int idTratamiento);

int agregarTratamiento()
{
    Tratamiento tratamiento;
    int idTratamiento;
    tratamiento.cargar();

    FILE *pArchivo = fopen("Tratamiento.dat", "rb+");
    if (pArchivo == NULL)
    {

        idTratamiento = 1;
        tratamiento.setIdTratamiento(idTratamiento);
        pArchivo = fopen("Tratamiento.dat", "wb");
        if (pArchivo == NULL)
        {
            cout << "Error al crear el archivo para escritura." << endl;
            system("pause");
            return -1;
        }
    }
    else
    {
        Tratamiento ultimoTratamiento;
        fseek(pArchivo, -(long int)sizeof(Tratamiento), SEEK_END);
        if (fread(&ultimoTratamiento, sizeof(Tratamiento), 1, pArchivo) == 1)
        {
            int ultimoId = ultimoTratamiento.getIdTratamiento() + 1;
            tratamiento.setIdTratamiento(ultimoId);
            idTratamiento = ultimoId;
        }
        else
        {
            idTratamiento = 1;
            tratamiento.setIdTratamiento(1);
        }
        fclose(pArchivo);
        pArchivo = fopen("Tratamiento.dat", "ab");
        if (pArchivo == NULL)
        {
            cout << "Error al abrir el archivo para escritura." << endl;
            system("pause");
            return -1;
        }
    }

    bool ok = (fwrite(&tratamiento, sizeof(Tratamiento), 1, pArchivo) == 1);
    if (!ok)
    {
        cout << "Error al escribir en el archivo." << endl;
    }
    else
    {
        cout << "Tratamiento agregado con ID: " << tratamiento.getIdTratamiento() << endl;
    }

    fclose(pArchivo);
    return idTratamiento;
}

void mostrarTratamiento(int idTratamiento)
{
    FILE *pArchivo = fopen("Tratamiento.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << endl
             << "Error al abrir el archivo para lectura." << endl;
        system("pause");
        return;
    }
    Tratamiento tratamiento;
    bool encontrado = false;
    while (fread(&tratamiento, sizeof(Tratamiento), 1, pArchivo))
    {
        if (tratamiento.getIdTratamiento() == idTratamiento)
        {
            tratamiento.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "TRATAMIENTO NO ENCONTRADO" << endl;
    system("pause");
    fclose(pArchivo);
    return;
}
