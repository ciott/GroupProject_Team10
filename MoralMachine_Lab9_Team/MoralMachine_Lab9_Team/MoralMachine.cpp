#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct profiles {

	enum gender {MAN, WOMAN};
	enum age {ELDERLY, ADULT, TEEN, CHILD, BABY};
	enum species {ANIMAL, CAT, DOG, HUMAN};
	enum status {DRIVER, CRIMINAL, HOMELESS, DOCTOR};

};

class person {

	string setAge() {

	};
};

int main() {

	int const carSize = 5;
	vector <person> seat[carSize];
	cout << "MORAL MACHINE" << endl;
	
	cout << "FILL CAR" << endl;
	for (int occupant = 0; occupant < carSize; ++occupant) {

		cin >> seat[occupant].setAge();
	}
	
	// person has characteristics.
	// we have to fill the car with people.

	return 0;
}