#include "math.h"

using namespace corin::stdlib;

extern "C" {

// Basic operations
double corin_math_abs(double x) {
    return Math::abs(x);
}

double corin_math_min(double a, double b) {
    return Math::min(a, b);
}

double corin_math_max(double a, double b) {
    return Math::max(a, b);
}

// Trigonometry
double corin_math_sin(double x) {
    return Math::sin(x);
}

double corin_math_cos(double x) {
    return Math::cos(x);
}

double corin_math_tan(double x) {
    return Math::tan(x);
}

double corin_math_asin(double x) {
    return Math::asin(x);
}

double corin_math_acos(double x) {
    return Math::acos(x);
}

double corin_math_atan(double x) {
    return Math::atan(x);
}

double corin_math_atan2(double y, double x) {
    return Math::atan2(y, x);
}

// Exponential and logarithmic
double corin_math_exp(double x) {
    return Math::exp(x);
}

double corin_math_log(double x) {
    return Math::log(x);
}

double corin_math_log10(double x) {
    return Math::log10(x);
}

double corin_math_log2(double x) {
    return Math::log2(x);
}

double corin_math_pow(double x, double y) {
    return Math::pow(x, y);
}

double corin_math_sqrt(double x) {
    return Math::sqrt(x);
}

// Rounding
double corin_math_floor(double x) {
    return Math::floor(x);
}

double corin_math_ceil(double x) {
    return Math::ceil(x);
}

double corin_math_round(double x) {
    return Math::round(x);
}

// Constants
double corin_math_pi() {
    return Math::PI;
}

double corin_math_e() {
    return Math::E;
}

} // extern "C"
