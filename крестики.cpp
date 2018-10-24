#include<iostream>
#include<ctime>
using namespace std;
bool IS_TRue_x(unsigned a[][3]) {
	unsigned magicvalue = 12,sum=0;
	for (unsigned i = 0;i < 3;i++) {
		sum = 0;
		for (unsigned j = 0;j < 3;j++) {
			sum += a[i][j];
		}
		if (sum == magicvalue) {
			return true;
		}
	}
	for (unsigned i = 0;i < 3;i++) {
		sum = 0;
		for (unsigned j = 0;j < 3;j++) {
			sum += a[j][i];
		}
		if (sum == magicvalue) {
			return true;
		}
	}
	sum = 0;
	for (unsigned i = 0;i < 3;i++) {
		for (unsigned j = 0;j < 3;j++) {
			if (i == j) {
				sum += a[i][j];
			}
		}
		if (sum == magicvalue) {
			return true;
		}
	}

	return false;
}
bool IS_TRue_o(unsigned a[][3]) {
	unsigned magicvalue = 3, sum = 0;
	for (unsigned i = 0;i < 3;i++) {
		sum = 0;
		for (unsigned j = 0;j < 3;j++) {
			sum += a[i][j];
		}
		if (sum == magicvalue) {
			return true;
		}
	}
	for (unsigned i = 0;i < 3;i++) {
		sum = 0;
		for (unsigned j = 0;j < 3;j++) {
			sum += a[j][i];
		}
		if (sum == magicvalue) {
			return true;
		}
	}
	for (unsigned i = 0;i < 3;i++) {
		sum = 0;
		for (unsigned j = 0;j < 3;j++) {
			if (i == j) {
				sum += a[i][j];
			}
		}
		if (sum == magicvalue) {
			return true;
		}
	}
	return false;
}
bool IS_nichia(char a[][3]) {
	unsigned n = 0;
	for (unsigned i = 0;i < 3;i++) {
		for (unsigned j = 0;j < 3;j++) {
			if (a[i][j] == 'x' || a[i][j] == 'o') {
				n++;
			}
		}
	}
	if (n == 9) return true;
	else return false;
}
int main() {
	srand(time(NULL));
	char a[3][3] = {' '};
	unsigned  a2[3][3] = {};
	unsigned choice;
	
	cout << "1 - chelovek, 2 - MACHINE_CYBER_PUNK"<<endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		while (true) {
			unsigned i, j;
			cout << "v kakuy yacheiku zapisat(i,j) 1 - person" << endl;
		label1:cin >> i >> j;
			if (i < 0 || i>2 || j < 0 || j>2) goto label1;
			if (a[i][j] != 'x'&& a[i][j] != 'o') {
				a[i][j] = 'x';
				a2[i][j] = 4;
				for (unsigned i = 0;i < 3;i++) {
					for (unsigned j = 0;j < 3;j++) {

						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "yazhechka zanyata" << endl;
				goto label1;
			}
			if (IS_TRue_x(a2) == true) {
				cout << "x vygral" << endl;
				break;
			}
			cout << "v kakuy yacheiku zapisat(i,j) 2 - person" << endl;
		label:cin >> i >> j;
			if (i < 0 || i>2 || j < 0 || j>2) goto label;
			if (a[i][j] != 'x'&& a[i][j] != 'o') {
				a[i][j] = 'o';
				a2[i][j] = 1;
				for (unsigned i = 0;i < 3;i++) {
					for (unsigned j = 0;j < 3;j++) {
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "yazhechka zanyata" << endl;
				goto label;
			}
			if (IS_TRue_o(a2) == true) {
				cout << "o vygral" << endl;
				break;
			}
		}
		break;

	case 2:
		while (true) {
			unsigned i, j;
			cout << "v kakuy yacheiku zapisat(i,j)" << endl;
		label2:cin >> i >> j;
			if (i < 0 || i>2 || j < 0 || j>2) { cout << "mnogo" << endl;goto label2; }
			if (a[i][j] != 'x'&& a[i][j] != 'o') {
				a[i][j] = 'x';
				a2[i][j] = 4;
			}
			else {
				cout << "yazhechka zanyata" << endl;
				goto label2;
			}
			if (IS_TRue_x(a2) == true) {
				cout << "x vygral" << endl;
				break;
			}
			if (IS_nichia(a) == true && IS_TRue_x(a2) == false) {
				cout << "nichia" << endl;
				break;
			}
		label3:i = rand()%3;
			j = rand() % 3;
			if (a[i][j] != 'x'&& a[i][j] != 'o') {
				a[i][j] = 'o';
				a2[i][j] = 1;
				for (unsigned i = 0;i < 3;i++) {
					for (unsigned j = 0;j < 3;j++) {
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
			}
			else {
				goto label3;
			}
			if (IS_TRue_o(a2) == true) {
				cout << "o vygral" << endl;
				cout << "CYBER_PUNK" << endl;
				break;
			}
			if (IS_nichia(a) == true && IS_TRue_o(a2) == false) {
				cout << "nichia" << endl;
				break;
			}
		}
		break;
	default:
		cout << "net" << endl;
		break;
	}
	system("pause");
	return 0;
}