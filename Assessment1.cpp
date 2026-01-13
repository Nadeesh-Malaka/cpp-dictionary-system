/*
 * Project: Dictionary Management System
 * Language: C++
 * Author: Nadeesh Malaka
 * Date: January 2026
 * Description: A menu-driven program that loads a dictionary file,
 * searches for words, and displays alphabetical word ranges.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Word struct to hold dictionary entries
struct Word {
    string name;       // The word in the dictionary
    string type;       // Word type (v, n, adj, etc.)
    string definition; // Word definition(s)
};

// Function prototypes
void displayMenu();
void loadDictionary(vector<Word>& dictionary);
void searchWord(const vector<Word>& dictionary);
void firstAndLast(const vector<Word>& dictionary);
string getFullTypeName(const string& typeAbbrev);
string toLowerCase(const string& str);
string cleanString(string str); // Helper to remove invisible characters

/*
 * Function: main
 * Purpose: Entry point of the program, displays menu and processes user choices.
 * Author: Nadeesh Malaka
 */
int main() {
    vector<Word> Dictionary; // STL Vector to hold all Word instances
    int choice = 0;

    // Header for professional presentation
    cout << "----------------------------------------" << endl;
    cout << "      Dictionary Management System      " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Author:     Nadeesh Malaka" << endl;
    cout << "Date:       January 2026" << endl << endl;

    // Main menu loop
    while (true) {
        displayMenu();
        cout << "Enter your choice (1-4): ";

        // Defensive coding: Validate input
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(); // Clear the newline from input buffer

        cout << endl; // Formatting spacer

        switch (choice) {
        case 1:
            loadDictionary(Dictionary);
            break;
        case 2:
            searchWord(Dictionary);
            break;
        case 3:
            firstAndLast(Dictionary);
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
        cout << endl;
    }
    return 0;
}

/*
 * Function: displayMenu
 * Purpose: Displays the numbered main menu options to the user.
 */
void displayMenu() {
    cout << "========== MAIN MENU ==========" << endl;
    cout << "1. Load new Dictionary" << endl;
    cout << "2. Search Word" << endl;
    cout << "3. First and Last" << endl;
    cout << "4. Exit" << endl;
    cout << "===============================" << endl;
}

/*
 * Function: cleanString
 * Purpose: Removes semicolons, carriage returns (\r), and extra spaces from the end of a line.
 */
string cleanString(string str) {
    if (str.empty()) return str;

    // 1. Remove carriage return '\r' (common in Windows files)
    if (str.back() == '\r') str.pop_back();

    // 2. Remove semicolon ';' if present at the end
    if (!str.empty() && str.back() == ';') str.pop_back();

    // 3. Remove any trailing spaces
    while (!str.empty() && isspace(str.back())) {
        str.pop_back();
    }

    return str;
}

/*
 * Function: loadDictionary
 * Purpose: Loads and parses the dictionary file (dictionary_2026S0.txt).
 */
void loadDictionary(vector<Word>& dictionary) {
    ifstream file("dictionary_2026S0.txt");

    if (!file.is_open()) {
        cout << "Error: Could not open dictionary_2026S0.txt" << endl;
        cout << "Please ensure the file exists in the same directory as the program." << endl;
        return;
    }

    dictionary.clear();
    string line;
    int wordCount = 0;

    // Read file
    while (getline(file, line)) {
        // Skip empty lines
        if (cleanString(line).empty()) continue;

        Word newWord;

        // Line 1: Word Name
        newWord.name = cleanString(line);

        // Line 2: Word Type
        if (getline(file, line)) {
            newWord.type = cleanString(line);
        }

        // Line 3: Definition
        if (getline(file, line)) {
            newWord.definition = cleanString(line);
        }

        // Line 4: Blank Line (Consumed)

        dictionary.push_back(newWord);
        wordCount++;
    }

    file.close();
    cout << "Dictionary loaded successfully!" << endl;
    cout << "Total words loaded: " << wordCount << endl;
}

/*
 * Function: searchWord
 * Purpose: Searches for a user-provided word in the dictionary (case-insensitive).
 */
void searchWord(const vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "Error: No dictionary loaded." << endl;
        return;
    }

    string searchTerm;
    cout << "Enter the word to search: ";
    getline(cin, searchTerm);

    string searchLower = toLowerCase(searchTerm);
    vector<const Word*> matches;

    for (const auto& word : dictionary) {
        if (toLowerCase(word.name) == searchLower) {
            matches.push_back(&word);
        }
    }

    if (matches.empty()) {
        cout << "Word not found." << endl;
    }
    else {
        // Calculate definitions
        int definitionCount = 0;
        for (const auto* wordPtr : matches) {
            string def = wordPtr->definition;
            definitionCount++;
            size_t pos = 0;
            while ((pos = def.find(";  ", pos)) != string::npos) {
                definitionCount++;
                pos += 3;
            }
        }

        cout << "Word Found - with " << definitionCount << " definition";
        if (definitionCount != 1) cout << "s";
        cout << endl << endl;

        for (const auto* wordPtr : matches) {
            cout << "Word: " << wordPtr->name << endl;
            cout << "Type: " << getFullTypeName(wordPtr->type) << endl;
            cout << "Definition(s):" << endl;

            string def = wordPtr->definition;
            size_t start = 0;
            size_t pos;
            int defNum = 1;

            while ((pos = def.find(";  ", start)) != string::npos) {
                cout << "  " << defNum << ". " << def.substr(start, pos - start) << endl;
                start = pos + 3;
                defNum++;
            }
            cout << "  " << defNum << ". " << def.substr(start) << endl;
            cout << endl;
        }
    }
}

