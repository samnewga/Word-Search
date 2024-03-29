#include "pch.h"
#include <iostream>
#include <fstream>
#include  <string>
#include <algorithm>

using namespace std;

// word
string word;

// used for getting the lines of the paragraph text file
string line;

//used to store the text of the paragraphs file
string paragraphsText;

// Finds word inside text file and prints them to an output file
int main() {
	//count 
	int count;

	//length of text size
	int length;

	// word list file
	ifstream wordsFile;

	//paragraphs text file
	ifstream paragraphsFile;

	//output file to write to
	ofstream output("output.txt");

	//The following code open up the two files
	wordsFile.open("words.txt");
	paragraphsFile.open("paragraph.txt");


	// We iterate through the paragraph file andd the text to the string
	while (getline(paragraphsFile, line)) {
		paragraphsText += line;
	}

	// length is the length of the paragraphsText string
	length = paragraphsText.length();

	// Iterate through the paragraph text to find any punctuation and remove it
	for (int i = 0; i < length; i++)
	{
		//ispunct will find any puncuation. We then remove it
		if (ispunct(paragraphsText[i])) {
			paragraphsText.erase(i--, 1);
			length = paragraphsText.length();
		}
	}

	//convert all of the text in paragraphsText to lower text.
	transform(paragraphsText.begin(), paragraphsText.end(), paragraphsText.begin(), tolower);


	cout << paragraphsText << endl << endl;

	//close the paragraph file
	paragraphsFile.close();

	// iterate through all of the words
	// we also change all of the characters to lowercase letters
	for (int i = 0; i < 10; i++)
	{

		count = 0;

		wordsFile >> word;
		transform(word.begin(), word.end(), word.begin(), tolower);

		size_t position = paragraphsText.find(word, 0);

		// while we are not at the end of the string we increase the position integer
		while (position != string::npos) {
			position = paragraphsText.find(word, position + 1);
			count++;

		}

		output << word << " found " << count << " times." << endl << endl;

	}

	//Close wordsFIle and the output file
	wordsFile.close();
	output.close();

	system("pause");
	return 0;
}



