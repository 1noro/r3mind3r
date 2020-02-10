
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
// falta por acabar (repetir mientras no sea un comado valido)
int readOpt() {
	string out = "";
	do {
		cout << "> ";
		cin >> out;
	} while (out < 0 || out > max);
    cout << "\n";
	return out;
}

// --- LECTURAS Y VALIDACIONES DE FORMATO --------------------------------------
string readNombre(string finAltas) {
    string out = "";
    do {
        cout << " Nombre (15 char max); '" << finAltas << "' para acabar: ";
        cin >> out;
    } while (out != finAltas && out.length() > 15);
    return out;
}

int readEdad() {
    string edad_str = "";
	int edad = 0;
	bool continuar = true;

	do {
		cout << " Edad: ";
		cin >> edad_str;
		if (isNumber(edad_str)) {
            edad = stoi(edad_str);
            continuar = false;
        }
	} while(continuar);

	return edad;
}
