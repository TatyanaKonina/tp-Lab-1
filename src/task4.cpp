#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;

vector <int> convert(char* x) {
	vector <int> dijit;
    for (int i = (int)strlen(x); i > 0; i--) {
		x[i] = 0;
		dijit.push_back(atoi(i >= 1 ? x + i - 1 : x));
	}
    while (dijit.size() > 1 && dijit.back() == 0)
		dijit.pop_back();
	return dijit;
}

char* sum( char* x,  char* y){
	vector <int> dijit1 = convert(x);
	vector <int> dijit2 = convert(y);
	const int base{ 10 };
	int carry{ 0 };
	char* res = new char[dijit1.size()]();

	for (size_t i = 0; i < max(dijit1.size(), dijit2.size()) || carry; ++i) {
		if (i == dijit1.size()) {
			dijit1.push_back(0);
		}
		dijit1[i] += carry + (i < dijit2.size() ? dijit2[i] : 0);
		carry = dijit1[i] >= base;
		if (carry) {
			dijit1[i] -= base;
		}
	}
	int pointer{ 0 };
	/*printf("%d", dijit1.empty() ? 0 : dijit1.back());
	for (int i = (int)dijit1.size() - 2; i >= 0; --i) {
		res[i] = dijit1[i];
		printf("%09d", dijit1[i]);
	}
	res[dijit1.size()] = '\0'; */
	for (int i = dijit1.size(); i > 0; i--) {
		
		res[dijit1.size() - i] = dijit1[i - 1] + '0';
	}
	res[dijit1.size()] = '\0';

    return res;
}
