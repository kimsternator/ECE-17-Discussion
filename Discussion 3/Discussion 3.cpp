// Discussion 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
streams
strings

encapsulation
inheritance
polymorphism
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void strings() {
	// Initialization: (), =
	std::string theString; // ""
	std::string theString1("String value"); // RAII (Resource Acquisition Is Initialization) - length 12
	std::string theString2 = "String value";
	// length, size functions are similar in that they return the number of elements in a collection
	/* Examples of size in different collections
	theString.size();
	theVector.size();
	theStack.size();
	themap.size()
	*/
	// [] 0 - 11
	auto theChar = theString1[4];
	for (size_t i = 0; i < 2; i++) {}
	for (auto c : theString1) {}
	for (auto it = theString1.begin(); it != theString1.end(); it++) {}
	/* Iterator example
	1 2 3 4 
	theString1.begin() theString1.begin() + 1, theString1.begin() + 2, theString1.begin()+ 3 theString1.end()
	*/
	
	// pa2 -> replace, +=, insert, find (functions that might be useful for Assignment 2)
	// += appends values to the end
	theString2 = theString2 + "String value";
	theString2 += "\n";

	// replace
	/* Two iterators for any collection
	theString2.begin(); -> S
	theString2.end(); -> e
	*/

	// *(theString2.begin()); Dereferencing the iterator to return the value
	// abc -> acc replacing all instances of b with c
	std::string theString4("abccbbbccc");
	// String class replace
	theString4.replace(theString4.begin(), theString4.end(), 'b', 'c');
	// STL replace
	std::replace(theString4.begin(), theString4.end(), 'b', 'c');
	// replace part of a string with another *One Time
	theString4.replace(theString4.find("ccc"), 3, "rep");
	// replace all instances
	std::string replacement = "rep";
	size_t repLength = 3;
	std::string finder = "ccc";

	size_t theResult;
	do {
		theResult = theString4.find(finder);
		if (theResult == std::string::npos) { // npos is no position (a really big number *garbage)
			break;
		}
		theString4.replace(theResult, repLength, replacement);
	} while (theResult != std::string::npos);

	// insert - Inserts a string at a certain position
	theString4.insert(3, "z");

	// find - Finds a string, char within a string
	size_t theResult2 = theString4.find("llll");
	// return npos if not found
}

// pass-by-value
void function(int a) {
	a += 1;
}
// pass-by-reference
void function(int& a) {
	a += 1;
}

void streams() {
	// input, output
	std::cout;
	std::string var;
	std::cin >> var;
	// file input, output - escape characters \n \0 \t
	// In order to represent \ in the filepath, we need to write the escape character \\     
	// File path is the specific location of a ceretain file.
	std::ifstream theStream("C:\\Users\\steph\\Documents\\Class\\TA\\ECE 17\\ECE-17-Discussion\\Discussion 3\\TextFile.txt");
	std::ofstream theOstream;
	std::fstream theFstream;
	// GET, PUT (reading, writing)
	// seek, tell
	// tell -> tell the location pointer tellg, tellp
	// seek -> moves the pointer to the specified location seekp, seekg
	// End of file - eof

	/* How to read an entire file
	while (!fileStream.eof()) {
		reading here
	}
	*/

	// Be sure to close the files once we are done with them to prevent memory leaks
	// theFileStream.close();
}

class Encapulation {
public:

private:
};

class Animal {
public:
	void speak() {
		std::cout << "???\n";
	}
private:
};

class Dog : public Animal {
public:

private:
};

void inheritance() {

}

void polymorphism() {

}

int main() {
	//strings();
	streams();
	inheritance();
	polymorphism();
}
