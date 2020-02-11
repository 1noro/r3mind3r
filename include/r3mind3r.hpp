
#include <iostream>     //imprimir por pantalla
#include <fstream>      //leer archivos
#include <string>       //usar strings
#include <vector>       //usar arrays
#include <sstream>      //para hacer el split

using namespace std;    //para no tener que poner std:: delante de cada cosa

// --- VARIABLES GLOBALES ------------------------------------------------------
string finAltas = "fin";

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printHelp();

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void newEvent();
void listEvents();
void echo(vector<string> in);

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv);
