#pragma once
#include <math.h>

inline std::vector<std::vector<double>> vec4_to_vec2(std::vector<std::vector<double>> v) {
    std::vector<std::vector<double>> new_v = {{v[0][0]}, {v[1][0]}};
    return v;
}

inline std::vector<std::vector<double>> mat_translate(double tx, double ty, double tz) {
    std::vector<std::vector<double>> translation_matrix = {
        {1,  0,  0,  0},
        {0,  1,  0,  0},
        {0,  0,  1,  0},
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

// One-dimensional matrix scalar multiplication
inline std::vector<std::vector<double>> vec_mul_scalar(std::vector<std::vector<double>> a, double scalar) {
    double a_size = a.size();
    std::vector<std::vector<double>> result;
    double product;

    for (int i = 0; i < a_size; i++) {
        product = a[i][0] * scalar;
        result.push_back({product});
    }

    return result;
}

// One-dimensional matrix addition (Currently only for horizontal linear)
inline std::vector<std::vector<double>> vec_add(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b) {
    double a_size = a.size();
    std::vector<std::vector<double>> result;
    double sum;

    for (int i = 0; i < a_size; i++) {
        sum = a[i][0] + b[i][0];
        result.push_back({sum});
    }

    return result;
}

// One-dimensional matrix subtraction (Currently only for horizontal linear)
inline std::vector<std::vector<double>> vec_sub(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b) {
    double a_size = a.size();
    std::vector<std::vector<double>> result;
    double sum;

    for (int i = 0; i < a_size; i++) {
        sum = a[i][0] - b[i][0];
        result.push_back({sum});
    }

    return result;
}