#include <iostream>
#include <random>
#include <fstream>
#include <string>

int generateNote(int lower, int upper) {
	std::random_device rd;
	std::mt19937 e2(rd());

	std::uniform_int_distribution<int> dist(lower,upper);

	return dist(e2);
}


int main(int argc, char** argv)
{
	std::ifstream file;
	std::string name;

	if(argc != 4) {
		std::cout << "Usage: " << std::endl;
		std::cout << argv[0] << " <lower bound> <higher bound> <name_to_except>" << std::endl;
		return 1;
	}

	std::string except = argv[3];

	int lower = atoi(argv[1]);
	int upper = atoi(argv[2]);

	file.open("data/names.txt");

	while(file >> name) {
		if(name == except){
			std::cout << "Magda: 5" << std::endl;
		} else {
			std::cout << name << ": " << generateNote(lower, upper) << std::endl;
		}	
	}
}

