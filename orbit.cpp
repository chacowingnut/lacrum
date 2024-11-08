#include <iostream>
#include <cstdio>
#include "Eigen/Dense"
#include "utils/csv.hpp"
#include "numerical_methods/explicit_integrators.hpp"

using Eigen::VectorXd;

VectorXd xdot(const VectorXd& x) {
    VectorXd r = x.segment(0, 2);
    VectorXd a(2);
    double rmag = r.norm();
    a = -6.6743e-11 * 5.972e24 / (rmag * rmag * rmag) * r;
    VectorXd xdot(4);
    xdot << x[2], x[3], a[0], a[1];
    return xdot;
}

int main() {
    double r_earth = 6378e3;
    double h = 400e3;
    VectorXd x(4);
    x << 0, r_earth + h, -10.753e3, 0;

    double t = 0;
    double dt = 1;

    CSVTable out;
    out.add_col("time", &t);
    out.add_col("x", &x[0]);
    out.add_col("y", &x[1]);
    out.add_row();

    while (t <= 16 * 24 * 3600) {
        std::printf("\r%.1f      ", t / 3600);
        t += dt;
        rk4_step(xdot, x, dt);
        out.add_row();
    }
    std::cout << std::endl;
    out.write("deleteme.csv");
    return 0;
}