/*
 * Function: firstAndLast
 * Purpose: Prints the first and last alphabetical word for each letter.
 */
void firstAndLast(const vector<Word>& dictionary) {
    if (dictionary.empty()) {
        cout << "Error: No dictionary loaded." << endl;
        return;
    }

    cout << "========================================" << endl;
    cout << "  FIRST AND LAST WORDS BY LETTER" << endl;
    cout << "========================================" << endl;
    cout << "Letter    First Word         Last Word" << endl;
    cout << "----------------------------------------" << endl;

    for (char letter = 'a'; letter <= 'z'; letter++) {
        string minWord = "";
        string maxWord = "";
        bool foundAny = false;

        for (const auto& word : dictionary) {
            if (!word.name.empty() && tolower(word.name[0]) == letter) {
                if (!foundAny) {
                    minWord = word.name;
                    maxWord = word.name;
                    foundAny = true;
                }
                else {
                    string currentLower = toLowerCase(word.name);
                    string minLower = toLowerCase(minWord);
                    string maxLower = toLowerCase(maxWord);

                    if (currentLower < minLower) minWord = word.name;
                    if (currentLower > maxLower) maxWord = word.name;
                }
            }
        }

        if (foundAny) {
            cout << "  " << (char)toupper(letter) << "       ";
            cout.width(18);
            cout << left << minWord << " ";
            cout << maxWord << endl;
        }
    }
    cout << "========================================" << endl;
}

/*
 * Function: getFullTypeName
 * Purpose: Helper to convert abbreviations to full names.
 */
string getFullTypeName(const string& typeAbbrev) {
    string type = cleanString(typeAbbrev);
    if (type == "v") return "(verb)";
    if (type == "n") return "(noun)";
    if (type == "adj") return "(adjective)";
    if (type == "adv") return "(adverb)";
    if (type == "prep") return "(preposition)";
    if (type == "pn") return "(proper noun)";
    if (type == "n_and_v") return "(noun and verb)";
    if (type == "misc") return "(other)";
    return "(" + type + ")";
}

/*
 * Function: toLowerCase
 * Purpose: Helper to convert string to lowercase.
 */
string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}