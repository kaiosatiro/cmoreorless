#include <iostream>
#include <iomanip> 
#include <fstream>
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        // std::cout << std::resetiosflags(std::cout.flags());
        
        std::cout 
            << std::showbase
            << std::nouppercase
            << std::hex
            << std::left
            << long (A) 
            <<  "\n";
        std::cout
            << std::setw(15)
            << std::setfill('_')
            << std::right
            << std::showpos
            << std::fixed 
            << std::setprecision(2)
            << B
            << "\n";
        std::cout
            << std::noshowpos
            << std::uppercase
            << std::scientific
            << std::setprecision(9)
            << C
            << "\n";

        std::ofstream outputFile("output.txt", std::ios::app);

        outputFile
            << std::showbase
            << std::nouppercase
            << std::hex
            << std::left
            << long (A) 
            <<  "\n";
        outputFile
            << std::setw(15)
            << std::setfill('_')
            << std::right
            << std::showpos
            << std::fixed 
            << std::setprecision(2)
            << B
            << "\n";
        outputFile
            << std::noshowpos
            << std::uppercase
            << std::scientific
            << std::setprecision(9)
            << C
            << "\n";

        outputFile.close();
	}
	return 0;

}
