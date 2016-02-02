#include "Team.h"

/**
 * Returns the team's name
 */
std::string Team::getName() const
{
    return name;
}

/**
 * returns the actual scoring margin of the team
 */
int Team::getASM() const
{
    return _asm;
}

/**
 * Returns the predicted scoring margin of the team
 */
double Team::getPSM() const
{
    return _psm;
}

/**
 * Constructor. Sets up all the stats
 */
Team::Team(std::string n, int _a, double _py, double _dpy, double _ry, double _dry, int _t, int _dt, int _pen, int _ret)
{
    name = n;
    _asm = _a;
    _to = _t;
    _dto = _dt;
    _pendif = _pen;
    _rettd = _ret;
    _pya = _py;
    _dpya = _dpy;
    _rya = _ry;
    _drya = _dry;
    _psm = 3.17 * _rettd - 0.06 * _pendif + 61.67 * _pya + 26.44 * _rya - 2.77 * _to - 67.5 * _dpya - 22.79 * _drya + 3.49 * _dto;
}

/**
 * Default destructor
 */
Team::~Team()
{

}

