#include "Visualization.h"
#include "OscillatorVDP.h"

void drawPhaseTrajectory(vector<double> x, vector<double> y, const char* title, const char* filename){
    Gnuplot gp;
    gp << "set terminal jpeg enhanced size 800,600\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title '" <<  title << "'\n";
    gp << "set xlabel 'x'\n";
    gp << "set ylabel 'y'\n";
    gp << "set grid\n";
    gp << "set key box\n";
    gp << "set xrange [" << *min_element(x.begin(), x.end()) - 0.5 
    << ":" << *max_element(x.begin(), x.end()) + 0.5 << "]\n";
    gp << "set yrange [" << *min_element(y.begin(), y.end()) - 0.5 
    << ":" << *max_element(y.begin(), y.end()) + 0.5 << "]\n";
    gp << "plot" 
       << gp.file1d(std::make_pair(x, y)) 
       << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black'"
       << std::endl;
}

void drawTimeTrajectory(vector<double> t, vector<double> x, const char* title, const char* filename){
    Gnuplot gp;
    gp << "set terminal jpeg enhanced size 800,600\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title '" <<  title << "'\n";
    gp << "set xlabel 't'\n";
    gp << "set ylabel 'x'\n";
    gp << "set grid\n";
    gp << "set key box\n";
    gp << "set xrange [" << *min_element(t.begin(), t.end()) - 0.5 
    << ":" << *max_element(t.begin(), t.end()) + 0.5 << "]\n";
    gp << "set yrange [" << *min_element(x.begin(), x.end()) - 0.5 
    << ":" << *max_element(x.begin(), x.end()) + 0.5 << "]\n";
    gp << "plot" 
       << gp.file1d(std::make_pair(t, x)) 
       << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black'"
       << std::endl;
}

void visualizePhaseTrajectory(const vector<double> x, const vector<double> y, const char* title, const char* filename) {
    Gnuplot gp;
    const int FRAME_DELAY = 50;
    const int POINTS_PER_FRAME = 100;
    gp << "set terminal gif animate delay 10 optimize size 800,600\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title '" <<  title << "'\n";
    gp << "set xlabel 'x'\n";
    gp << "set ylabel 'y'\n";
    gp << "set grid\n";
    gp << "set key box\n";
    gp << "set xrange [" << *min_element(x.begin(), x.end()) - 0.5 
       << ":" << *max_element(x.begin(), x.end()) + 0.5 << "]\n";
    gp << "set yrange [" << *min_element(y.begin(), y.end()) - 0.5 
       << ":" << *max_element(y.begin(), y.end()) + 0.5 << "]\n";
    vector<double> current_x, current_y;
    for(size_t i = 0; i < x.size()/5; ++i) {
        current_x.push_back(x[i]);
        current_y.push_back(y[i]);
        if(i % POINTS_PER_FRAME == 0 || i == x.size()-1) {
            gp << "plot" 
               << gp.file1d(make_pair(current_x, current_y)) 
               << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black',"
               << "'-' with points title 'Текущая позиция' pt 7 ps 1 lc 'red'\n";
            vector<double> last_x = {x[i]};
            vector<double> last_y = {y[i]};
            gp.send1d(make_pair(last_x, last_y));
            
            usleep(FRAME_DELAY);
        }
    }
    gp << "plot" 
       << gp.file1d(make_pair(x, y)) 
       << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black'\n";
}

