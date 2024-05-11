/**
 * @file quadratic_equation.h
 * @brief Quadratic equation solver module.
 */

#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#define EPS_ZERO 1e-7 /**< Small value used for comparing with zero */

#include <math.h>
#include <stdio.h>

/**
 * @brief Structure for representing roots of a quadratic equation.
 */
typedef struct {
  double x1;     /**< First root. */
  double x2;     /**< Second root. */
  int num_roots; /**< Number of roots (0, 1, or 2). */
} QuadraticEquationRoots;

/**
 * @brief Solves a quadratic equation of the form ax^2 + bx + c = 0.
 *
 * This function calculates the roots of the quadratic equation using the
 * coefficients a, b, and c.
 *
 * @param a Coefficient of x^2.
 * @param b Coefficient of x.
 * @param c Constant term.
 * @return Roots of the quadratic equation.
 *         If the discriminant is negative, both roots are NaN.
 *         If the discriminant is zero, both roots are equal.
 *         If the discriminant is positive, two distinct real roots are
 * returned.
 */
QuadraticEquationRoots solve_equation(double a, double b, double c);

#endif  // QUADRATIC_EQUATION_H
