
#include "utils/genFunc.hpp"
#include "classes/Altas.hpp"

Alta::Alta() {
    nombre = "";
    edad = 0;
}

Alta::Alta(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

Alta::Alta(string _line) {
    vector<string> part = split(_line, '#');
    nombre = part.at(0);
    edad = stoi(part.at(1));
}

void Alta::setNombre(string _nombre) {nombre = _nombre;}
string Alta::getNombre() {return nombre;}
void Alta::setEdad(int _edad) {edad = _edad;}
int Alta::getEdad() {return edad;}

string Alta::toFileLine() {return nombre + "#" + to_string(edad) + "\n";}
string Alta::toListados() {return autotab2(nombre) + to_string(edad) + "\n";}
