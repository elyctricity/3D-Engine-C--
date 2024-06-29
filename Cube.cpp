#include "Cube.h"

Cube::Cube(double w_height, double w_width) {
    vertices = {{0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0},
                {0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1}};
    modified_vertices = {{0, 0}, {0, 0}, {0, 0}, {0, 0},
                         {0, 0}, {0, 0}, {0, 0}, {0, 0}};
    wind_height = w_height;
    wind_width = w_width;
    p_cube_vertbuff = new sf::VertexArray(sf::LineStrip, 8);
}

void Cube::screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = vec3_mat_mul(vertices[i], camera->camera_matrix());  // The [i] is grab a vertex, which is std::vector<std::vector<double>>
        vertices[i] = vec3_mat_mul(vertices[i], projection->projection_matrix);
        vertices[i] = vec3_mat_mul(vertices[i], projection->to_screen_matrix);
        modified_vertices[i] = vec3_to_vec2(vertices[i]);
    }

    for (int i = 0; i < modified_vertices.size(); i++) {
        (*(p_cube_vertbuff))[i].position = sf::Vector2f(modified_vertices[i].x, modified_vertices[i].y);
        (*(p_cube_vertbuff))[0].color = sf::Color(255, 255, 255);
    }

    wind.draw(*p_cube_vertbuff);
}

void Cube::translate(double tx, double ty, double tz) {
    for (vec3 &vertex : vertices) {
        vertex = vec3_mat_mul(vertex, mat_translate(tx, ty, tz));
    }
}

void Cube::scale(double scale_to) {
    for (vec3 &vertex : vertices) {
        vertex = vec3_mat_mul(vertex, mat_scale(scale_to));
    }
}

void Cube::rotate_x(double angle) {
    for (vec3 &vertex : vertices) {
        vertex = vec3_mat_mul(vertex, mat_rotate_x(angle));
    }
}

void Cube::rotate_y(double angle) {
    for (vec3 &vertex : vertices) {
        vertex = vec3_mat_mul(vertex, mat_rotate_y(angle));
    }
}

void Cube::rotate_z(double angle) {
    for (vec3 &vertex : vertices) {
        vertex = vec3_mat_mul(vertex, mat_rotate_z(angle));
    }
}