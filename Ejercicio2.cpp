#include <iostream>

using namespace std;

struct Estudiante{
	int *codigo;
	string *nombre;
	string *apellido;
	int **nota;
	float *promedio;
};

main(){
	Estudiante estudiante;
	int notas = 0, n;
	
	cout << "Ingrese cuantos estudiantes desea ingresar: ";
	cin >> n;
	
	estudiante.codigo = new int[n];
	estudiante.nombre = new string[n];
	estudiante.apellido = new string[n];
	estudiante.nota = new int *[n];
	estudiante.promedio = new float[n];
	
	for(int i = 0; i < n; i++){
		estudiante.nota[i] = new int[4];
	}
	
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
			cin >> *(*(estudiante.nota+i)+ii);
			notas += *(*(estudiante.nota+i)+ii);
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
	
	for(int i = 0; i < n; i ++){
		delete[] estudiante.nota[i];
	}
	
	delete[] estudiante.codigo;
	delete[] estudiante.nombre;
	delete[] estudiante.apellido;
	delete[] estudiante.nota;
	delete[] estudiante.promedio;
	
	system("Pause");
}
