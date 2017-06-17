#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        // Tell the user how to run the program
        std::cerr << "Usage: " << argv[0] << " <header_file> where the header should contain the configuration for the running system." << std::endl;
        return 1;
    }
    std::cout << argv[0] << "says hello, " << argv[1] << "!" << std::endl;
    return 0;
}
b
