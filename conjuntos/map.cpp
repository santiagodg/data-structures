#include <map>
#include <iostream>

using namespace std;

int main() {
	map<string, int> m;
	int n, edad;
	string nombre;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nombre >> edad;
		m[nombre] = edad;
	}

	cout << "Nombre a buscar: ";
	cin >> nombre;
	// cout << m[nombre] << endl;

	map<string, int>::iterator it = m.find(nombre);
	if (it != m.end()) {
		cout << "Edad: " << it->second << endl;
	} else {
		cout << "No esta :(" << endl;
	}

	return 0;
}
