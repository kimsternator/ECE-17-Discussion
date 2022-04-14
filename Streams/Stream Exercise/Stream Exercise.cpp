// Stream Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

/* Word Shape
{
    "WORD": "aardvark",
    "POS": "noun",
    "CATEGORY": "animal"
},
Trailing comma may not be present in last object
*/

// Word Bins (word type, vector of words)
using WordBin = std::unordered_map<std::string, std::vector<std::string>>;

// Get the value in the key-value line from a Word Object
std::string getWord(const std::string& aLine) {
    size_t thirdQuotePos = aLine.find('\"', aLine.find(":"));
    size_t fourthQuotePos = aLine.find('\"', thirdQuotePos);

    if (thirdQuotePos == std::string::npos && fourthQuotePos == std::string::npos) {
        throw std::exception("Unexpected Word Shape");
    }

    return aLine.substr(thirdQuotePos + 1, fourthQuotePos - thirdQuotePos - 1);
}

void readWord(std::ifstream& aStream, WordBin& aWordBin) {
    const size_t NUM_OF_ITEMS{ 3 };
    // Read the elements of a word object
    std::vector<std::string> wordInfo(NUM_OF_ITEMS);
    for (size_t i = 0; i < NUM_OF_ITEMS; i++) {
        std::getline(aStream, wordInfo[i]);
    }
    // Add words to bins
    aWordBin[getWord(wordInfo[1])].push_back(getWord(wordInfo[0]));
    aWordBin[getWord(wordInfo[2])].push_back(getWord(wordInfo[0]));
    // Get the last curly brace
    std::string wordObjectEnd;
    std::getline(aStream, wordObjectEnd);
    wordObjectEnd.erase(
        std::remove_if(wordObjectEnd.begin(), wordObjectEnd.end(), isspace),
        wordObjectEnd.end());
    if (wordObjectEnd != "}" && wordObjectEnd != "},") {
        throw std::exception("Error Parsing File");
    }
}

int main() {
    const std::string fileName = "S:\\Documents\\TA\\ECE 17\\Stream Exercise\\Stream Exercise\\words.json";
    std::ifstream theStream(fileName);
    if (theStream.is_open()) {
        std::string line;
        std::string theWords;
        
        WordBin wordBins;

        while (theStream) {
            // Read Line
            std::getline(theStream, line);
            // Remove Punctuation
            line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
            // Enter if we're reading the start of a word
            if ("{" == line) {
                readWord(theStream, wordBins);
            }
        }

        theStream.close();
    }
}
