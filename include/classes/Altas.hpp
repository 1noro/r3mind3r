
#include <string>       //usar strings
#include <vector>       //usar arrays

using namespace std;    //para no tener que poner std:: delante de cada cosa

class Alta {
    private:
        string nombre;
        int edad;

    public:
        Alta();
        Alta(string _nombre, int _edad);
        Alta(string _line);

        void setNombre(string _nombre);
        string getNombre();
        void setEdad(int _edad);
        int getEdad();

        string toFileLine();
        string toListados();
};
