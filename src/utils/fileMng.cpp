
#include <iostream>     //imprimir por pantalla

#include "utils/genFunc.hpp"
#include "utils/fileMng.hpp"

string checkDataDir(char* userDir, string defDir) {
    string out = "";
    if (userDir == NULL && isDir(defDir).value) {
        out = defDir;
        cout << "[INFO] asignado directorio de datos por defecto: '";
        cout << defDir << "'\n";
    } else if (userDir != NULL && isDir(userDir).value) {
        out = userDir;
        cout << "[INFO] asignado directorio de datos manualmente: '";
        cout << userDir << "'\n";
    } else if (userDir != NULL && !isDir(userDir).value && isDir(defDir).value) {
        out = userDir;
        cout << "[FAIL] error al determinar el directorio de datos '";
        cout << userDir << "': " << isDir(userDir).err_no << "\n";
        cout << "[INFO] asignado directorio de datos por defecto: '";
        cout << defDir << "'\n";
    } else if (userDir != NULL && !isDir(userDir).value) {
        cout << "[FAIL] error al determinar el directorio de datos '";
        cout << userDir << "': " << isDir(userDir).err_no << "\n";
        exit(1);
    } else {
        cout << "[FAIL] error al determinar el directorio de datos '";
        cout << defDir << "': " << isDir(defDir).err_no << "\n";
        exit(1);
    }
    return out;
}
