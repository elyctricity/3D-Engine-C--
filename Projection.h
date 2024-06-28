#pragma once
#include <SFML/Graphics.hpp>
#include "Camera.h"

class Projection {
public:
    double NEAR;
    double FAR;
    double RIGHT;
    double LEFT;
    double TOP;
    double BOTTOM;
    double m00;
    double m11;
    double m22;
    double m32;
    double HH, HW;
    std::vector<std::vector<double>> projection_matrix;
    std::vector<std::vector<double>> to_screen_matrix;
    Projection(Camera* camera, double w_height, double w_width);
};