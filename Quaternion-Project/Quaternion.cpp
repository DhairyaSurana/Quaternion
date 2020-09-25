#include <iostream> 
#include <stdexcept>

#include "Quaternion.h"

using namespace std;


Quaternion::Quaternion(double s, double i, double j, double k) {

	parts[0] = s;
	parts[1] = i;
	parts[2] = j;
	parts[3] = k;

}

double Quaternion :: getRe() {

	return parts[0];
}

double Quaternion :: norm() {

	return sqrt(parts[0] * parts[0] + parts[1] * parts[1] + parts[2] * parts[2] + parts[3] * parts[3]);

}

double Quaternion :: getIm(int n) {
		
	if (n < 0 || n > 2)
		return -DBL_MAX;

	return parts[n + 1];
	
}

Quaternion Quaternion :: getIm() {

	return Quaternion(0, parts[1], parts[2], parts[3]);
}

Quaternion Quaternion :: conj() {

	return Quaternion(parts[0], -parts[1], -parts[2], -parts[3]);
}

Quaternion Quaternion :: getUnitVector() {
	
	double norm = this->norm();

	return Quaternion(parts[0] / norm, parts[1] / norm, parts[2] / norm, parts[3] / norm);

}

Quaternion operator +(const Quaternion& lhs, const Quaternion& rhs) {

	return Quaternion(lhs.parts[0] + rhs.parts[0], lhs.parts[1] + rhs.parts[1], lhs.parts[2] + rhs.parts[2], lhs.parts[3] + rhs.parts[3]);

}

Quaternion operator +(const double& lhs, const Quaternion& rhs) {

	return Quaternion(lhs + rhs.parts[0], rhs.parts[1], rhs.parts[2], rhs.parts[3]);

}

Quaternion operator +(const Quaternion& lhs, const double& rhs) {

	return Quaternion(rhs + lhs.parts[0], lhs.parts[1], lhs.parts[2], lhs.parts[3]);

}

Quaternion operator /(const Quaternion& lhs, const double& rhs) {

	double quotient = (rhs == 0) ? -DBL_MAX : lhs.parts[0] / rhs;

	return Quaternion(quotient, lhs.parts[1], lhs.parts[2], lhs.parts[3]);
}

Quaternion operator -(const Quaternion& lhs, const Quaternion& rhs) {

	return Quaternion(lhs.parts[0] - rhs.parts[0], lhs.parts[1] - rhs.parts[1], lhs.parts[2] - rhs.parts[2], lhs.parts[3] - rhs.parts[3]);
}

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


void exerciseQ() {

	Quaternion q[] = { Quaternion(1, 0, 0, 0), Quaternion(2, 2, 2, 2), Quaternion(0, -1, 0, 1) };
	Quaternion q_r = Quaternion(1, 0, 0, 0);
	Quaternion q_i = Quaternion(0, 1, 0, 0);
	Quaternion q_j = Quaternion(0, 0, 1, 0);
	Quaternion q_k = Quaternion(0, 0, 0, 1);
	Quaternion q_ijk = Quaternion(0, 1, 1, 1);
	Quaternion q_rijk = Quaternion(1, 1, 1, 1);
	Quaternion q_seq = Quaternion(1, 2, 3, 4);
	double d = 2.5;
	cout << "q[0] = " << q[0] << ", q[1] = " << q[1] << ", q[2] = " << q[2] << endl;
	cout << "q[0].conj() = " << q[0].conj() << ", q[1].conj() = " << q[1].conj() << ", + q[2].conj() = " << q[2].conj() << endl;
	cout << "q[0] + q[2] = " << q[0] + q[2] << endl;
	cout << "q[1] - q_ijk = " << q[1] - q_ijk << endl;
	cout << "q_seq == [1, 2, 3, 4] is " <<
		(q_seq == Quaternion(1, 2, 3, 4) ? "TRUE" : "FALSE") << endl;
	cout << "-q_rijk = " << -q_rijk << endl;
	cout << "q[2] + 2.5 = " << q[2] + d << endl;
	cout << "q_r * q_i = " << q_r * q_i << endl;
	cout << "q_i * q_j = " << q_i * q_j << endl;
	cout << "q_k * q_j = " << q_k * q_j << endl;
	cout << "q_ijk * q_seq = " << q_ijk * q_seq << endl;
	cout << "q[2] * 1.5 = " << q[2] * 1.5 << endl;
	cout << "q[2] * 2 = " << q[2] * 2 << endl;
	cout << "q[2] / 2.5 = " << q[2] / 2.5 << endl;
	cout << "3.5 * q[2] = " << 3.5 * q[2] << endl;
	cout << "unit vector of " << q[2] << " is " << q[2].getUnitVector() << endl;
	cout << "norm of " << q_ijk << " is " << q_ijk.norm() << endl;
	cout << "norm of " << q_rijk << " is " << q_rijk.norm() << endl;
	cout << "norm of " << q_seq << " is " << q_seq.norm() << endl;
	cout << endl << endl << endl;

}


int main() {

	exerciseQ();
	system("pause");

	return 0;
}