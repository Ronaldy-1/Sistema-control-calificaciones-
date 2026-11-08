// Sistema de control de calificaciones
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    char otroGrupo;
    cout << fixed << setprecision(2);

    // Repite todo el programa mientras el usuario escriba s
    do {
        int cantidad, aprobados = 0, reprobados = 0;
        double sumaPromedios = 0, mejorPromedio = -1;
        string mejorNombre;

        // Pide la cantidad hasta que sea mayor que 0
        do {
            cout << "Cantidad de estudiantes: ";
            cin >> cantidad;
        } while (cantidad <= 0);

        // Recorre cada estudiante
        for (int i = 1; i <= cantidad; i++) {
            string nombre;
            double nota, sumaNotas = 0;

            cout << "--- Estudiante " << i << " ---" << endl;
            cout << "Nombre: ";
            cin >> nombre;

            // Recorre las 4 calificaciones
            for (int j = 1; j <= 4; j++) {
                // Repite la nota hasta que este entre 0 y 100
                do {
                    cout << "Calificacion " << j << ": ";
                    cin >> nota;
                } while (nota < 0 || nota > 100);
                sumaNotas = sumaNotas + nota;
            }

            double promedio = sumaNotas / 4;
            sumaPromedios = sumaPromedios + promedio;
            cout << "Promedio: " << promedio << " - ";

            if (promedio >= 70) {
                cout << "Aprobado" << endl;
                aprobados++;
            } else {
                cout << "Reprobado" << endl;
                reprobados++;
            }

            if (promedio > mejorPromedio) {
                mejorPromedio = promedio;
                mejorNombre = nombre;
            }
        }

        cout << "===== RESUMEN =====" << endl;
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << endl;
        cout << "Promedio del grupo: " << sumaPromedios / cantidad << endl;
        cout << "Mejor promedio: " << mejorNombre << " (" << mejorPromedio << ")" << endl;

        cout << "Desea procesar otro grupo? (s/n): ";
        cin >> otroGrupo;
    } while (otroGrupo == 's');

    return 0;
}
