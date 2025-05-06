#include <iostream>
#include <vector>
#include <iostream>
#include "gnuplot-iostream.h"
#include "math.h"

using namespace std;

void drawPhaseTrajectory(vector<double> x, vector<double> y, const char* title, const char* filename);

void drawTimeTrajectory(vector<double> t, vector<double> y, const char* title, const char* filename);

void visualizePhaseTrajectory(const vector<double> x, const vector<double> y, const char* title, const char* filename);

void visualizeTimeTrajectory(vector<double> t, vector<double> x, const char* title);

void plotMuVariation(double mu_start, double mu_end, double mu_step,
    double t_start, double t_end, double x0, double y0, 
    double h, const char* filename);