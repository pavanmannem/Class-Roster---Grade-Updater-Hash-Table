#include "CSVEditor.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <regex>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

CSVEditor::CSVEditor(string& inputPath, string& rosterPath, string& outputPath, regex expr, int m) {
	regexPattern = expr;
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);

	hashTable = new HashTable<string>(m); 

}

CSVEditor::~CSVEditor(){
	delete hashTable;
	hashTable = nullptr;

	input.close();
	roster.close();
	output.close();
}

void CSVEditor::readCSVToTable() {
	smatch match;
	string line;
	if (input.is_open()) {
		while (getline(input, line)) {
			regex_search(line, match, regexPattern);
			hashTable->insert(std::stoi(match[1]), match[2]);

		}
	}
	else {
		cout << "Error: File input.csv not opened" << endl;
	}


}


void CSVEditor::writeCSVToFile() {
	smatch match;
	string line;

	if (output.is_open()) {
		if (roster.is_open()) {
			while (getline(roster, line)) {
				regex_search(line, match, regexPattern);
				int key = std::stoi(match[1]);
				if (hashTable->search(key) != nullptr){
					line.erase(line.end()-1); //remove newline
					output << line;
					output << *(hashTable->search(key)) << endl;
				}
				else {
					output << line;
				}

			}
		}
		else {
			cout << "Error: File roster.csv not opened" << endl;
		}
	}
	else {
		cout << "Error: File output.csv not opened" << endl;
	}


}

tuple<int, int, double> CSVEditor::getStats(){
	int min = hashTable->minChainLen();
	int max = hashTable->maxChainLen();
	double avg = hashTable->averageChainLen();
	return make_tuple(min,max,avg);
}