#include "Cube.hpp"

Cube::Cube() {
    vertices = {{0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0},
                {0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1}};
    modified_vertices = {{0, 0}, {0, 0}, {0, 0}, {0, 0},
                         {0, 0}, {0, 0}, {0, 0}, {0, 0}};
    p_cube_vertbuff = new sf::VertexArray(sf::LineStrip, 8);
}

void Cube::screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind) {
    printf("Cube\n");
    for (int i = 0; i < vertices.size(); i++) {
        printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        vertices[i] = vec3_mat_mul(vertices[i], camera->camera_matrix());
        // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        vertices[i] = vec3_mat_mul(vertices[i], projection->projection_matrix);
        // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        vertices[i] = vec3_mat_mul(vertices[i], projection->to_screen_matrix);
        // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        modified_vertices[i] = vec3_to_vec2(vertices[i]);
    }
    
    for (int i = 0; i < modified_vertices.size(); i++) {
        // printf("%f, %f\n", modified_vertices[i].x, modified_vertices[i].y);
        (*(p_cube_vertbuff))[i].position = sf::Vector2f(modified_vertices[i].x, modified_vertices[i].y);
        (*(p_cube_vertbuff))[0].color = sf::Color(255, 0, 0);
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