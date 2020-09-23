#include <iostream> 
#include "Quaternion.h"


Quaternion::Quaternion(int s, int i, int j, int k) {

	parts[0] = s;
	parts[1] = i;
	parts[2] = j;
	parts[3] = k;

}

//double Quaternion :: getRe() {}

//double Quaternion :: norm() {}
//double Quaternion :: getIm(int n) {}

//Quaternion Quaternion :: getIm() {}
//Quaternion Quaternion :: conj() {}
//Quaternion Quaternion :: getUnitVector() {}

//Quaternion operator +(const Quaternion& q) {}
//Quaternion operator -(const Quaternion& q) {}
//Quaternion operator *(const Quaternion& q) {}
//Quaternion Quaternion :: operator -() const {}


int main() {

	Quaternion q = Quaternion(1, -1, 0, 1);

	std::cout << q << std::endl;
	system("pause");

	return 0;
}