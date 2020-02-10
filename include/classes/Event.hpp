
#include <string>       //usar strings
#include <vector>       //usar arrays
#include <ctime>        //para el struct time_t de C

using namespace std;    //para no tener que poner std:: delante de cada cosa

class Event {
    private:
        string name;
        string desc;
        time_t ini_date;
        time_t end_date;

    public:
        Event();
        Event(string _name, string _desc, time_t _ini_date, time_t _end_date);
        Event(string _code_line);

        void setName(string _name);
        string getName();
        void setDesc(string _desc);
        string getDesc();
        void setIniDate(time_t _ini_date);
        time_t getIniDate();
        void setEndDate(time_t _end_date);
        time_t getEndDate();

        string toFileLine();
        string toCliLine();
        string toCliDetail();
};
