// Karan Kumar
// CSS 343 Dong Si
// Assignment 1

#ifndef ASSIGNMENT1_POLY_H
#define ASSIGNMENT1_POLY_H

#include <iostream>

using namespace std;

class Poly
{

private:
    int *coeffPtr; // pointer to array that holds input
    int size;      // size of array

public:

    // Constructors**************************************
    /*
    Initializes a Poly object representing the zero polynomial, with a single term of degree 0 and a coefficient of 0
    @param None
    @return None
    */
    Poly();

    /*
    Initializes a Poly object with a single term of degree 0 and sets its coefficient to the provided value. 
    This constructor creates a constant polynomial.
    @param coeff The coefficient of the 0-degree term in the polynomial.
    @return None
    */
    Poly(int coeff);

    /*
    Initializes a Poly object with a specified term, setting the coefficient for the given power and initializing 
    all other coefficients to 0. Allows for creating a polynomial with a single non-zero term at the specified power.
    @param coeff The coefficient of the term at the specified power.
    @param power The exponent for the term with the non-zero coefficient.
    @return None 
    */
    Poly(int coeff, int power);

    /*
    Creates a new Poly object as a copy of another Poly object and copies over the size and all the coefficients to the new object.
    @param other The Poly object from which to copy the size and coefficients.
    @return None 
    */
    Poly(const Poly &other);


    // Destructors**************************************
    /*
    Cleans up a Poly object by first setting all coefficients to 0, then setting the size to 0, 
    and deallocating the dynamic memory allocated for the coefficients. 
    Ensures that no memory leaks occur when a Poly object is destroyed.
    @param None.
    @return None
    */
    ~Poly();


    // Overloaded Arithmetic Operators**************************************
    /*
    Overloads the + operator to add two Poly objects by creating a new Poly object that represents the sum. 
    Ensures that the result contains all terms from both polynomials by starting with a copy of the larger polynomial 
    and then adding the coefficients of the smaller polynomial to it.
    @param p The Poly object to be added to the current Poly object.
    @return A new Poly object that represents the sum of the current object and the p object.
    */
    Poly operator+(const Poly &p) const;

    /*
    Overloads the - operator to subtract one Poly object from another to reult in a new Poly object. 
    Initializes the result as a copy of the current object and then adjusts its coefficients by subtracting the coefficients of the given Poly object.
    If the given polynomial is larger, the current polynomial is expanded to match its size before subtraction.
    @param p The Poly object to be subtracted from the current Poly object.
    @return A new Poly object that represents the difference between the current object and the p object.
    */
    Poly operator-(const Poly &p) const;

    /*
    Overloads the * operator to multiply two Poly objects, creating a new Poly object that represents the product. 
    Initializes the resulting polynomial with a size large enough to hold the highest possible degree resulting from the multiplication, 
    then iterates through each pair of coefficients from the current and given polynomials, 
    multiplying them and adding the result to the appropriate term in the product polynomial.
    @param p The Poly object to be multiplied with the current Poly object.
    @return A new Poly object representing the product of the current object and the p object.
    */
    Poly operator*(const Poly &p) const;


    // Overloaded Assignment Operator**************************************
    /*
    Overloads the assignment operator to assign the contents of one Poly object to another. 
    It first checks for self-assignment and returns the current object unchanged if true. 
    Otherwise, it deallocates the existing array, copies the size and coefficients from p, 
    and allocates a new array to store the copied coefficients, ensuring a deep copy.
    @param p The Poly object whose values are to be copied into the current Poly object.
    @return A reference to the current Poly object after assignment.
    */
    Poly &operator=(const Poly &p);

    // Overloaded Arithmetic Assignment Operators
    /*
    Overloads the += operator to add the coefficients of a given Poly object to the current Poly object. 
    Uses the operator+ to create a new Poly representing the sum of the two polynomials and then assigns this result back to the current object.
    @param p The Poly object to be added to the current Poly object.
    @return A reference to the current Poly object after the addition.
    */
    Poly &operator+=(const Poly &p);

    /*
    Overloads the -= operator to subtract the coefficients of a given Poly object from the current Poly object. 
    Utilizes the operator- to create a new Poly representing the difference between the two polynomials and then
    assigns this result back to the current object.
    @param p The Poly object to be subtracted from the current Poly object.
    @return A reference to the current Poly object after the subtraction.
    */
    Poly &operator-=(const Poly &p);

    /*
    Overloads the -= operator to subtract the coefficients of a given Poly object from the current Poly object. 
    Utilizes the operator- to create a new Poly representing the difference between the two polynomials and then
    assigns this result back to the current object.
    @param p The Poly object to be subtracted from the current Poly object.
    @return A reference to the current Poly object after the subtraction.
    */
    Poly &operator*=(const Poly &p);


    // Overloaded Comparison Operators**************************************
    /*
    Overloads the == operator to compare the current Poly object with another Poly object for equality. 
    First checks if the sizes of the two polynomials are equal. If the sizes are equal, it then compares each coefficient of the polynomials. 
    If any coefficients at the same index are different, it returns false; otherwise, it returns true.
    @param p The Poly object to be compared with the current Poly object for equality.
    @return true if the two Poly objects are equal (same size and identical coefficients), otherwise false.
    */
    bool operator==(const Poly &p) const;

    /*
    Overloads the != operator to compare the current Poly object with another Poly object for inequality. 
    Returning the negation of the == operator's result to determine if the two Poly objects are not equal.
    @param p The Poly object to be compared with the current Poly object for inequality.
    @return true if the two Poly objects are not equal, otherwise false.
    */
    bool operator!=(const Poly &p) const;


    // Overloaded << and >> operators**************************************
    /*
    Overloads the << operator for ostream to output a Poly object in a polynomial format. 
    Iterates through the polynomial's coefficients in reverse order and outputs only the non-zero terms. 
    Each term is prefixed by a space, and positive coefficients are prefixed with a +. 
    Outputs a " 0" if no non-zero coefficients are found.
    @param output The output stream to which the polynomial is written.
    @param p The Poly object to be outputted.
    @return The modified output stream.
    */
    friend ostream &operator<<(ostream &out, const Poly &p); // output

    /*
    Overloads the >> operator for istream to input coefficients and their powers into a Poly object. 
    Reads pairs of integers representing a coefficient and its power, until the pair -1 -1 is entered, which terminates the input. 
    Each valid pair is used to set the corresponding coefficient in the polynomial.
    @param input The input stream from which the coefficients and powers are read.
    @param p The Poly object into which the coefficients and powers are set.
    @return The modified input stream.
    */
    friend istream &operator>>(istream &in, Poly &p);        // input


    // Getter and Setter**************************************
    /*
    Returns the coefficient of a term in the polynomial at the specified power. 
    If the power is within the bounds of the polynomial, it returns the coefficient at that power. 
    Otherwise, it returns 0.
    @param power The power of the term whose coefficient is requested.
    @return The coefficient of the term at the specified power, or 0 if the term is beyond the polynomial's current size or if the power is negative.
    */
    int getCoeff(int power) const;

    /*
    Sets the coefficient for a term at a specified power in the polynomial. 
    If the power is within the current size of the polynomial, the coefficient is directly set. 
    If the power is beyond the current size, the polynomial is expanded to accommodate the new term,
    initializing any new coefficients to 0 before setting the specified term's coefficient. 
    @param co The coefficient to be set for the term at the specified power.
    @param power The power at which the coefficient is to be set, which must be non-negative.
    @return None.
    */
    void setCoeff(int co, int power);
};
#endif