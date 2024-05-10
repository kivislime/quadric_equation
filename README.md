# Quadratic Equation Solver

This module provides a function to solve quadratic equations of the form ax^2 + bx + c = 0.

## Installation

To use this module, simply clone the repository and include the `quadratic_equation.h` header file in your project:

```bash
git clone git@github.com:kivislime/quadric_equation.git
```
## Usage

To solve a quadratic equation, include the `quadratic_equation.h` header file in your C code and call the `solve_equation` function with the coefficients of the quadratic equation:

```c
#include "quadratic_equation.h"
#include <stdio.h>

int main() {
    double a = 1.0;
    double b = -3.0;
    double c = 2.0;

    QuadraticEquationRoots roots = solve_equation(a, b, c);

    printf("Number of roots: %d\n", roots.num_roots);
    printf("Root 1: %lf\n", roots.x1);
    printf("Root 2: %lf\n", roots.x2);

    return 0;
}
```
## Static Library

Alternatively, you can build the quadratic equation solver as a static library and include it directly in your project.

To build the static library, navigate to the cloned repository and run the following command:

```bash
make static
```
This will generate a static library file named libquadratic.a. You can then include this library in your project and link it during compilation.

```bash

gcc -o your_program your_program.c -L/path/to/quadratic-equation -lquadratic -lm
```
Replace /path/to/quadratic-equation with the path to the cloned repository directory.

## Documentation
The documentation for this module is generated using Doxygen. To generate the documentation, navigate to the cloned repository and run:

```bash
make doc
```
