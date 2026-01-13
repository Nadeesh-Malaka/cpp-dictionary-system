# Dictionary Management System (C++)

A console-based Dictionary Management System implemented in C++ for CSP2104 Object-Oriented Programming course.

## ?? Assignment Details
- **Course**: CSP2104 Object-oriented Programming with C++
- **Assignment**: Assessment 1 - Dictionary Menu Program
- **Author**: Ransini
- **Student ID**: 10705203
- **Date**: January 8, 2026

## ?? Features

### 1. Load Dictionary
- Reads dictionary data from `dictionary_2026S0.txt`
- Parses word names, types, and definitions
- Handles file format variations and special characters
- Displays total words loaded

### 2. Search Word
- Case-insensitive word search
- Supports multiple definitions per word
- Displays word type with full names (noun, verb, adjective, etc.)
- Numbered definition output

### 3. First and Last Words
- Displays alphabetically first and last words for each letter (A-Z)
- Formatted table output
- Handles letters with no words gracefully

### 4. Exit
- Clean program termination

## ?? File Structure
```
Ransini_10705203/
??? Assessment1.cpp          # Main program file
??? dictionary_2026S0.txt    # Dictionary data file (required)
??? README.md                # This file
??? .gitignore               # Git ignore rules
```

## ?? Requirements
- **Compiler**: C++11 or later
- **Libraries**: Standard Template Library (STL)
  - `<iostream>` - Input/output operations
  - `<fstream>` - File handling
  - `<vector>` - Dynamic arrays
  - `<string>` - String operations
  - `<algorithm>` - String transformations
  - `<cctype>` - Character handling
- **Data File**: `dictionary_2026S0.txt` must be in the same directory as executable

## ?? How to Compile and Run

### Using g++ (Command Line):
```bash
# Compile
g++ -std=c++11 Assessment1.cpp -o DictionaryApp

# Run (Windows)
DictionaryApp.exe

# Run (Linux/Mac)
./DictionaryApp
```

### Using Visual Studio:
1. Open Visual Studio
2. Create new project: "Create a new project" ? "Console App"
3. Add `Assessment1.cpp` to the project
4. Place `dictionary_2026S0.txt` in the project directory
5. Press `Ctrl+F5` to build and run

### Using Dev-C++ or Code::Blocks:
1. Create new project
2. Add `Assessment1.cpp` as source file
3. Build and run (F9 or F11)

## ?? Usage Instructions

1. **Start the Program**
   ```
   ----------------------------------------
         Dictionary Management System      
   ----------------------------------------
   Author:     Ransini
   Student ID: 10705203
   Date:       January 8, 2026
   ```

2. **Main Menu Options**
   ```
   ========== MAIN MENU ==========
   1. Load new Dictionary
   2. Search Word
   3. First and Last
   4. Exit
   ===============================
   ```

3. **Load Dictionary** (Option 1)
   - Loads the dictionary file
   - Must be done before searching or displaying words
   - Shows confirmation and word count

4. **Search Word** (Option 2)
   - Enter word to search (case-insensitive)
   - Displays all definitions if found
   - Shows "word not found" if not in dictionary

5. **First and Last** (Option 3)
   - Shows alphabetical range for each letter
   - Only displays letters that have words

6. **Exit** (Option 4)
   - Closes the program

## ?? Technical Implementation

### Data Structure
```cpp
struct Word {
    string name;       // The word
    string type;       // Word type (v, n, adj, etc.)
    string definition; // Definition(s)
};

vector<Word> Dictionary; // STL Vector for storage
```

### Key Features
- **Input Validation**: Handles invalid menu choices and non-numeric input
- **Case-Insensitive Search**: Converts to lowercase for comparison
- **Robust File Parsing**: Handles carriage returns, semicolons, and extra spaces
- **Memory Efficient**: Uses references and const pointers
- **Defensive Programming**: Checks for empty dictionary before operations

### Word Type Abbreviations
| Abbreviation | Full Name |
|--------------|-----------|
| v | verb |
| n | noun |
| adj | adjective |
| adv | adverb |
| prep | preposition |
| pn | proper noun |
| n_and_v | noun and verb |
| misc | other |

## ??? Error Handling
- File not found error with helpful message
- Empty dictionary check before operations
- Input validation for menu choices
- Graceful handling of malformed data

## ?? Dictionary File Format
```
word_name
word_type
definition1;  definition2;  definition3

next_word
type
definition

```

## ?? Academic Integrity
This project is submitted as part of CSP2104 coursework at Edith Cowan University. All code is original work by the author.

## ?? License
Academic Project - Educational Use Only

## ?? Contact
- **Author**: Ransini
- **Student ID**: 10705203
- **Institution**: Edith Cowan University
- **Course**: CSP2104 Object-oriented Programming with C++

---

**Note**: Ensure `dictionary_2026S0.txt` is present in the same directory as the compiled executable before running the program.
