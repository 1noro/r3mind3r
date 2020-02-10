
#include "utils/genFunc.hpp"
#include "classes/Event.hpp"

Alta::Alta() {
    name = "";
    desc = "";
    ini_date = time(0);
    end_date = time(0);
}

Alta::Alta(string _name, string _desc, time_t _ini_date, time_t _end_date) {
    name = _name;
    desc = _desc;
    ini_date = _ini_date;
    end_date = _end_date;
}

Alta::Alta(string _line) {
    (void) _line;
    name = "";
    desc = "";
    ini_date = time(0);
    end_date = time(0);
}

void Alta::setName(string _name) {name = _name;}
string Alta::getName() {return name;}
void Alta::setDesc(string _desc) {desc = _desc;}
string Alta::getDesc() {return desc;}
void Alta::setIniDate(time_t _ini_date) {ini_date = _ini_date;}
string Alta::getIniDate() {return ini_date;}
void Alta::setEndDate(time_t _end_date) {end_date = _end_date;}
string Alta::getEndDate() {return end_date;}

string Alta::toFileLine() {return "toFileLine" + "\n";}
string Alta::toCliLine() {return "toCliLine" + "\n";}
string Alta::toCliDetail() {return "toCliDetail" + "\n";}
