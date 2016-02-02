#pragma once

#ifndef STATPARSER_PARSER
#define STATPARSER_PARSER

#include <string>
#include <fstream>
#include <vector>
#include "Team.h"

class Parser
{
private:
    std::vector<Team> teams;            // vector of teams parsed from the file
    std::ifstream file;                 // file to parse
    Team create_team();                 // Creates one team and returns it
    void add_team(Team& new_team);      // adds new team to vector if the team is unique

public:
    std::vector<Team> create_teams();   // Called to create the vector of teams
    Parser(std::string f);              // Constructor. Opens file to be parsed
    ~Parser();                          // Destructor. Destroys vector and closes file
};

#endif

