#include "lv.h"

LotkaVolterra::LotkaVolterra(double a, double b, double c, double e,
                             double x_init, double y_init, 
                             double dt, double max_time): 
    _a(a), _b(b), _c(c), _e(e), 
    _x_init(x_init), _y_init(y_init), 
    _dt(dt), _max_time(max_time) 
{}


int LotkaVolterra::dim_singles() {

    return (int) ceil(_max_time / _dt);

}

std::pair<int, int> LotkaVolterra:: dim_combi() {

    return std::make_pair( (int) ceil(_max_time / _dt), 3 );

}

void LotkaVolterra::run_singles(double *ts, int len_ts, 
                          double *xs, int len_xs, 
                          double *ys, int len_ys) {

    int const end = std::min(len_ts, std::min(len_xs, len_ys));
    
    double t = 0.0;
    double x = _x_init;
    double y = _y_init;
    
    ts[0] = t;
    xs[0] = x;
    ys[0] = y;

    for (int i = 1; i < end; ++i) {
        t = t + _dt;
        x = x + (_a*x - _b*x*y)*_dt;
        y = y + (-_c*y + _e*x*y)*_dt;

        ts[i] = t;
        xs[i] = x;
        ys[i] = y;
    }

}


void LotkaVolterra::run_combi(double *out, int len, int wid) {

    double t = 0.0;
    double x = _x_init;
    double y = _y_init;
    
    out[0] = t;
    out[1] = x;
    out[2] = y;

    for (int i = 1; i < len; ++i) {
        t = t + _dt;
        x = x + (_a*x - _b*x*y)*_dt;
        y = y + (-_c*y + _e*x*y)*_dt;

        out[i*wid + 0] = t;
        out[i*wid + 1] = x;
        out[i*wid + 2] = y;
    }

}

