
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"
#include "classes/Event.hpp"
#include "r3mind3r.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printHelp() {
    cout << " h\tMuestra esta ayuda\n";
    cout << " n\tNuevo evento\n";
    cout << " l\tListar eventos pendientes\n";
    cout << "\n";
    cout << " exit\tSalir\n";
}

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void newEvent() {cout << ">> newEvent\n";}
void listEvents(string in) {cout << ">> listEvents: " << in << "\n";}

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv) {
    // string fullDir = "/opt/archivosJava/altasEdad01cpp.dat";
    (void) argc;
    string fullDir = "";
    vector<string> user_in;

    vector<string> commands {"h", "n", "l", "exit"};

    if (argv[1] == NULL) fullDir = "data/aa.dat";
        else fullDir = argv[1];

    do {
        user_in = readInput(commands);
        if (user_in.at(0) != "exit") {
            if (user_in.at(0) == "h") printHelp();
            else if (user_in.at(0) == "n") newEvent();
            else if (user_in.at(0) == "l") listEvents(user_in.at(1));
        }
    } while (user_in.at(0) != "exit");
    cout << "Bye (; ;)\n";
    return 0;
}

// --- CODE UTILS --------------------------------------------------------------
// for (auto it = part.begin(); it != part.end(); it++)
//     cout << *it << "\n";
