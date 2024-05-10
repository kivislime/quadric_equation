#include "quadratic_equation.h"

QuadraticEquationRoots solve_equation(double a, double b, double c) {
  QuadraticEquationRoots roots = {0};
  if (fabs(a) <= EPS_ZERO) return roots;

  double discriminant = b * b - 4 * a * c;

  if (discriminant < -EPS_ZERO) {
    return roots;
  } else if (fabs(discriminant) > EPS_ZERO) {
    roots.x1 = (-b - sqrt(discriminant)) / (2 * a);
    roots.x2 = (-b + sqrt(discriminant)) / (2 * a);
    roots.num_roots = 2;
  } else {
    roots.x1 = -b / (2 * a);
    roots.x2 = roots.x1;
    roots.num_roots = 1;
  }

  if (isnan(roots.x1) || isnan(roots.x2)) {
    roots.num_roots = 0;
    roots.x1 = 0.0;
    roots.x2 = 0.0;
  }

  return roots;
}
