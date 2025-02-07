#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <map>
#include <cmath>
#include <algorithm>
#include "../core/PhysiCell.h"
#include "../modules/PhysiCell_standard_modules.h" 

/**
 *	\main rdrug:sensitivity
 *	\brief Custom module file for  prostate example
 * 
 *	\details Modules needed for the prostate example. This custom module can be used to study the inhibition of prostate cell lines
 *
 *
 *	\date 19/10/2020
 *	\author Annika Meert, BSC-CNS
 */

using namespace std;
using namespace PhysiCell;
using namespace BioFVM;

extern const vector<pair<string, int>> cell_line_ids;
extern const vector<pair<string, int>> drug_ids;
extern const vector<pair<string, string>> drug_targets;
extern const vector<pair<string, int>> half_lives;
extern const std::vector<std::pair<std::string, std::vector<double>>> csv_file;

std::vector<std::pair<std::string, std::vector<double>>> read_csv(std::string filename);

string get_value (const vector<pair<string, string>> dict, string key);
int get_value (const vector<pair<string, int>> dict, string key);
int get_index(string drug_name, string cell_line_name);
vector<double> get_drug_sensitivity_values_initial (string drug_name, string cell_line_name);
vector<double> get_drug_sensitivity_values (Cell* pCell, string drug_name, string cell_line_name);
double get_drug_concentration_from_level_initial (string cell_line, string drug_name, int conc_level, int num_of_conc_levels, int simulation_mode);

double get_x_from_conc(double x_conc, double max_conc);
double get_conc_from_x (double x, double max_conc);
double get_lx_from_x (double x, double max_conc);
double get_x_for_cell_viability (double xmid, double scale, double cell_viability);
double linear_mixed_model_function(double x, double max_conc, double xmid, double scale);
double get_cell_viability_for_drug_conc (Cell* pCell, double drug_conc, string cell_line, string drug_name, int index);