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
//Quaternion operator *(const Quaternion& q) {}
//Quaternion Quaternion :: operator -() const {}

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

	if(q1 == q2)
		std::cout << "True" << std::endl;
	system("pause");

	return 0;
}