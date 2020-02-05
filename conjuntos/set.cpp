#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> s;
	int n, dato;

	cin >> n;
	for( int i = 0; i < n; i++ ) {
		cin >> dato;
		s.insert(dato);
	}

	cout << "dato a buscar: " ;
	cin >> dato;

	set<int>::iterator it = s.find(dato);

	if( it != s.end() ) {
		cout << "si esta" << endl;
	} else {
		cout << "no esta" << endl;
	}

	return 0;
}
