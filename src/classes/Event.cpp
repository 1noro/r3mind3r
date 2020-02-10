
#include "utils/genFunc.hpp"
#include "classes/Event.hpp"

Event::Event() {
    name = "";
    desc = "";
    ini_date = time(0);
    end_date = time(0);
}

Event::Event(string _name, string _desc, time_t _ini_date, time_t _end_date) {
    name = _name;
    desc = _desc;
    ini_date = _ini_date;
    end_date = _end_date;
}

Event::Event(string _line) {
    (void) _line;
    name = "";
    desc = "";
    ini_date = time(0);
    end_date = time(0);
}

void Event::setName(string _name) {name = _name;}
string Event::getName() {return name;}
void Event::setDesc(string _desc) {desc = _desc;}
string Event::getDesc() {return desc;}
void Event::setIniDate(time_t _ini_date) {ini_date = _ini_date;}
time_t Event::getIniDate() {return ini_date;}
void Event::setEndDate(time_t _end_date) {end_date = _end_date;}
time_t Event::getEndDate() {return end_date;}

string Event::toFileLine() {return "toFileLine\n";}
string Event::toCliLine() {return "toCliLine\n";}
string Event::toCliDetail() {return "toCliDetail\n";}
