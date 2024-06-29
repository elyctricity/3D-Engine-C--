#pragma once
#include <math.h>

struct vec3 {
    double x;
    double y;
    double z;
};

struct vec2 {
    double x;
    double y;
};

inline vec3 vec3_mat_mul(vec3 v, std::vector<std::vector<double>> m) {
    vec3 o;
    o.x = v.x*m[0][0] + v.y*m[0][1] + v.z*m[0][2] + m[0][3];
    o.y = v.x*m[1][0] + v.y*m[1][1] + v.z*m[1][2] + m[1][3];
    o.z = v.x*m[2][0] + v.y*m[2][1] + v.z*m[2][2] + m[2][3];
    double w = v.x*m[3][0] + v.y*m[3][1] + v.z*m[3][2] + m[3][3];

    if (w != 0) {
        o.x /= w; o.y /= w; o.z /= w;
    }

    return o;
}

inline vec2 vec3_to_vec2(vec3 v) {
    vec2 o;
    o.x = v.x;
    o.y = v.y;
    
    return o;
}

inline vec3 vec3_add(vec3 a, vec3 b) {
    vec3 o;
    o.x = a.x+b.x;
    o.y = a.y+b.y;
    o.z = a.z+b.z;

    return o;
}

inline vec3 vec3_sub(vec3 a, vec3 b) {
    vec3 o;
    o.x = a.x-b.x;
    o.y = a.y-b.y;
    o.z = a.z-b.z;

    return o;
}

inline vec3 vec3_mul_scalar(vec3 a, double s) {
    vec3 o;
    o.x = a.x*s;
    o.y = a.y*s;
    o.z = a.z*s;

    return o;
}

inline std::vector<std::vector<double>> mat_translate(double tx, double ty, double tz) {
    std::vector<std::vector<double>> translation_matrix = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {tx, ty, tz, 1}
    };
    return translation_matrix;
}

inline std::vector<std::vector<double>> mat_rotate_x(double angle) {
    std::vector<std::vector<double>> rotate_x_matrix = {
        {1, 0, 0, 0},
        {0, cos(angle), sin(angle), 0},
        {0, -1*sin(angle), cos(angle), 0},
        {0, 0, 0, 1}
    };
    return rotate_x_matrix;
}

inline std::vector<std::vector<double>> mat_rotate_y(double angle) {
    std::vector<std::vector<double>> rotate_y_matrix = {
        {cos(angle), 0, -1*sin(angle), 0},
        {0, 1, 0, 0},
        {sin(angle), 0, cos(angle), 0},
        {0, 0, 0, 1}
    };
    return rotate_y_matrix;
}

inline std::vector<std::vector<double>> mat_rotate_z(double angle) {
    std::vector<std::vector<double>> rotate_z_matrix = {
        {cos(angle), sin(angle), 0, 0},
        {-1*sin(angle), cos(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    return rotate_z_matrix;
}

inline std::vector<std::vector<double>> mat_scale(double n) {
    std::vector<std::vector<double>> scale_matrix = {
        {n, 0, 0, 0},
        {0, n, 0, 0},
        {0, 0, n, 0},
        {0, 0, 0, 1}
    };
    return scale_matrix;
}

inline std::vector<std::vector<double>> mat_mul(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b) {
    int cols_a = a[0].size();
    int rows_a = a.size();
    int cols_b = b[0].size();
    int rows_b = b.size();
    std::vector<double> result;

    if (cols_a != rows_b)
    {
        std::cout << "Columns of A must match rows of B" << " \n";
        return {};
    }

    // push back sum element to result array
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            double sum = 0;
            for (int k = 0; k < cols_a; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result.push_back(sum);
        }
    }

    // initialize a multidimensional array
    std::vector<std::vector<double>> result_2;
    for (int i = 0; i < rows_a; i++) {
        std::vector<double> array = {};
        for (int j = 0; j < cols_b; j++) {
            array.push_back({});
        }
        result_2.push_back(array);
    }
    
    // Turn result, which is a one-dimensional array, to a multidimensional array.
    // given matrix a and b's matrix product's predicted rows and columns.
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            result_2[i][j] = result[(i*cols_b)+j];
        }
    }

    return result_2;
}