#include "Camera.h"

Camera::Camera(vec3 pos, double w_height, double w_width) {
    position = pos;
    forward.x = 0; forward.y = 0; forward.z = 1; // Forward unit vector of camera. Facing towards positive z.
    up.x = 0; up.y = 1; up.z = 0;                    // Up unit vector of camera. Facing towards positive y.
    right.x = 1; right.y = 0; right.z = 0;         // Right unit vector of camera. Facing towards positive x.
    h_fov = M_PI / 3;
    v_fov = h_fov * (w_height / w_width);
    near_plane = 0.1;
    far_plane = 100;
    moving_speed = 0.02;
    rotation_speed = 0.01;
}

void Camera::control() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        position = vec3_sub(position, (vec3_mul_scalar(right, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        position = vec3_add(position, (vec3_mul_scalar(right, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        position = vec3_add(position, (vec3_mul_scalar(forward, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        position = vec3_sub(position, (vec3_mul_scalar(forward, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        position = vec3_add(position, (vec3_mul_scalar(up, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        position = vec3_sub(position, (vec3_mul_scalar(up, moving_speed)));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        camera_yaw(-rotation_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        camera_yaw(rotation_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        camera_pitch(-rotation_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        camera_pitch(rotation_speed);
    }
}

void Camera::camera_yaw(double angle) {
    std::vector<std::vector<double>> rotate = mat_rotate_y(angle);
    forward = vec3_mat_mul(forward, rotate);
    right = vec3_mat_mul(right, rotate);
    up = vec3_mat_mul(up, rotate);
}

void Camera::camera_pitch(double angle) {
    std::vector<std::vector<double>> rotate = mat_rotate_x(angle);
    forward = vec3_mat_mul(forward, rotate);
    right = vec3_mat_mul(right, rotate);
    up = vec3_mat_mul(up, rotate);
}

std::vector<std::vector<double>> Camera::translate_matrix() {
    double x = position.x;
    double y = position.y;
    double z = position.z;
    std::vector<std::vector<double>> translation_matrix = {
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1}
    };
    return translation_matrix;
}

std::vector<std::vector<double>> Camera::rotate_matrix() {
    double rx = right.x;
    double ry = right.y;
    double rz = right.z;
    double fx = forward.x;
    double fy = forward.y;
    double fz = forward.z;
    double ux = up.x;
    double uy = up.y;
    double uz = up.z;
    std::vector<std::vector<double>> rotation_matrix = {
        {rx, ux, fx, 0},
        {ry, uy, fy, 0},
        {rz, uz, fz, 0},
        {0, 0, 0, 1}
    };
    return rotation_matrix;
}

std::vector<std::vector<double>> Camera::camera_matrix() {
    return mat_mul(rotate_matrix(), translate_matrix());
}