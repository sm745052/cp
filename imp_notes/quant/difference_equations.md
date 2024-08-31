# Linear Difference Equations - Chapter 3 Summary

## 1. Introduction
- Focus on solving linear difference equations with some applications.

## 2. First Order Homogeneous Equation
- **Equation form**: \( x(n) = ax(n - 1) \)
- **Solution**: \( x(n) = a^n x(0) \)
- Model for exponential growth or decay.
- **General solution**: \( x(n) = Ca^n \)

## 3. Interest Rate Example
- Yearly interest rate of 5% compounded monthly.
- **Equation**: \( x(n) = \left(\frac{241}{240}\right)x(n - 1) \)
- **Solution after 5 years**: \( x(60) = 1283.35 \)

## 4. First Order Inhomogeneous Equation
- **Equation form**: \( x(n) = ax(n - 1) + b(n) \)
- **Linearity Principle**:
  - If \( x(n) \) is a solution of the homogeneous equation and \( y(n) \) of the inhomogeneous, then \( z(n) = x(n) + y(n) \) is a solution of the inhomogeneous equation.
- **General solution**:
  1. Find a particular solution of the inhomogeneous equation.
  2. Solve the homogeneous equation.
  3. Combine both solutions.

## 5. Example - Solving Inhomogeneous Equation
- **Given equation**: \( x(n) = ax(n - 1) + b \)
- **General solution**: \( x(n) = Ca^n + \frac{b}{1 - a} \)

## 6. More Interest Rate
- Adding $10 every month.
- **Equation**: \( x(n) = \left(\frac{241}{240}\right)x(n - 1) + 10 \)
- **Solution after 5 years**: \( x(60) = 1963.41 \)

## 7. Second Order Homogeneous Equation
- **Equation form**: \( x(n) = ax(n - 1) + bx(n - 2) \)
- **General solution**: \( x(n) = C_1 \alpha_1^n + C_2 \alpha_2^n \)

## 8. Example - Fibonacci Sequence
- **Sequence**: \( x(n) = x(n - 1) + x(n - 2) \)
- General solution involves the golden ratio \( \varphi \).
- Fibonacci relation to probability in flipping coins with no consecutive heads.

## 9. Second Order Inhomogeneous Equation
- **Equation form**: \( x(n) = ax(n - 1) + bx(n - 2) + c(n) \)
- **Solution steps**:
  1. Solve the homogeneous equation.
  2. Find a particular solution of the inhomogeneous equation.
  3. Combine both solutions.

## 10. Example - Solving Second Order Inhomogeneous Equation
- **Given equation**: \( 3x(n) + 5x(n - 1) - 2x(n - 2) = 5 \)
- **General solution**: \( x(n) = \frac{5}{6} + C_1 \left(\frac{1}{3}\right)^n + C_2(-2)^n \)
