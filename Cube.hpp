#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrices.hpp"
#include "Camera.hpp"
#include "Projection.hpp"

class Cube {
private:
    std::vector<vec3> vertices;
    std::vector<vec3> projection_vertices;
    std::vector<vec2> modified_vertices;
    sf::VertexArray* p_cube_vertbuff;

public:
    Cube();
    void vertices_to_projection();
    void screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind);
    void translate(double tx, double ty, double tz);
    void scale(double scale_to);
    void rotate_x(double angle);
    void rotate_y(double angle);
    void rotate_z(double angle);
};