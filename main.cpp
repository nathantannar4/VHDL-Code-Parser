//Use only the following three libraries:
#include "parserClasses.h"
#include <iostream>
#include <fstream>

using namespace std;

//Example Test code for interacting with your Token, TokenList, and Tokenizer classes
//Add your own code to further test the operation of your Token, TokenList, and Tokenizer classes
int main() {
	ifstream sourceFile;
	TokenList tokens;
	Tokenizer tokenizer;

	//Read in a file line-by-line and tokenize each line
	sourceFile.open("test.txt");
	if (!sourceFile.is_open()) {
		cout << "Failed to open file" << endl;
		return 1;
	}

	while(!sourceFile.eof()) {
		string lineA, lineB;

		getline(sourceFile, lineA);

		while(lineA.length() > 0 && lineA[lineA.length()-1] == '\\') {
			lineA.erase(lineA.length()-1, 1);
			getline(sourceFile, lineB);
			lineA = lineA + lineB;
		}
        cout << lineA << endl << endl;
        tokenizer.setString(&lineA);
        cout << lineA << endl << endl;



		/*
		while (!tokenizer.isComplete())
        {
            cout << "[" << tokenizer.getNextToken() << "] ";
        }
        cout << endl;
        */


		//while the current line ends with a line-continuation \ append the next line to the current line
		/*



		while(!tokenizer.isComplete()) {
			tokens.append(tokenizer.getNextToken());
		}
		//Re-insert newline that was removed by the getline function
		tokens.append("\n");

		*/
	}



	/*Test your tokenization of the file by traversing the tokens list and printing out the tokens*/
	Token *t = tokens.getFirst();
	while(t) {
		cout << t->getStringRep() << " ";
		t = t->getNext();
	}

	return 0;
}
