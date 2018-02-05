#include <string>
#include <fstream>
#include <iostream>

void print(const std::string& text, std::ostream& out = std::cout);	//конструктор1
void print(const std::string& text, std::ofstream& out);	//конструктор2
