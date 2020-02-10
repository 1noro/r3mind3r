
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"
#include "classes/Altas.hpp"
#include "main.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printMenu() {
    cout << "\n";
    cout << "--- MENU ---\n";
    cout << " 1 - Altas\n";
    cout << " 2 - Listados\n";
    cout << " 3 - Media de edad\n";
    cout << " 4 - Nombre del mayor int argc, y menor (no rep.)\n";
    cout << "\n";
    cout << " 0 - Salir\n";
    cout << "\n";
}

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void saveAlta(string line, string fullDir) {
    ofstream f;
    f.open(fullDir, ios::app); //ios::app --> append to file
    f << line;
    f.close();
}

void altas(string fullDir) {
    Alta myAlta;
	string nombre = "";
	int edad = 0;
	do {
		cout << ">> Nueva alta:\n";
		nombre = readNombre(finAltas);
		if (nombre != finAltas) {
			edad = readEdad();
			myAlta = Alta(nombre, edad);
			saveAlta(myAlta.toFileLine(), fullDir);
            cout << " #GUARDADO: " << myAlta.toFileLine();
		}
	} while(nombre != finAltas);
}

void printListados(string fullDir) {
    Alta myAlta;
    ifstream f;
    string line = "";
    vector<string> part;

    cout << "--- LISTADOS ---\n";
    f.open(fullDir);
    if (!f) {
        cerr << "[FAIL] Unable to open file '" << fullDir << "'\n";
        exit(1); // call system to stop
    }
    while (f >> line) {
        myAlta = Alta(line);
        cout << myAlta.toListados();
    }
    f.close();
}

void printMediaEdad(string fullDir) {
    Alta myAlta;
    ifstream f;
    string line = "";
    vector<string> part;
    int cont = 0;
    int suma = 0;

    cout << "--- MEDIA ---\n";
    f.open(fullDir);
    if (!f) {
        cerr << "[FAIL] Unable to open file '" << fullDir << "'\n";
        exit(1); // call system to stop
    }
    while (f >> line) {
        myAlta = Alta(line);
        suma += myAlta.getEdad();
        cont++;
    }
    f.close();
    cout << "suma: " << suma << '\n';
    cout << "cont: " << cont << '\n';
    cout << "avg:  " << ((float) suma / (float) cont) << '\n';
}

void printNombreMayorMenor(string fullDir) {
    Alta myAlta;
    ifstream f;
    string line = "";
    vector<string> part;
    int eMax = 0;
    int eMin = 999;
    string nMax = "";
    string nMin = "";

    cout << "--- NOMBRES MAX Y MIN ---\n";
    f.open(fullDir);
    if (!f) {
        cerr << "[FAIL] Unable to open file '" << fullDir << "'\n";
        exit(1); // call system to stop
    }

    while (f >> line) {
        myAlta = Alta(line);
        if (myAlta.getEdad() > eMax) {
            nMax = myAlta.getNombre();
            eMax = myAlta.getEdad();
        }
        if (myAlta.getEdad() < eMin) {
            nMin = myAlta.getNombre();
            eMin = myAlta.getEdad();
        }
    }
    f.close();
    cout << "Mayor: " << nMax << " (" << eMax << ")" << '\n';
    cout << "Menor: " << nMin << " (" << eMin << ")" << '\n';
}

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv) {
    // string fullDir = "/opt/archivosJava/altasEdad01cpp.dat";
    (void) argc;
    string fullDir = "";
    if (argv[1] == NULL) fullDir = "aa.dat";
        else fullDir = argv[1];

    int opt = 0;
    do {
        printMenu();
        opt = readOpt(4);
        if (opt != 0) {
            if (opt == 1) altas(fullDir);
            else if (opt == 2) printListados(fullDir);
            else if (opt == 3) printMediaEdad(fullDir);
            else if (opt == 4) printNombreMayorMenor(fullDir);
        }
    } while (opt != 0);
    cout << "Bye (; ;)\n";
    return 0;
}

// --- CODE UTILS --------------------------------------------------------------
// for (auto it = part.begin(); it != part.end(); it++)
//     cout << *it << "\n";
