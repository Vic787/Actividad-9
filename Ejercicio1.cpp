#include <iostream>

using namespace std;

struct Estudiante{
	int codigo[4];
	string nombre[4];
	string apellido[4];
	int nota[4];
	float promedio[4];
};

main(){
	Estudiante estudiante;
	int notas = 0, n;
	
	cout << "Ingrese cuantos estudiantes desea ingresar: ";
	cin >> n;
	
	for(int i = 0; i < n; i++){
		notas = 0;
		cout << "--- Estudiante " << i+1 << " ---" << endl;
		cout << "____________________" << endl;
		cout << "Ingrese codigo: ";
		cin >> estudiante.codigo[i];
		cin.ignore();
		cout << "Ingrese nombres: ";
		getline(cin,estudiante.nombre[i]);
		cout << "Ingrese apellidos: ";
		getline(cin,estudiante.apellido[i]);
		
		for(int ii = 0; ii < 4; ii++){
			cout << "Ingrese nota [" << ii+1 << "]: ";
			cin >> estudiante.nota[ii];
			notas += estudiante.nota[ii];
		}
		
		estudiante.promedio[i] = notas/4;
		cout << "____________________" << endl;
	}
	
	for(int i = 0; i < n; i++){
		cout << "____________________" << endl;
		cout << "Codigo: " << estudiante.codigo[i] << endl;
		cout << "Nombres: " << estudiante.nombre[i] << endl;
		cout << "Apellidos: " << estudiante.apellido[i] << endl;
		cout << "Promedio: " << estudiante.promedio[i] << endl;
		if(estudiante.promedio[i] > 60){
			cout << "Estudiante aprobado." << endl;
		} else {
			cout << "Estudiante reprobado." << endl;
		}
	}
	
	system("Pause");
}
