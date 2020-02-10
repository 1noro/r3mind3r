
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"
#include "classes/Event.hpp"
#include "r3mind3r.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printHelp() {
    cout << "\n";
    cout << " h\tMuestra esta ayuda\n";
    cout << " n\tNuevo evento\n";
    cout << " l\tListar eventos pendientes\n";
    cout << "\n";
    cout << " exit\tSalir\n";
    cout << "\n";
}

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void newEvent() {cout << ">> newEvent\n";}
void listEvents() {cout << ">> listEvents\n";}

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv) {
    // string fullDir = "/opt/archivosJava/altasEdad01cpp.dat";
    (void) argc;
    string fullDir = "";

    vector<string> commands {"h", "n", "l", "exit"};

    if (argv[1] == NULL) fullDir = "data/aa.dat";
        else fullDir = argv[1];

    string opt = "";
    do {
        opt = readOpt(commands);
        if (opt != "exit") {
            if (opt == "h") printHelp();
            else if (opt == "n") newEvent();
            else if (opt == "l") listEvents();
        }
    } while (opt != "exit");
    cout << "Bye (; ;)\n";
    return 0;
}

// --- CODE UTILS --------------------------------------------------------------
// for (auto it = part.begin(); it != part.end(); it++)
//     cout << *it << "\n";
