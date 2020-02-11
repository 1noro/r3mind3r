
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"
#include "classes/Event.hpp"
#include "r3mind3r.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printHelp() {
    cout << "# Ayuda:\n";
    cout << " " << autotab2mod("h, help", 7) << "Muestra esta ayuda\n";
    cout << " " << autotab2mod("n", 7) << "Nuevo evento\n";
    cout << " " << autotab2mod("l", 7) << "Listar eventos pendientes\n";
    cout << " " << autotab2mod("echo", 7) << "Devuelve lo escrito a continuación por pantalla\n";
    cout << "\n";
    cout << " " << autotab2mod("exit", 7) << "Salir\n";
}

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void newEvent() {cout << ">> newEvent\n";}
void listEvents(string in) {cout << ">> listEvents: " << in << "\n";}

void echo(vector<string> in) {
    for (int i = 1; i < (int) in.size() - 1; i++)
        cout << in.at(i) << " ";
    cout << in.at(in.size() - 1) << "\n";
}

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv) {
    // string fullDir = "/opt/archivosJava/altasEdad01cpp.dat";
    (void) argc;
    string fullDir = "";
    vector<string> user_in;

    vector<string> commands {
        "h", "help",
        "n",
        "l",
        "echo",
        "exit"
    };

    if (argv[1] == NULL) fullDir = "data/aa.dat";
        else fullDir = argv[1];

    do {
        user_in = readInput(commands);
        if (user_in.at(0) != "exit") {
            if (user_in.at(0) == "h") printHelp();
            else if (user_in.at(0) == "n") newEvent();
            else if (user_in.at(0) == "l") listEvents(user_in.at(1));
            else if (user_in.at(0) == "echo") echo(user_in);
        }
    } while (user_in.at(0) != "exit");
    cout << "Bye (; ;)\n";
    return 0;
}

// --- CODE UTILS --------------------------------------------------------------
// for (auto it = part.begin(); it != part.end(); it++)
//     cout << *it << "\n";
