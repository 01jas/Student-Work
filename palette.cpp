// check if terminal can print color properly
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void test_foreground() {
    for(int i = 0; i < 256; i++) {
		if(i % 36 == 16)
			cout << endl;
        cout << "\e[38;5;" << i << "m";
        cout << setw(3) << setfill(' ') << i;
        cout << "\e[0m";
    }
	cout << endl;
}

void test_background() {
    for(int i = 0; i < 256; i++) {
		if(i % 36 == 16)
			cout << endl;
        cout << "\e[48;5;" << i << "m";
        cout << setw(3) << setfill(' ') << i;
        cout << "\e[0m";
    }
	cout << endl;
}

int main()
{
#ifdef _WIN32
	system("chcp 65001");
#endif
    test_foreground();
    test_background();
    return 0;
}
