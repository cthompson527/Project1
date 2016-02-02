#include <iostream>
#include <cmath>
#include "Team.h"
#include "Parser.h"

bool sort(std::vector<Team>& teams);
void swap(std::vector<Team>& teams, int team1, int team2);
void solve_bar_values(const std::vector<Team>& teams, double& x_bar, double& y_bar);
void solve_var_values(const std::vector<Team>& teams, const double x_bar, const double y_bar, double& var_x, double& var_y);
double solve_r_value(const std::vector<Team>& teams, const double x_bar, const double y_bar, const double x_std, const double y_std);

int main() {
    Parser parser("../Input File/315Assignment1.txt");
    std::vector<Team> teams = parser.create_teams();
    sort(teams);

    std::cout << std::setw(13) << std::left << "Team Name" << std::setw(6) << std::right << "ASM" << std::setw(13) << "PSM\n";
    for (int i = 0; i < teams.size(); i++) {
        std::cout << teams[i] << std::endl;
    }

    double asm_bar, psm_bar, asm_var, psm_var, asm_std, psm_std, r_value = 0.0;
    solve_bar_values(teams, asm_bar, psm_bar);
    solve_var_values(teams, asm_bar, psm_bar, asm_var, psm_var);
    asm_std = std::sqrt(asm_var);
    psm_std = std::sqrt(psm_var);
    r_value = solve_r_value(teams, asm_bar, psm_bar, asm_std, psm_std);

    std::cout << "The r-value of the data is " << r_value << std::endl;
    return 0;
}

/**
 * implementing simple bubble sort to sort teams based on name
 */
bool sort(std::vector<Team>& teams)
{
    for (int i = 0; i < teams.size(); i++) {
        for (int j = i+1; j < teams.size(); j++) {
            if (strcmp(teams[i].getName().c_str(), teams[j].getName().c_str()) > 0) {
                swap(teams, i, j);
            } else if (strcmp(teams[i].getName().c_str(), teams[j].getName().c_str()) == 0) {
                std::cerr << "An error occurred" << std::endl;
                return false;
            }
        }
    }
    return true;
}

/**
 * swap the two teams in the vector
 */
void swap(std::vector<Team>& teams, int team1, int team2)
{
    Team temp = teams[team1];
    teams[team1] = teams[team2];
    teams[team2] = temp;
}

/**
 * Find the bar value
 */
void solve_bar_values(const std::vector<Team>& teams, double& x_bar, double& y_bar)
{
    for (int i = 0; i < teams.size(); i++) {
        x_bar += teams[i].getASM();
        y_bar += teams[i].getPSM();
    }
    x_bar = x_bar / teams.size();
    y_bar = y_bar / teams.size();
}

/**
 * Find the sample variance value
 */
void solve_var_values(const std::vector<Team>& teams, const double x_bar, const double y_bar, double& var_x, double& var_y)
{
    for (int i = 0; i < teams.size(); i++) {
        var_x += ((teams[i].getASM()-x_bar) * (teams[i].getASM()-x_bar));
        var_y += ((teams[i].getPSM()-y_bar) * (teams[i].getPSM()-y_bar));
    }
    var_x = var_x / (teams.size()-1);
    var_y = var_y / (teams.size()-1);
}

/**
 * Find the r_value of the data and return r
 */
double solve_r_value(const std::vector<Team>& teams, const double x_bar, const double y_bar, const double x_std, const double y_std)
{
    double internal_sum = 0;
    for (int i = 0; i < teams.size(); i++) {
        double x = (teams[i].getASM() - x_bar) / x_std;
        double y = (teams[i].getPSM() - y_bar) / y_std;
        internal_sum += x*y;
    }
    return internal_sum / (teams.size()-1);
}