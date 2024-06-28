#include "Camera.h"

Camera::Camera(std::vector<std::vector<double>> pos, double w_height, double w_width) {
    position = pos;
    position.push_back({1.0});
    forward = {{0}, {0}, {1}, {1}};                   // Forward unit vector of camera. Facing towards positive z.
    up = {{0}, {1}, {0}, {1}};                        // Up unit vector of camera. Facing towards positive y.
    right = {{1}, {0}, {0}, {1}};                     // Right unit vector of camera. Facing towards positive x.
    h_fov = M_PI / 3;
    v_fov = h_fov * (w_height / w_width);
    near_plane = 0.1;
    far_plane = 100;
    moving_speed = 0.02;
    rotation_speed = 0.01;
}

void Camera::control() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        position = vec_sub(position, (vec_mul_scalar(right, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        position = vec_add(position, (vec_mul_scalar(right, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        position = vec_add(position, (vec_mul_scalar(forward, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        position = vec_sub(position, (vec_mul_scalar(forward, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        position = vec_add(position, (vec_mul_scalar(up, moving_speed)));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        position = vec_sub(position, (vec_mul_scalar(up, moving_speed)));
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
    forward = mat_mul(rotate, forward);
    right = mat_mul(rotate, right);
    up = mat_mul(rotate, up);
}

void Camera::camera_pitch(double angle) {
    std::vector<std::vector<double>> rotate = mat_rotate_x(angle);
    forward = mat_mul(rotate, forward);
    right = mat_mul(rotate, right);
    up = mat_mul(rotate, up);
}

std::vector<std::vector<double>> Camera::translate_matrix() {
    double x = position[0][0];
    double y = position[1][0];
    double z = position[2][0];
    double w = position[3][0];
    std::vector<std::vector<double>> translation_matrix = {
        {1, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {-x, -y, -z, 1}
    };
    return translation_matrix;
}

std::vector<std::vector<double>> Camera::rotate_matrix() {
    double rx = right[0][0];
    double ry = right[1][0];
    double rz = right[2][0];
    double fx = forward[0][0];
    double fy = forward[1][0];
    double fz = forward[2][0];
    double ux = up[0][0];
    double uy = up[1][0];
    double uz = up[2][0];
    std::vector<std::vector<double>> rotation_matrix = {
        {rx, ux, fx, 0},
        {ry, uy, fy, 0},
        {rz, uz, fz, 0},
        {0, 0, 0, 1}
    };
    return rotation_matrix;
}

std::vector<std::vector<double>> Camera::camera_matrix() {
    return mat_mul(translate_matrix(), rotate_matrix());
}