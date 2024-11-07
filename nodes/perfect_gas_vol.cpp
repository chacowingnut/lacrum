#include <iostream>

struct PerfectGasVol
{
    double p;
    double h;
    double T;
    double rho;
    double u;
    double cp;
    double power_net = 0.0;
    double mdot_net = 0.0;
    const double R = 296.8;
    const double gamma = 1.4;
    const double V;

    PerfectGasVol(double p_initial, double T_initial, double V) : p(p_initial), T(T_initial), V(V)
    {
        cp = R / (1 - 1 / gamma);
        h = T * cp;
        rho = p / R / T;
        u = T * cp / gamma;
    }

    void rhou_update(double rho, double u)
    {
        rho = rho;
        u = u;
        T = u / (cp / gamma);
        p = rho * R * T;
        h = T * cp;
    }

    void say()
    {
        std::cout << "p " << p << std::endl;
        std::cout << "T " << T << std::endl;
        std::cout << "rho " << rho << std::endl;
    }
};

int main()
{
    PerfectGasVol foo(1e5, 273, 1);
    foo.say();
    return 0;
}