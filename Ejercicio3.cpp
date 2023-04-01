#include <iostream>

using namespace std;

const char *nombre_archivo = "archivo.dat";

struct Estudiante{
	int *codigo;
	string *nombre;
	string *apellido;
	int **nota;
	float *promedio;
};

void Crear();
void Leer();

main(){
	Estudiante estudiante;
	int notas = 0, n;
	bool simon = true;
	
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
	
	if(simon = true){
		Crear();
		Leer();
	}
	
	system("Pause");
}

void Crear(){
   FILE* archivo = fopen(nombre_archivo, "a+b");
   char res;
   Estudiante estudiante;
   bool simon = true;
   
   cout << "Desea ingresar otro estudiante (s/n): ";
   cin >> res;

   while(res=='s' || res == 'S'){
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
			cout << "________________________" << endl;
		} else {
			cout << "Estudiante reprobado." << endl;
			cout << "________________________" << endl;
		}
	}
	
	if(simon = true){
		Crear();
		Leer();
	}

      fwrite(estudiante.codigo, sizeof(int), 1, archivo);
      fwrite(estudiante.nombre->c_str(), sizeof(char), estudiante.nombre->length(), archivo);
      fwrite("\n", sizeof(char), 1, archivo);
      fwrite(estudiante.apellido->c_str(), sizeof(char), estudiante.apellido->length(), archivo);
      fwrite("\n", sizeof(char), 1, archivo);
      for(int i=0; i<4; i++){
         fwrite(estudiante.nota[i], sizeof(int), 1, archivo);
      }
      fwrite(estudiante.promedio, sizeof(float), 1, archivo);
      
      char res;
      cout << "Desea ingresar otro estudiante (s/n): ";
      cin >> res;
   }

   fclose(archivo);
   Leer();
}


void Leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	if(!archivo){
		archivo = fopen(nombre_archivo, "w+b");
	}
	
	Estudiante estudiante;
	int id = 0;
	fread(&estudiante, sizeof(Estudiante), 1, archivo);
	cout << "__________________________________________________" << endl;
	cout << "ID  " << "|" << " Nombres " << "|"<< " Apellidos " << "|" << " Promedio" << endl;
	
	do{
	   cout << "| " << estudiante.codigo << " | " << estudiante.nombre << " | " << estudiante.apellido << " | " << *(estudiante.promedio) << endl;
	}while(fread(&estudiante, sizeof(Estudiante), 1, archivo) && !feof(archivo));
	
	fclose(archivo);
}

