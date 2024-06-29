#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrices.h"
#include "Camera.h"
#include "Projection.h"

class Cube {
private:
    std::vector<vec3> vertices;
    std::vector<vec2> modified_vertices;
    double wind_height;
    double wind_width;
    sf::VertexArray* p_cube_vertbuff;

public:
    Cube(double w_height, double w_width);
    void screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind);
    void translate(double tx, double ty, double tz);
    void scale(double scale_to);
    void rotate_x(double angle);
    void rotate_y(double angle);
    void rotate_z(double angle);
};