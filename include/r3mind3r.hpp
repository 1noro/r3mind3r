
#include <iostream>     //imprimir por pantalla
#include <fstream>      //leer archivos
#include <string>       //usar strings
#include <vector>       //usar arrays
#include <sstream>      //para hacer el split

using namespace std;    //para no tener que poner std:: delante de cada cosa

// --- VARIABLES GLOBALES ------------------------------------------------------
string finAltas = "fin";

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printMenu();
int readOpt(int max);

// --- LECTURAS Y VALIDACIONES DE FORMATO --------------------------------------
string readNombre();
int readEdad();

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void saveAlta(string line, string fullDir);
void altas(string fullDir);
void printListados(string fullDir);
void printMediaEdad(string fullDir);
void printNombreMayorMenor(string fullDir);

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv);
