#include <math.h>
#include "Projection.h"

Projection::Projection(Camera* camera, double w_height, double w_width) {
    NEAR = camera->near_plane;
    FAR = camera->far_plane;
    RIGHT = tan(camera->h_fov / 2);
    LEFT = -RIGHT;
    TOP = tan(camera->v_fov / 2);
    BOTTOM = -TOP;

    m00 = 2 / (RIGHT - LEFT);
    m11 = 2 / (TOP - BOTTOM);
    m22 = (FAR + NEAR) / (FAR - NEAR);
    m32 = -2 * NEAR * FAR / (FAR - NEAR);
    projection_matrix = {
        {m00, 0, 0, 0},
        {0, m11, 0, 0},
        {0, 0, m22, 1},
        {0, 0, m32, 0},
    };

    HH = w_height;
    HW = w_width;
    to_screen_matrix = {
        {HW, 0, 0, 0},
        {0, -HH, 0, 0},
        {0, 0, 1, 0},
        {HW, HH, 0, 1}
    };
}