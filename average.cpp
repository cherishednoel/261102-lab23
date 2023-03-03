#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 1) cout << "Please input numbers to find average." << endl;
    else {
        cout << "---------------------------------\n";
        cout << "Average of " << argc-1 << " numbers = ";
        int sum = 0;
        for(int i = 1; i < argc; i++) {
            sum += atoi(argv[i]);
        }
        cout << sum/(argc-1) << endl;
        cout << "---------------------------------\n";
    }

    return 0;
}