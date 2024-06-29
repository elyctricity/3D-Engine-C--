#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrices.h"

class Camera {
public:
    vec3 position;
    vec3 forward;
    vec3 up;
    vec3 right;
    double h_fov;
    double v_fov;
    double near_plane;
    double far_plane;
    double moving_speed;
    double rotation_speed;
    Camera(vec3 pos, double w_height, double w_width);
    void control();
    void camera_yaw(double angle);
    void camera_pitch(double angle);
    std::vector<std::vector<double>> translate_matrix();
    std::vector<std::vector<double>> rotate_matrix();
    std::vector<std::vector<double>> camera_matrix();
};