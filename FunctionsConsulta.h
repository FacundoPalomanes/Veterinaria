#include "Consulta.h"

using namespace std;

void agregarConsulta();
void buscarConsulta();

void agregarConsulta()
{
    Consulta nuevaConsulta;
    nuevaConsulta.cargar();

    FILE *pArchivo = fopen("Consultas.dat", "ab");
    if (pArchivo == NULL)
    {
        cout << "Error al abrir el archivo para escritura." << endl;
        system("pause");
        return;
    }

    bool ok = (fwrite(&nuevaConsulta, sizeof(Consulta), 1, pArchivo) == 1);
    if (ok)
    {
        cout << endl
             << "Consulta agregado con exito." << endl;
    }
    else
    {
        cout << endl
             << "Error al escribir en el archivo." << endl;
    }
    system("pause");
    fclose(pArchivo);
    return;
}

void buscarConsulta()
{
    int idAnimal;
    cout << "ID DEL ANIMAL: ";
    cin >> idAnimal;

    FILE *pArchivo = fopen("Consultas.dat", "rb");
    if (pArchivo == NULL)
    {
        cout << endl
             << "Error al abrir el archivo para lectura." << endl;
        system("pause");
        return;
    }
    Consulta consulta;
    bool encontrado = false;
    while (fread(&consulta, sizeof(Consulta), 1, pArchivo))
    {
        if (consulta.getIdMascota() == idAnimal)
        {
            consulta.mostrar();
            encontrado = true;
        }
    }
    if (encontrado == false)
        cout << endl
             << "CONSULTA NO ENCONTRADA" << endl;
    system("pause");
    fclose(pArchivo);
    return;
}
