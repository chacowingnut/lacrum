#pragma once

#include "../Eigen/Dense"


using Eigen::VectorXd;

void forward_euler_step(VectorXd (*func)(const VectorXd&), VectorXd& x, const double dt) {
    x += func(x) * dt;
}

void heun_step(VectorXd (*func)(const VectorXd&), VectorXd& x, const double dt) {
    VectorXd xbar = x + func(x) * dt;
    x += 0.5 * dt * (func(x) + func(xbar));
}

void rk4_step(VectorXd (*func)(const VectorXd&), VectorXd& x, const double dt) {
    const VectorXd k1 = func(x);
    const VectorXd k2 = func(x + 0.5 * k1 * dt);
    const VectorXd k3 = func(x + 0.5 * k2 * dt);
    const VectorXd k4 = func(x + k3 * dt);
    x += (k1 + 2 * k2 + 2 * k3 + k4) * dt / 6.0;
}