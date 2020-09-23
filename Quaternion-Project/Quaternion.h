#include <iostream>
#include <vector>

class Quaternion {

private:

	double parts[4];

public:

	// Constructor
	Quaternion(double s, double i, double j, double k);

	// Returns the real part of quaternion
	double getRe();

	// Returns the euclidien norm of quaternion
	double norm();

	// Returns the nth imaginary part of quaternion
	double getIm(int n);

	// Returns a quaternion with only the imaginary parts (real part is 0)
	Quaternion getIm();

	// Returns the complex conjugate of quaternion 
	Quaternion conj();

	// Returns the unit vector of quaternion
	Quaternion getUnitVector();

	// addition
	Quaternion operator +(const Quaternion& q);

	// substraction
	Quaternion operator -(const Quaternion& q);

	// multiplication
	Quaternion operator *(const Quaternion& q);

	// equality
	friend bool operator ==(const Quaternion& lhs, const Quaternion& rhs);

	// negation
	friend Quaternion operator -(const Quaternion& q);

	friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);

};

