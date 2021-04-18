#include "std_lib_facilities.h"

template<class T>
struct S {
private:
	T val;
public:
	S() : val(T()) { }
	S(T d) : val(d) { } //2.
	S(const S&);

	T& operator=(const T&); //10

	T& get(); //5
	const T& get() const; //11

	void set(const T& d); //9

};

template<class T> T& S<T>::operator=(const T& d) //10
{
	val = d;
	return val;
}

template<class T> T& S<T>::get() { return val; } //6
template<class T> const T& S<T>::get() const { return val; } //11
template<class T> void S<T>::set(const T& d) { val = d; } //9

template<class T> istream& operator>>(istream& is, S<T>& ss) //13
{
	T v;
	cin >> v;
	if (!is) return is;
	ss = v;
	return is;
}

template<class T> //12
void read_val(T& v)
{
	cin >> v;
}

int main()
{
	S<int> s_int(15);
	S<char> s_char('b');
	S<double> s_dbl(1.92);
	S<string> s_strg("asd123");
	S<vector<int>> s_v_int(vector<int> {15, 18, 20, 12});


	cout << "s_int: " << s_int.get() << "\n";
	cout << "s_char: " << s_char.get() << "\n";
	cout << "s_dbl: " << s_dbl.get() << "\n";
	cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i < s_v_int.get().size(); ++i)
		cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	cout << "" << endl;

	s_int.set(12);
	s_char.set('d');
	s_dbl.set(5.48);
	s_strg.set("321dsa");
	s_v_int.set(vector<int> {25, 34, 546, 845});

	cout << "s_int: " << s_int.get() << "\n";
	cout << "s_char: " << s_char.get() << "\n";
	cout << "s_dbl: " << s_dbl.get() << "\n";
	cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i < s_v_int.get().size(); ++i)
		cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	cout << "" << endl;

	s_int = 18;
	s_char = 'g';
	s_dbl = 7.12;
	s_strg = "teszt";
	s_v_int = vector<int> {54, 156, 15, 84};

	cout << "s_int: " << s_int.get() << "\n";
	cout << "s_char: " << s_char.get() << "\n";
	cout << "s_dbl: " << s_dbl.get() << "\n";
	cout << "s_strg: " << s_strg.get() << "\n";
	for (int i = 0; i < s_v_int.get().size(); ++i)
		cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";

	cout << "" << endl;

	cout << "s_int: ";
	read_val(s_int);
	cout << "s_char: ";
	read_val(s_char);
	cout << "s_dbl: ";
	read_val(s_dbl);
	cout << "s_strg: ";
	read_val(s_strg);

	cout << "s_int: " << s_int.get() << "\n";
	cout << "s_char: " << s_char.get() << "\n";
	cout << "s_dbl: " << s_dbl.get() << "\n";
	cout << "s_strg: " << s_strg.get() << "\n";

	cout << "" << endl;

	return 0;
}