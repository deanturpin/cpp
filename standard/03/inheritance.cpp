#include <iostream>

class base;
class derived1;
class derived2;
class derived3;
class derived4;
class friendly;

class doublederived1;
class doublederived2;
class doublederived3;
class doublederived4;

class base {

	public:
		int iampublic;

	protected:
		int iamprotected;

	private:
		int iamprivate;

	friend friendly;
};

class derived1 : public base {

	derived1() {
		iampublic = 1;
		iamprotected = 1;
		// iamprivate = 1; // error - private member of base class
	}
};

class doublederived1 : public derived1 {

	doublederived1() {
		iampublic = 1;
		iamprotected = 1;
		// iamprivate = 1; // error - private member of base class
	}
};

class derived2 : protected base {

	derived2() {
		iampublic = 1;
		iamprotected = 1;
		// iamprivate = 1; // error - private member of base class
	}
};

class doublederived2 : public derived2 {

	doublederived2() {
		iampublic = 1;
		iamprotected = 1;
		iamprivate = 1; // error - private member of base class
	}
};

class derived3 : private base {

	derived3() {
		iampublic = 1;
		iamprotected = 1;
		iamprivate = 1; // error - private member of base class
	}
};

class doublederived3 : public derived3 {

	doublederived3() {
		iampublic = 1;
		iamprotected = 1;
		iamprivate = 1; // error - private member of base class
	}
};

class derived4 : base { // default - implicitly private

	derived4() {
		iampublic = 1;
		iamprotected = 1;
		// iamprivate = 1; // error - private member of base class
	}
};

class doublederived4 : public derived4 {

	doublederived4() {
		iampublic = 1;
		iamprotected = 1;
		iamprivate = 1; // error - private member of base class
	}
};

class friendly {

	friendly() {
		base b;
		b.iamprivate = 1;
	}
};

int main() {
	return 0;
}
