#include "OscillatorVDP.h"

pair<double, double> OscillatorVDP::calculateSystem(double x, double y){
    double dxdt = y;
    double dydt = mu*(1-x*x)*y-x;
    return pair(dxdt, dydt);
}

void OscillatorVDP::euler(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    int steps = (t_final-t_first)/h;
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    pair<double, double> stepResult;
    for (int step = 0; step < steps; step++){
        stepResult = makeEulerStep(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeEulerStep(double t, double x, double y, double h){
    pair<double, double> results = calculateSystem(x, y);
    double k1 = results.first;
    double m1 = results.second;

    double x_new = x + k1*h;
    double y_new = y + m1*h;
    
    return pair(x_new, y_new);
}

void OscillatorVDP::midpoint(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    int steps = (t_final-t_first)/h;
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    pair<double, double> stepResult;
    for (int step = 0; step < steps; step++){
        stepResult = makeMidpointStep(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeMidpointStep(double t, double x, double y, double h){
    pair<double, double> results = calculateSystem(x, y);
    double k1 = results.first;
    double m1 = results.second;

    results = calculateSystem(x + (k1*h)/2, y + (m1*h)/2);
    double k2 = results.first; 
    double m2 = results.second;

    double x_new = x + k2*h;
    double y_new = y + m2*h;
    
    return pair(x_new, y_new);
}

void OscillatorVDP::RK4(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    int steps = (t_final-t_first)/h;
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    pair<double, double> stepResult;
    for (int step = 0; step < steps; step++){
        stepResult = makeRK4step(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeRK4step(double t, double x, double y, double h){
    pair<double, double> results = calculateSystem(x, y);
    double k1 = results.first;
    double m1 = results.second;

    results = calculateSystem(x + (k1*h)/2, y + (m1*h)/2);
    double k2 = results.first; 
    double m2 = results.second;

    results =  calculateSystem(x + (k2*h)/2, y + (m2*h)/2);
    double k3 = results.first;
    double m3 = results.second;

    results =  calculateSystem(x + k3*h, y + m3*h);
    double k4 = results.first;
    double m4 = results.second;

    double x_new = x + (k1 + 2*k2 + 2*k3 + k4)*h/6;
    double y_new = y + (m1 + 2*m2 + 2*m3 + m4)*h/6;
    
    return pair(x_new, y_new);
}

void OscillatorVDP::implicitMidpoint(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    int steps = (t_final-t_first)/h;
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    pair<double, double> stepResult;
    for (int step = 0; step < steps; step++){
        stepResult = makeImMidpointStep(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeImMidpointStep(double t, double x, double y, double h, double tol, int max_iter){
    pair<double, double> results = calculateSystem(x, y);
    
    double k1 = results.first;
    double m1 = results.second; 

    double x_mid; 
    double y_mid;

    pair<double, double> results_next;
    for (int i = 0; i < max_iter; i++){
        x_mid = x + 0.5*h*k1;
        y_mid = y + 0.5*h*m1;
        results_next = calculateSystem(x_mid, y_mid);
        double F1 = k1 - results_next.first;
        double F2 = m1 - results_next.second;

        if (sqrt(F1*F1+F2*F2) < tol){
            break;
        }

        vector<double> J = {1, -0.5*h, 0.5*(2*mu*x_mid*y_mid+1), 1-0.5*h*mu*(1-x_mid*x_mid)};
        double det = J[0]*J[3]-J[1]*J[2];
        double e = -F1;
        double f = -F2;

        double d1 = (e*J[3]-f*J[1])/det;
        double d2 = (J[0]*f-e*J[2])/det;

        k1 += d1;
        m1 += d2;
    }
    double x_new = x + h*k1;
    double y_new = y + h*m1; 
    return pair(x_new, y_new);

}

void OscillatorVDP::implicitTrapezoid(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    int steps = (t_final-t_first)/h;
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    pair<double, double> stepResult;
    for (int step = 0; step < steps; step++){
        stepResult = makeImTrapezoidStep(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeImTrapezoidStep(double t, double x, double y, double h, double tol, int max_iter){
    pair<double, double> results = calculateSystem(x, y);
    double k1 = results.first;
    double m1 = results.second; 

    double k2 = k1;
    double m2 = m1;

    double x_mid; 
    double y_mid;

    pair<double, double> results_next;
    for (int i = 0; i < max_iter; i++){
        x_mid = x + 0.5 * h * (k1+k2);
        y_mid = y + 0.5 * h * (m1+m2);
        results_next = calculateSystem(x_mid, y_mid);
        double F1 = k2 - results_next.first;
        double F2 = m2 - results_next.second;

        if (sqrt(F1*F1+F2*F2) < tol){
            break;
        }

        vector<double> J = {1, -0.5*h, 0.5*(2*mu*x_mid*y_mid+1), 1-0.5*h*mu*(1-x_mid*x_mid)};
        double det = J[0]*J[3]-J[1]*J[2];
        double e = -F1;
        double f = -F2;

        double d1 = (e*J[3]-f*J[1])/det;
        double d2 = (J[0]*f-e*J[2])/det;

        k2 += d1;
        m2 += d2;
    }
    double x_new = x + 0.5*h*(k1+k2);
    double y_new = y + 0.5*h*(m1+m2); 
    return pair(x_new, y_new);

}

void OscillatorVDP::ABM2(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    pair<double, double> stepResultRK4 = makeRK4step(t_first, x_first, y_first, h);
    t_all = {t_first, t_first+h};
    x_all = {x_first, stepResultRK4.first};
    y_all = {y_first, stepResultRK4.second};
    file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    pair<double, double> stepResult;
    int steps = (t_final-t_first)/h;
    for (int step = 1; step < steps; step++){
        stepResult = makeABM2Step(t_all[step-1], x_all[step-1], y_all[step-1],t_all[step], x_all[step], y_all[step], h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeABM2Step(double t_prev, double x_prev, double y_prev, double t, double x, double y, double h){
    pair<double, double> resultsForPrev = calculateSystem(x_prev, y_prev);
    pair<double, double> results = calculateSystem(x, y);
    double x_pred = x + 0.5*h*(3*results.first-resultsForPrev.first);
    double y_pred = y + 0.5*h*(3*results.second-resultsForPrev.second);

    
    pair<double, double> resultsPred = calculateSystem(x_pred, y_pred);
    results = calculateSystem(x, y);
    double x_new = x+0.5*h*(resultsPred.first+results.first);
    double y_new = y+0.5*h*(resultsPred.second+results.second);
    return pair(x_new, y_new); 
}

void OscillatorVDP::ABM4(double t_first, double t_final, double x_first, double y_first, double h, const char* filename){
    ofstream file;
    file.open(filename);
    t_all = {t_first};
    x_all = {x_first};
    y_all = {y_first};
    for (int i = 0; i<3; i++){
        pair<double, double> stepResultRK4 = makeRK4step(t_all.back(), x_all.back(), y_all.back(), h);
        x_all.push_back(stepResultRK4.first);
        y_all.push_back(stepResultRK4.second);
        t_all.push_back(t_all.back()+h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    int steps = (t_final-t_first)/h;
    pair<double, double> stepResult;
    for (int step = 3; step < steps; step++){
        vector<double> last_x = {x_all[step-3], x_all[step-2], x_all[step-1], x_all[step]};
        vector<double> last_y = {y_all[step-3], y_all[step-2], y_all[step-1], y_all[step]};
        vector<double> last_t = {t_all[step-3], t_all[step-2], t_all[step-1], t_all[step]};
        stepResult = makeABM4Step(last_t, last_x, last_y, h);
        x_all.push_back(stepResult.first);
        y_all.push_back(stepResult.second);
        t_all.push_back(t_all.back() + h);
        file << t_all.back() << " " <<  x_all.back() << " " << y_all.back() << endl;
    }
    file.close();
}

pair<double, double> OscillatorVDP::makeABM4Step(vector<double> last_t, vector<double> last_x, vector<double> last_y, double h){
    pair<double, double> resultsForPrev1 = calculateSystem(last_x[0], last_y[0]);
    pair<double, double> resultsForPrev2 = calculateSystem(last_x[1], last_y[1]);
    pair<double, double> resultsForPrev3 = calculateSystem(last_x[2], last_y[2]);
    pair<double, double> resultsForPrev4 = calculateSystem(last_x[3], last_y[3]);
    double x_pred = last_x[3] + (55*resultsForPrev4.first-59*resultsForPrev3.first+37*resultsForPrev2.first-9*resultsForPrev1.first)*h/24;
    double y_pred = last_y[3] + (55*resultsForPrev4.second-59*resultsForPrev3.second+37*resultsForPrev2.second-9*resultsForPrev1.second)*h/24;

    
    pair<double, double> resultsPred = calculateSystem(x_pred, y_pred);
    double x_new = last_x[3]+h*(9*resultsPred.first+19*resultsForPrev4.first-5*resultsForPrev3.first+resultsForPrev2.first)/24;
    double y_new = last_y[3]+h*(9*resultsPred.second+19*resultsForPrev4.second-5*resultsForPrev3.second+resultsForPrev2.second)/24;;
    return pair(x_new, y_new); 
}

void OscillatorVDP::emHeunEulerAdaptive(double t, double t_final, double x, double y, double h, const char* filename, double tol){
    ofstream file;
    file.open(filename);
    pair<double, double> stepResult;
    t_all = {t};
    x_all = {x};
    y_all = {y};
    double last_t = t;
    while (t < t_final){
        if (t + h > t_final) {
            h = t_final - t;
        }

        auto results = calculateSystem(x, y);
        double k1 = results.first;
        double m1 = results.second;

        results = calculateSystem(x + h * k1, y + h * m1);
        double k2 = results.first;
        double m2 = results.second;

        double x_heun = x + (h/2) * (k1 + k2);
        double y_heun = y + (h/2) * (m1 + m2);

        double x_euler = x + h * k1;
        double y_euler = y + h * m1;

        double error_x = x_heun - x_euler;
        double error_y = y_heun - y_euler;
        double error = std::sqrt(error_x * error_x + error_y * error_y);

        if (error <= tol || h < 1e-6) {
            t += h;
            x = x_heun;
            y = y_heun;
            t_all.push_back(t);
            x_all.push_back(x);
            y_all.push_back(y);
            if (t > last_t + 1e-6) { 
                file << t << " " << x << " " << y << std::endl;
                last_t = t;
            }

            if (error > 0) {
                h *= min(2.0, 0.8 * std::pow(tol/error, 0.5));
            }
        } else {
            h *= max(0.1, 0.8 * std::pow(tol/error, 0.5));
        }
    }
    file.close();
}

/* Работает слишком медленно
void OscillatorVDP::emFehlbergRKAdaptive(double t, double t_final, double x, double y, double h, const char* filename, double tol) {
    ofstream file;
    file.open(filename);
    pair<double, double> stepResult;
    t_all = {t};
    x_all = {x};
    y_all = {y};
    double last_t = t;
    while (t < t_final){
        if (t + h > t_final) {
            h = t_final - t;
        }

        auto results = calculateSystem(x, y);
        double k1 = results.first;
        double m1 = results.second;

        results = calculateSystem(x+h*0.5*k1, y+h*0.5*m1);
        double k2 = results.first;
        double m2 = results.second;

        results = calculateSystem(x+h*(k1/256+255*k2/256), y+h*(m1/256+255*m2/256));
        double k3 = results.first;
        double m3 = results.second;

        double x_rk2 = x + h*(k1/512+255*k2/256+k3/512);
        double y_rk2 = y + h*(m1/512+255*m2/256+m3/512);

        double x_rk1 = x + h*(k1/256+255*k2/256);
        double y_rk1 = y + h*(m1/256+255*m2/256);

        double error_x = x_rk2 - x_rk1;
        double error_y = y_rk2 - y_rk1;
        double error = std::sqrt(error_x * error_x + error_y * error_y);

        if (error <= tol || h < 1e-6) {
            t += h;
            x = x_rk2;
            y = y_rk2;
            t_all.push_back(t);
            x_all.push_back(x);
            y_all.push_back(y);
            if (t > last_t + 1e-6) { 
                file << t << " " << x << " " << y << std::endl;
                last_t = t;
            }

            if (error > 0) {
                h *= min(2.0, 0.8 * std::pow(tol/error, 1/3));
            }
        } else {
            h *= max(0.1, 0.8 * std::pow(tol/error, 1/3));
        }
    }
    file.close();
}
*/

vector<double> OscillatorVDP::getTimeCoords(){
    return t_all;
}

vector<double> OscillatorVDP::getXCoords(){
    return x_all;
}

vector<double> OscillatorVDP::getYCoords(){
    return y_all;
}