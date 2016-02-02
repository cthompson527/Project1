#pragma once

#ifndef STATPARSER_TEAM
#define STATPARSER_TEAM

#include <string>
#include <iostream>
#include <iomanip>

class Team
{
private:
    std::string name;               /* All the stats and information for the teams */
    int _asm, 
        _to, 
        _dto, 
        _pendif, 
        _rettd;
    double _pya, 
           _dpya, 
           _rya, 
           _drya, 
           _psm;
public:
    friend std::ostream& operator<<(std::ostream& os, const Team& dt);  // override output operator
    std::string getName() const;    // returns the name of the team
    int getASM() const;             // returns the team's actual scoring margin
    double getPSM() const;          // returns the team's predicted scoring margin
    Team(std::string n, int _a, double _py, double _dpy, double _ry, double _dry, int _t, int _dt, int _pen, int _ret);
    ~Team();                        // destructor (default)
};

inline std::ostream& operator<<(std::ostream& os, const Team& t) {
    os << std::setw(12) << std::left << t.getName() << "|" << std::setw(6) << std::right << t.getASM()  << " |" << std::setw(10) << t.getPSM();
    return os;
}


#endif
