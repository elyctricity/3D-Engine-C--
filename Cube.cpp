#include "Cube.hpp"

Cube::Cube() {
    vertices = {{-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1},
                {-1, 1, 1}, {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}};
    modified_vertices = vertices;
    p_cube_vertbuffer = {sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3),
                         sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3),
                         sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3),
                         sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3),
                         sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3),
                         sf::VertexArray(sf::Triangles, 3), sf::VertexArray(sf::Triangles, 3)};
}

void Cube::screen_projection(Camera* camera, Projection* projection, sf::RenderWindow& wind) {
    for (int i = 0; i < vertices.size(); i++) {
        modified_vertices[i] = vertices[i];
        // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        modified_vertices[i] = vec3_mat_mul(modified_vertices[i], camera->camera_matrix());
        // // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        // modified_vertices[i] = vec3_mat_mul(modified_vertices[i], projection->projection_matrix);
        // // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
        // vertices[i] = vec3_mat_mul(vertices[i], projection->to_screen_matrix);
        // printf("%f, %f, %f\n", vertices[i].x, vertices[i].y, vertices[i].z);
    }

    p_cube_vertbuffer[0][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[0][1].position = sf::Vector2f(modified_vertices[1].x, modified_vertices[1].y);
    p_cube_vertbuffer[0][2].position = sf::Vector2f(modified_vertices[2].x, modified_vertices[2].y);
    p_cube_vertbuffer[1][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[1][1].position = sf::Vector2f(modified_vertices[3].x, modified_vertices[3].y);
    p_cube_vertbuffer[1][2].position = sf::Vector2f(modified_vertices[2].x, modified_vertices[2].y);

    p_cube_vertbuffer[2][0].position = sf::Vector2f(modified_vertices[4].x, modified_vertices[4].y);
    p_cube_vertbuffer[2][1].position = sf::Vector2f(modified_vertices[5].x, modified_vertices[5].y);
    p_cube_vertbuffer[2][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);
    p_cube_vertbuffer[3][0].position = sf::Vector2f(modified_vertices[4].x, modified_vertices[4].y);
    p_cube_vertbuffer[3][1].position = sf::Vector2f(modified_vertices[6].x, modified_vertices[6].y);
    p_cube_vertbuffer[3][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);

    p_cube_vertbuffer[4][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[4][1].position = sf::Vector2f(modified_vertices[4].x, modified_vertices[4].y);
    p_cube_vertbuffer[4][2].position = sf::Vector2f(modified_vertices[6].x, modified_vertices[6].y);
    p_cube_vertbuffer[5][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[5][1].position = sf::Vector2f(modified_vertices[3].x, modified_vertices[3].y);
    p_cube_vertbuffer[5][2].position = sf::Vector2f(modified_vertices[6].x, modified_vertices[6].y);

    p_cube_vertbuffer[6][0].position = sf::Vector2f(modified_vertices[1].x, modified_vertices[1].y);
    p_cube_vertbuffer[6][1].position = sf::Vector2f(modified_vertices[5].x, modified_vertices[5].y);
    p_cube_vertbuffer[6][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);
    p_cube_vertbuffer[7][0].position = sf::Vector2f(modified_vertices[1].x, modified_vertices[1].y);
    p_cube_vertbuffer[7][1].position = sf::Vector2f(modified_vertices[2].x, modified_vertices[2].y);
    p_cube_vertbuffer[7][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);

    p_cube_vertbuffer[8][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[8][1].position = sf::Vector2f(modified_vertices[4].x, modified_vertices[4].y);
    p_cube_vertbuffer[8][2].position = sf::Vector2f(modified_vertices[5].x, modified_vertices[5].y);
    p_cube_vertbuffer[9][0].position = sf::Vector2f(modified_vertices[0].x, modified_vertices[0].y);
    p_cube_vertbuffer[9][1].position = sf::Vector2f(modified_vertices[1].x, modified_vertices[1].y);
    p_cube_vertbuffer[9][2].position = sf::Vector2f(modified_vertices[5].x, modified_vertices[5].y);

    p_cube_vertbuffer[10][0].position = sf::Vector2f(modified_vertices[3].x, modified_vertices[3].y);
    p_cube_vertbuffer[10][1].position = sf::Vector2f(modified_vertices[6].x, modified_vertices[6].y);
    p_cube_vertbuffer[10][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);
    p_cube_vertbuffer[11][0].position = sf::Vector2f(modified_vertices[3].x, modified_vertices[3].y);
    p_cube_vertbuffer[11][1].position = sf::Vector2f(modified_vertices[2].x, modified_vertices[2].y);
    p_cube_vertbuffer[11][2].position = sf::Vector2f(modified_vertices[7].x, modified_vertices[7].y);

    p_cube_vertbuffer[0][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[0][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[0][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[1][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[1][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[1][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[2][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[2][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[2][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[3][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[3][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[3][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[4][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[4][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[4][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[5][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[5][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[5][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[6][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[6][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[6][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[7][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[7][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[7][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[8][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[8][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[8][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[9][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[9][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[9][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[10][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[10][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[10][2].color = sf::Color(0, 255, 0);
    p_cube_vertbuffer[11][0].color = sf::Color(255, 0, 0);
    p_cube_vertbuffer[11][1].color = sf::Color(0, 0, 255);
    p_cube_vertbuffer[11][2].color = sf::Color(0, 255, 0);

    for (int i = 0; i < p_cube_vertbuffer.size(); i++) {
        wind.draw(p_cube_vertbuffer[i]);
    }
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