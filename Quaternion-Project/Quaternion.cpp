#include <iostream> 
#include "Quaternion.h"
#include <stdexcept>



Quaternion::Quaternion(double s, double i, double j, double k) {

	parts[0] = s;
	parts[1] = i;
	parts[2] = j;
	parts[3] = k;

}

double Quaternion :: getRe() {

	return parts[0];
}

//double Quaternion :: norm() {}
double Quaternion :: getIm(int n) {
		
	if (n < 0 || n > 2)
		return -DBL_MAX;

	return parts[n + 1];
	
}

Quaternion Quaternion :: getIm() {

	return Quaternion(0, parts[1], parts[2], parts[3]);
}

//Quaternion Quaternion :: conj() {}
//Quaternion Quaternion :: getUnitVector() {}

//Quaternion operator +(const Quaternion& q) {}
//Quaternion operator -(const Quaternion& q) {}

Quaternion operator *(const Quaternion& lhs, const Quaternion& rhs) {

	double a1 = lhs.parts[0];
	double a2 = rhs.parts[0];

	double b1 = lhs.parts[1];
	double b2 = rhs.parts[1];

	double c1 = lhs.parts[2];
	double c2 = rhs.parts[2];

	double d1 = lhs.parts[3];
	double d2 = rhs.parts[3];

	double new_real = (a1 * a2) - (b1 * b2) - (c1 * c2) - (d1 * d2);
	double new_i = (a1 * b2) + (b1 * a2) + (c1 * d2) - (d1 * c2);
	double new_j = (a1 * c2) + (c1 * a2) + (d1 * b2) - (b1 * d2);
	double new_k = (a1 * d2) + (d1 * a2) + (b1 * c2) - (c1 * b2);

	return Quaternion(new_real, new_i, new_j, new_k);

}

Quaternion operator *(const double& lhs, const Quaternion& rhs) {

	return Quaternion(lhs * rhs.parts[0], lhs * rhs.parts[1], lhs * rhs.parts[2], lhs * rhs.parts[3]);
}

Quaternion operator *(const Quaternion& lhs, const double& rhs) {

	return Quaternion(rhs * lhs.parts[0], rhs * lhs.parts[1], rhs * lhs.parts[2], rhs * lhs.parts[3]);

}

Quaternion operator -(const Quaternion & q){

	return Quaternion(-q.parts[0], -q.parts[1], -q.parts[2], -q.parts[3]);

}

bool operator ==(const Quaternion& lhs, const Quaternion& rhs) {

	for (size_t i = 0; i < 4; i++) {
		if (lhs.parts[i] != rhs.parts[i])
			return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
	os << "[ " << q.parts[0] << " + " << q.parts[1] << "i + " << q.parts[2] << "j + " << q.parts[3] << "k ]";
	return os;
}

int main() {

	Quaternion q1 = Quaternion(1, -1, 0, 1);
	Quaternion q2 = Quaternion(1, -1, 0, 1);

	std::cout << q1 * 2.0 << std::endl;
	system("pause");

	return 0;
}