#include <iostream>
#include <vector>

class Quaternion {

	private:

		int scalar;
		std::vector <int> imag;

	public:

		// Constructor
		Quaternion(int s, int i, int j, int k);

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

		// negation
		Quaternion operator -() const;


		friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);

};
