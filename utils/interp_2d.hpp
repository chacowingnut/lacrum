#pragma once

#include "../Eigen/Dense"
#include <algorithm>


double interp_2d(const Eigen::MatrixXd& data, double x, double y) {
    double xi = std::min(std::max(x, 0.0), data.cols() - 1.0);
    double yi = std::min(std::max(y, 0.0), data.rows() - 1.0);

    int x1 = floor(xi);
    int x2 = ceil(xi);
    int y1 = floor(yi);
    int y2 = ceil(yi);

    double xFrac = xi - x1;
    double yFrac = yi - y1;

    double q11 = data(y1, x1);
    double q12 = data(y1, x2);
    double q21 = data(y2, x1);
    double q22 = data(y2, x2);

    double result = q11 * (1 - xFrac) * (1 - yFrac) +
                    q12 * xFrac * (1 - yFrac) +
                    q21 * (1 - xFrac) * yFrac +
                    q22 * xFrac * yFrac;

    return result;
}
