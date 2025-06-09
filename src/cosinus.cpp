#include <vector>
#include <matplot/matplot.h>
#include "funkcje.hpp"
#include <cmath>

using namespace matplot;

void cosinus(int& f, double& t_start, double& t_end, int& l_probek) {
    std::vector<double> x;
    std::vector<double> x_df;
    std::vector<double> y;
    std::vector<double> y_df;
    double  bufor;
    double PI = 3.14159265358979323846;
    double dt = (t_end-t_start)/l_probek;
    double t = t_start+dt;
    

    x.push_back(t_start);
    bufor = cos(2*PI*f*t);
    y.push_back(bufor);


    for (int i=1; i<l_probek; i++)
    {
        x.push_back(t);
        bufor = cos(2*PI*f*t);
        y.push_back(bufor);
        x_df.push_back(t);
        bufor = (y[i]-y[i-1])/dt;
        y_df.push_back(bufor);
        t=t+dt;
    }

    figure();
    subplot(2,1,1);
    title("Cosinus, f= " + std::to_string(f) + " Hz");
    xlabel("t[s]");
    ylabel("y");
    plot(x,y);
    subplot(2,1,2);
    title("Pochodna");
    xlabel("t[s]");
    ylabel("y");
    plot(x_df,y_df);
    show();
}