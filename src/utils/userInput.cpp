
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
vector<string> readInput(vector<string> commands) {
	string user_in_str = "";
	vector<string> user_in;
	do {
		cout << "> ";
		cin >> user_in_str;
		user_in = split(user_in_str, '#');
	} while (!count(commands.begin(), commands.end(), user_in.at(0)));
	return user_in;
}

// --- LECTURAS Y VALIDACIONES DE FORMATO --------------------------------------
// string readNombre(string finAltas) {
//     string out = "";
//     do {
//         cout << " Nombre (15 char max); '" << finAltas << "' para acabar: ";
//         cin >> out;
//     } while (out != finAltas && out.length() > 15);
//     return out;
// }
//
// int readEdad() {
//     string edad_str = "";
// 	int edad = 0;
// 	bool continuar = true;
//
// 	do {
// 		cout << " Edad: ";
// 		cin >> edad_str;
// 		if (isNumber(edad_str)) {
//             edad = stoi(edad_str);
//             continuar = false;
//         }
// 	} while(continuar);
//
// 	return edad;
// }
