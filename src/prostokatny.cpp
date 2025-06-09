#include <vector>
#include <matplot/matplot.h>
#include "funkcje.hpp"
#include <cmath>

using namespace matplot;

void prostokatny(int& f, double& t_start, double& t_end, int& l_probek) {
    std::vector<double> x;
    std::vector<double> x_df;
    std::vector<double> y;
    std::vector<double> y_df;
    int  bufor;
    double dy;
    double czas_skoku = 0;//1/(2*f)
    double dt = (t_end-t_start)/l_probek;
    double t = t_start;
    

    x.push_back(t_start);
    bufor = 0;
    y.push_back(bufor);
    

    for (int i=1; i<l_probek; i++)
    {
        t=t+dt;
        czas_skoku+=dt;

        x.push_back(t);
        
        if (czas_skoku>=(1.0/(2.0*f)))
        {
            bufor = 1 - bufor;
            czas_skoku = 0; 
        }   

        y.push_back(bufor); 

        x_df.push_back(t);
        dy = (y[i]-y[i-1])/dt;
        y_df.push_back(dy);
       
    }
    figure();
    subplot(2,1,1);
    title("Prostokątny, f= " + std::to_string(f) + " Hz");
    xlabel("t[s]");
    ylabel("y");
    plot(x,y);
    auto ax1 = gca();
    ax1->ylim({-0.5, 1.5});
    subplot(2,1,2);
    title("Pochodna");
    xlabel("t[s]");
    ylabel("y");
    plot(x_df,y_df);
    auto ax2 = gca();
    ax2->ylim({-110, 110});
    show();
}
