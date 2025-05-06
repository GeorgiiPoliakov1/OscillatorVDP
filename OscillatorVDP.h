#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <iomanip>
#include <fstream>
#include "math.h"

using namespace std;

class OscillatorVDP {
    private:
        double mu;
        vector<double> t_all;
        vector<double> x_all;
        vector<double> y_all;

    public:
        OscillatorVDP(double mu) : mu(mu) {};
        pair<double, double> calculateSystem(double x, double y);

        void euler(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeEulerStep(double t, double x, double y, double h);

        void midpoint(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeMidpointStep(double t, double x, double y, double h);

        void RK4(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeRK4step(double t, double x, double y, double h);

        void implicitMidpoint(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeImMidpointStep(double t, double x, double y, double h, double tol=1e-8, int max_iter=100);

        void implicitTrapezoid(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeImTrapezoidStep(double t, double x, double y, double h, double tol=1e-8, int max_iter=100);
        
        void ABM2(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeABM2Step(double t_prev, double x_prev, double y_prev, double t, double x, double y, double h);
        
        void ABM4(double t_first, double t_final, double x_first, double y_first, double h, const char* filename);
        pair<double, double> makeABM4Step(vector<double> last_t, vector<double> last_x, vector<double> last_y, double h);

        void emHeunEulerAdaptive(double t, double t_final, double x, double y, double h, const char* filename, double tol=1e-6);
        
        //void emFehlbergRKAdaptive(double t, double t_final, double x, double y, double h, const char* filename, double tol=1e-6);

        vector<double> getTimeCoords();
        vector<double> getXCoords();
        vector<double> getYCoords();
};