void visualizeTimeTrajectory(const vector<double> t, const vector<double> x, const char* title, const char* filename) {
    Gnuplot gp;
    const int FRAME_DELAY = 500;
    const int POINTS_PER_FRAME = 10;
    gp << "set title 'Анимированный график временного ряда'\n";
    gp << "set xlabel 't'\n";
    gp << "set ylabel 'x'\n";
    gp << "set grid\n";
    gp << "set key box\n";
    gp << "set terminal gif animate delay 10 optimize size 800,600\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title '" <<  title << "'\n";
    gp << "set xrange [" << *min_element(t.begin(), t.end()) - 0.5 
       << ":" << *max_element(t.begin(), t.end()) + 0.5 << "]\n";
    gp << "set yrange [" << *min_element(x.begin(), x.end()) - 0.5 
       << ":" << *max_element(x.begin(), x.end()) + 0.5 << "]\n";
    vector<double> current_x, current_y;
    for(size_t i = 0; i < t.size(); ++i) {
        current_x.push_back(t[i]);
        current_y.push_back(x[i]);
        if(i % POINTS_PER_FRAME == 0 || i == t.size()-1) {
            gp << "plot" 
               << gp.file1d(make_pair(current_x, current_y)) 
               << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black',"
               << "'-' with points title 'Текущая позиция' pt 7 ps 1 lc 'red'\n";
            vector<double> last_x = {t[i]};
            vector<double> last_y = {x[i]};
            gp.send1d(make_pair(last_x, last_y));
            usleep(FRAME_DELAY);
        }
    }
    gp << "plot" 
       << gp.file1d(make_pair(t, x)) 
       << "with linespoints title '' lw 0.3 pt 7 ps 0.2 lc 'black'\n";
}

void plotMuVariation(double mu_start, double mu_end, double mu_step,
                    double t_start, double t_end, double x0, double y0, 
                    double h, const char* filename) {
    Gnuplot gp;
    
    std::vector<std::tuple<std::vector<double>, std::vector<double>, double>> all_trajectories;
    for(double mu = mu_start; mu <= mu_end; mu += mu_step) {
        OscillatorVDP oscillator(mu);
        oscillator.RK4(t_start, t_end, x0, y0, h, "../points/Animation.txt");
        all_trajectories.emplace_back(oscillator.getXCoords(), 
                                    oscillator.getYCoords(), 
                                    mu);
    }
    gp << "set terminal jpeg enhanced size 1200,800\n";
    gp << "set output '" << filename << "'\n";
    gp << "set title 'Фазовые траектории осциллятора Ван дер Поля'\n";
    gp << "set xlabel 'x'\n";
    gp << "set ylabel 'y (dx/dt)'\n";
    gp << "set grid\n";
    gp << "set key outside\n";
    gp << "set style line 1 lc palette\n";
    gp << "set palette defined (0 'red', 1 'blue', 2 'green', 3 'purple', 4 'orange')\n";
    gp << "set cbrange [" << mu_start << ":" << mu_end << "]\n";
    double xmin = INFINITY, xmax = -INFINITY;
    double ymin = INFINITY, ymax = -INFINITY;
    for(const auto& [x, y, mu] : all_trajectories) {
        auto [xcurr_min, xcurr_max] = std::minmax_element(x.begin(), x.end());
        auto [ycurr_min, ycurr_max] = std::minmax_element(y.begin(), y.end());
        xmin = std::min(xmin, *xcurr_min);
        xmax = std::max(xmax, *xcurr_max);
        ymin = std::min(ymin, *ycurr_min);
        ymax = std::max(ymax, *ycurr_max);
    }
    gp << "set xrange [" << xmin-0.1*(xmax-xmin) << ":" << xmax+0.1*(xmax-xmin) << "]\n";
    gp << "set yrange [" << ymin-0.1*(ymax-ymin) << ":" << ymax+0.1*(ymax-ymin) << "]\n";
    gp << "plot ";
    for(size_t i = 0; i < all_trajectories.size(); ++i) {
        const auto& [x, y, mu] = all_trajectories[i];
        gp << "'-' using 1:2:3 with lines title 'μ=" << mu 
           << "' lw 1.5 lc palette cb " << mu;
        if(i < all_trajectories.size()-1) gp << ", ";
    }
    gp << "\n";

    for(const auto& [x, y, mu] : all_trajectories) {
        std::vector<std::tuple<double, double, double>> data;
        for(size_t k = 0; k < x.size(); ++k) {
            data.emplace_back(x[k], y[k], mu);
        }
        gp.send1d(data);
    }

    gp << "set terminal wxt\n";
    gp << "set output\n";
}