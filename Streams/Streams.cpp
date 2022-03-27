//#include <iostream>
//#include <string>
//
//int main() {
//    std::string name;
//    std::cin >> name;
//    std::cout << "Hello World!\nI am " << name << std::endl;
//}

//#include <iostream>
//#include <string>
//
//int main() {
//    std::ostream& theOutStream = std::cout;
//    std::istream& theInStream = std::cin;
//    std::string name;
//    theInStream >> name;
//    theOutStream << "Hello World!\nI am " << name << std::endl;
//
//    return 0;
//}

//#include <fstream>
//#include <string>
//
//int main() {
//	std::string inputFileData;
//	std::string outputFileData;
//
//	// reading file data
//	std::ifstream theInputStream;
//	theInputStream.open("./InputFile.txt");
//
//	if (theInputStream.is_open()) {
//		while (!theInputStream.eof()) {
//			// Read word from input file
//			theInputStream >> inputFileData;
//			// Store word and newline
//			outputFileData += inputFileData + "\n";
//		}
//	}
//	theInputStream.close();
//	
//	// writing file data
//	std::ofstream theOutputStream;
//	theOutputStream.open("./OutputFile.txt");
//
//	theOutputStream << outputFileData;
//
//	theOutputStream.close();
//
//	return 0;
//}

//#include <fstream>
//#include <string>
//#include <iostream>
//
//int main() {
//	std::string inputFileData;
//	std::string outputFileData;
//
//	std::fstream theStream("./TextFile.txt", std::ios::in | std::ios::out | std::ios::app);
//
//	// reading file data
//	std::cout << "Reading\n" << theStream.tellg() << "\n";
//
//	if (theStream.is_open()) {
//		while (!theStream.eof()) {
//			// Read word from input file
//			theStream >> inputFileData;
//			// Store word and newline
//			outputFileData += inputFileData + "\n";
//			std::cout << theStream.tellg() << "\n";
//		}
//	}
//
//	// writing file data
//	theStream.clear(); // must clear since eof raises a flag
//	std::cout << "Writing\n" << theStream.tellp();
//
//	theStream << "\n\nWriting Here\n" << outputFileData;
//
//	theStream.close();
//
//	return 0;
//}

//#include <iostream>
//#include <sstream>
//#include <string>
//
//int main() {
//	std::string theWords = "Hello, I am a word!";
//	std::stringstream theStream(theWords);
//
//	int count = 0;
//	std::string word;
//	while (theStream >> word) {
//		count++;
//	}
//	std::cout << count << std::endl; // outputs 5
//}
