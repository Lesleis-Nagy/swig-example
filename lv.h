#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>

class LotkaVolterra {

    public:

        LotkaVolterra(double a, double b, double c, double e, 
                      double x_init, double y_init, 
                      double dt, double max_time);

        int dim_singles(); 

        std::pair<int, int> dim_combi();

        void run_singles(double *ts, int len_ts, 
                         double *xs, int len_xs, 
                         double *ys, int len_ys);

        void run_combi(double *out, int len, int wid);


    private:

        double _a;
        double _b;
        double _c;
        double _e;
        double _x_init;
        double _y_init;
        double _dt;
        double _max_time;

};

