#include <math.h>
#include "Projection.hpp"

Projection::Projection(Camera* camera, double w_height, double w_width) {
    NEAR = camera->near_plane;
    FAR = camera->far_plane;
    RIGHT = tan(camera->h_fov / 2);
    LEFT = -RIGHT;
    TOP = tan(camera->v_fov / 2);
    BOTTOM = -TOP;

    double xymax = NEAR * tan(camera->fov * (M_PI/360));
    double ymin = -xymax;
    double xmin = -xymax;

    double width = xymax - xmin;
    double height = xymax - ymin;

    double depth = FAR - NEAR;
    double q = -(FAR + NEAR) / depth;
    double qn = -2 * (FAR * NEAR) / depth;

    double w = 2 * NEAR / width;
    double aspect = w_height/w_width;
    w = w / aspect;
    double h = 2 * NEAR / height;
    projection_matrix = {
        {w, 0, 0, 0},
        {0, h, 0, 0},
        {0, 0, q, qn},
        {0, 0, -1, 1},
    };

    HH = w_height;
    HW = w_width;
    double a = HW/2;
    double b = HH/2;
    double c = 1/2;
    double d = 0+a;
    double e = HH+b;
    double f = 1/2;
    to_screen_matrix = {
        {a, 0, 0, d},
        {0, b, 0, e},
        {0, 0, c, f},
        {0, 0, 0, 1}
    };
}