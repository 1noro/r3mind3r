
#include "structs/def.hpp"
#include "utils/genFunc.hpp"
#include "utils/userInput.hpp"
#include "classes/Event.hpp"
#include "r3mind3r.hpp"

// --- INTERFAZ DE USUARIO -----------------------------------------------------
void printHelp() {
    cout << "# Ayuda:\n";
    cout << " " << autotab2mod("h, help", 7) << "Muestra esta ayuda\n";
    cout << " " << autotab2mod("n, new", 7) << "Nuevo evento\n";
    cout << " " << autotab2mod("l, list", 7) << "Listar eventos pendientes\n";
    cout << " " << autotab2mod("echo", 7) << "Devuelve lo escrito a continuación por pantalla\n";
    cout << "\n";
    cout << " " << autotab2mod("exit", 7) << "Salir\n";
}

// --- FUNCIONES GENÉRICAS -----------------------------------------------------
void newEvent() {cout << ">> newEvent\n";}
void listEvents() {cout << ">> listEvents" << "\n";}

void echo(vector<string> in) {
    if (in.size() > 1) {
        for (int i = 1; i < (int) in.size() - 1; i++)
            cout << in.at(i) << " ";
        cout << in.at(in.size() - 1) << "\n";
    }
}

// --- MAIN --------------------------------------------------------------------
int main(int argc, char** argv) {
    // string fullDir = "/opt/archivosJava/altasEdad01cpp.dat";
    (void) argc;
    string fullDir = "";
    vector<string> user_in;
    string cmm = "";

    vector<string> commands {
        "h", "help",
        "n",
        "new",
        "l",
        "list",
        "echo",
        "exit"
    };

    cout << "isDir '/': " << isDir("/").value << ", " << isDir("/").err_no << "\n";
    cout << "isDir 'data': " << isDir("data").value << ", " << isDir("data").err_no << "\n";
    cout << "isDir '/jj': " << isDir("/jj").value << ", " << isDir("/jj").err_no << "\n";
    cout << "isDir 'LICENSE': " << isDir("LICENSE").value << ", " << isDir("LICENSE").err_no << "\n";

    if (argv[1] == NULL) fullDir = "data/aa.dat";
        else fullDir = argv[1];

    do {
        user_in = readInput(commands);
        cmm = user_in.at(0);
        if (cmm != "exit") {
            if (cmm == "h" || cmm == "help") printHelp();
            else if (cmm == "n" || cmm == "new") newEvent();
            else if (cmm == "l" || cmm == "list") listEvents();
            else if (cmm == "echo") echo(user_in);
        }
    } while (user_in.at(0) != "exit");
    cout << "Bye (; ;)\n";
    return 0;
}

// --- CODE UTILS --------------------------------------------------------------
// for (auto it = part.begin(); it != part.end(); it++)
//     cout << *it << "\n";
