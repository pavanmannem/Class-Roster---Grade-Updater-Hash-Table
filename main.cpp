#include <string>
#include <regex>
#include <tuple>

#include "HashTable.hpp"
#include "CSVEditor.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    regex expr(".*,.*,(.*),(.*)"); //regex for csv reading 
	
    string inputPath = "input.csv";
    string rosterPath = "roster.csv";
    string outputPath = "output.csv";
	
	int m = 0; //class size 

	//calculate class size 
	string line;
	ifstream file(rosterPath);
	while(!file.eof()){
		getline(file, line);
		m++; 
	}
	

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();
	
	tuple<int, int, double> stats = editor.getStats();
	cout << "minimum chain len = " << std::get<0>(stats) << endl;
	cout << "maximum chain len = " << std::get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;
	

}
