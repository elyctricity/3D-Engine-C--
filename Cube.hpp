#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Matrices.hpp"
#include "Camera.hpp"
#include "Projection.hpp"

class Cube {
private:
    std::vector<vec3> vertices;
    std::vector<vec3> modified_vertices;
    std::vector<sf::VertexArray> p_cube_vertbuffer;
    sf::VertexArray p_cube_vertbuff;
    sf::VertexArray p_cube_vertbuff1;
    sf::VertexArray p_cube_vertbuff2;

public:
    Cube();
    void screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind);
    void translate(double tx, double ty, double tz);
    void scale(double scale_to);
    void rotate_x(double angle);
    void rotate_y(double angle);
    void rotate_z(double angle);
};