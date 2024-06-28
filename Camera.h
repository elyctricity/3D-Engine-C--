#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrices.h"

class Camera {
public:
    std::vector<std::vector<double>> position;
    std::vector<std::vector<double>> forward;
    std::vector<std::vector<double>> up;
    std::vector<std::vector<double>> right;
    double h_fov;
    double v_fov;
    double near_plane;
    double far_plane;
    double moving_speed;
    double rotation_speed;
    Camera(std::vector<std::vector<double>> pos, double w_height, double w_width);
    void control();
    void camera_yaw(double angle);
    void camera_pitch(double angle);
    std::vector<std::vector<double>> translate_matrix();
    std::vector<std::vector<double>> rotate_matrix();
    std::vector<std::vector<double>> camera_matrix();
};