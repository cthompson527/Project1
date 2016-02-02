#include "Parser.h"

/**
 * Constructor. Opens file to be parsed
 */
Parser::Parser(std::string f)
{
    file.open(f.c_str(), std::ifstream::in);
    if (!file.is_open()) {
        exit(1);
    }
}

/**
 * Destructor. Destroys vector and closes file
 */
Parser::~Parser()
{
    teams.empty();
    file.close();
}

/**
 * Called to create the vector of teams
 */
std::vector<Team> Parser::create_teams()
{
    std::string input;
    while (!file.eof()) {
        Team team = create_team();
        add_team(team);
    }
    return teams;
}

/**
 * Private function. Creates one team and returns it
 */
Team Parser::create_team()
{
    std::string name = "";
    int _asm, _to, _dto, _pendif, _rettd;
    double _pya, _dpya, _rya, _drya;
    file >> name >> _asm >> _pya >> _dpya >> _rya >> _drya >> _to >> _dto >> _pendif >> _rettd;
    if (!name.empty())
        return Team(name, _asm, _pya, _dpya, _rya, _drya, _to, _dto, _pendif, _rettd);
}

/**
 * add_team(Team) receives a new team to add to teams. First checks if the new_team is unique,
 * then adds to the teams vector
 */
void Parser::add_team(Team& new_team)
{
    bool team_is_unique = true;
    for (int i = 0; i < teams.size(); i++) {
        if (teams[i].getName().compare(new_team.getName()) == 0) {
            team_is_unique = false;
            break;
        }
    }
    if (team_is_unique)
        teams.push_back(new_team);
}
