#include "std_lib_facilities.h"

struct Person {
private:
	string firstName;
	string lastName;
	int age;
public:
	Person(){};
	Person(string fn, string ln, int a){
		firstName = fn;
		lastName = ln;
		age = a;
	};

	void set_first_name(string fn) { firstName = fn; }
	void set_last_name(string ln) { lastName = ln; }
	void set_age(int a) { age = a; }

	string get_name() const {return firstName+" "+lastName; }
	int get_age() const {return age; }
};

bool isnumber(string a) {
	int letterCount = 0;
	int numberCount = 0;

	for(auto letter : a) {
		letterCount++;
		if (isdigit(letter)) { numberCount++; }
	}
	if (letterCount == numberCount) { return true; }
	else { return false; }
}

istream& operator>> (istream& is, Person& p) {
	string fname;
	string lname;
	int age;

	is>>fname;
	for (auto letter : fname) {
		if (!isalpha(letter)) { error("The name cannot contain special characters or numbers!"); }
	}
	p.set_first_name(fname);

	is>>lname;
	if (isnumber(lname)) { error("Also enter a last name!"); }
	for (auto letter : lname) {
		if (!isalpha(letter)) { error("The name cannot contain special characters or numbers!"); }
	}
	p.set_last_name(lname);

	is>>age;
	if (age < 0 || age > 150) { error("Age range: [0, 150]"); }
	p.set_age(age);

	return is;
}

ostream& operator<< (ostream& os, Person& p) {
	os << p.get_name() << ", " << p.get_age();
	return os;
}

int main()
{
	Person player;
	/*player.name = "Goofy";
	player.age = 63;
	cout << player.name << ", " << player.age << endl;*/

	cout << "Please write a name and an age: (name age)" << endl;
	cin >> player;
	cout << player << endl;

	cout << "Enter some persons" << endl;
	vector<Person> persons;
	Person temp;
	while (cin>>temp) {
		persons.push_back(temp);
		cout << persons[persons.size()-1] << endl;
	}

	return 0;
}