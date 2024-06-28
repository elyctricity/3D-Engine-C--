#include "Cube.h"

Cube::Cube(double w_height, double w_width) {
    vertices = {{{0}, {0}, {0}, {1}}, {{0}, {1}, {0}, {1}}, {{1}, {1}, {0}, {1}}, {{1}, {0}, {0}, {1}},
                {{0}, {0}, {1}, {1}}, {{0}, {1}, {1}, {1}}, {{1}, {1}, {1}, {1}}, {{1}, {0}, {1}, {1}}};
    modified_vertices = {{{0}, {0}, {0}, {1}}, {{0}, {1}, {0}, {1}}, {{1}, {1}, {0}, {1}}, {{1}, {0}, {0}, {1}},
                {{0}, {0}, {1}, {1}}, {{0}, {1}, {1}, {1}}, {{1}, {1}, {1}, {1}}, {{1}, {0}, {1}, {1}}};
    faces = {{0, 1, 2, 3}, {4, 5, 6, 7}, {0, 4, 5, 1}, {2, 3, 7, 6},
            {1, 2, 6, 5}, {0, 3, 7, 4}};
    wind_height = w_height;
    wind_width = w_width;
    p_cube_vertbuff = new sf::VertexArray(sf::LineStrip, 8);
}

void Cube::screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind) {
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i] = mat_mul(vertices[i], camera->camera_matrix());  // The [i] is grab a vertex, which is std::vector<std::vector<double>>
        vertices[i] = mat_mul(vertices[i], projection->projection_matrix);
        for (int j = 0; j < vertices[i].size(); j++){
            vertices[i][j][0] = vertices[i][j][0]/vertices[i][2][0];  // Go through each vertices, rows, then grab first column
        }                                                             // resulting in the x, y, z, w, components being divided by w
        modified_vertices[i] = mat_mul(vertices[i], projection->to_screen_matrix);
        modified_vertices[i] = vec4_to_vec2(modified_vertices[i]);
    }

    for (std::vector<double> face : faces) {
        for (int i = 0; i < 4; i++) {
            if (modified_vertices[face[i]][1][0] != wind_height || modified_vertices[face[i]][0][0] != wind_width) {
                (*(p_cube_vertbuff))[face[i]].position = sf::Vector2f(modified_vertices[face[i]][0][0], modified_vertices[face[i]][1][0]);
                (*(p_cube_vertbuff))[face[i]].color = sf::Color(i*255, i*100, 0);
            }
        }
    }
    
    wind.draw(*p_cube_vertbuff);
}

void Cube::translate(double tx, double ty, double tz) {
    for (std::vector<std::vector<double>>& vertex : vertices) {
        vertex = mat_mul(vertex, mat_translate(tx, ty, tz));
    }
}

void Cube::scale(double scale_to) {
    for (std::vector<std::vector<double>>& vertex : vertices) {
        vertex = mat_mul(vertex, mat_scale(scale_to));
    }
}

void Cube::rotate_x(double angle) {
    for (std::vector<std::vector<double>>& vertex : vertices) {
        vertex = mat_mul(vertex, mat_rotate_x(angle));
    }
}

void Cube::rotate_y(double angle) {
    for (std::vector<std::vector<double>>& vertex : vertices) {
        vertex = mat_mul(vertex, mat_rotate_y(angle));
    }
}

void Cube::rotate_z(double angle) {
    for (std::vector<std::vector<double>>& vertex : vertices) {
        vertex = mat_mul(vertex, mat_rotate_z(angle));
    }
}