# 📚 Dictionary Management System (C++)

![Language](https://img.shields.io/badge/Language-C++11-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A robust, console based Dictionary Management System that parses, searches, and organizes dictionary data efficiently using the Standard Template Library (STL).

---

## 📑 Table of Contents
- [✨ Key Features](#-key-features)
- [📂 File Structure](#-file-structure)
- [🚀 How to Compile and Run](#-how-to-compile-and-run)
- [📖 Usage Guide](#-usage-guide)
- [⚙️ Technical Implementation](#-technical-implementation)
- [📝 Input Data Format](#-input-data-format)
- [👨‍💻 Author](#-author)

---

## ✨ Key Features

### 1. 📥 Load Dictionary
- Parses raw text data from `dictionary_2026S0.txt`.
- Robust Parsing: Automatically cleans invisible characters such as Windows `\r` and handles messy formatting.
- Displays the total count of loaded words.

### 2. 🔍 Search Word
- Case Insensitive: Search for "Code", "code", or "CODE".
- Rich Output: Displays the word type (noun, verb, etc.) and all available definitions numbered clearly.

### 3. 📊 First and Last Words
- Generates an alphabetical report.
- Displays the first and last word found for every letter A Z.
- Handles letters with no entries gracefully.

### 4. 🛡️ Error Handling
- Prevents searching before loading data.
- Validates menu inputs and blocks infinite loops on non numeric input.
- Displays clear error messages for missing files.

---

## 📂 File Structure

```text
cpp-dictionary-system/
├── Assessment1.cpp         # Main application logic
├── dictionary_2026S0.txt   # Dictionary database (Required)
├── README.md               # Project documentation
└── .gitignore              # Git ignore rules
```

---

## 🚀 How to Compile and Run

**Important** The file dictionary_2026S0.txt must be in the same directory as your executable file.

<details><summary><strong>Visual Studio (Recommended)</strong></summary>

Open Visual Studio.

Select Create a new project → Console App (C++).

Name your project and click Create.

In the Solution Explorer, right click Source Files → Add Existing Item → Select Assessment1.cpp.

Copy dictionary_2026S0.txt into the project folder (same location as the .vcxproj file).

Press Ctrl + F5 to build and run.

</details>

<details><summary><strong>G++ CLI / Linux / MacOS</strong></summary>

```bash
# Compile the code
g++ -std=c++11 Assessment1.cpp -o DictionaryApp

# Run the application
# Windows:
DictionaryApp.exe

# Linux or Mac
./DictionaryApp
```
</details>

<details><summary><strong>VS Code</strong></summary>

Open the folder in VS Code.

Make sure the C or C++ Extension is installed.

Open Assessment1.cpp.

Press the Run button and start debugging.

Ensure the terminal working directory contains the text file.

</details>

---

## 📖 Usage Guide

### 1. The Main Menu

Displayed when the program launches

```text
========== MAIN MENU ==========
1. Load new Dictionary
2. Search Word
3. First and Last
4. Exit
===============================
Enter your choice (1-4):
```

### 2. Searching for a Word

Example output when searching for "Code"

```text
Word Found - with 1 definition

Word: code
Type: (noun)
Definition(s):
  1. Instructions for a computer.
```

### 3. First and Last Report

Example output for Option 3

```text
========================================
  FIRST AND LAST WORDS BY LETTER
========================================
Letter    First Word         Last Word
----------------------------------------
  A       aardvark           abstract
  B       beautiful          beneath
  C       cat                cupcake
```

---

## ⚙️ Technical Implementation

### Data Structure

The system uses a custom struct stored in a vector.

```cpp
struct Word {
    string name;
    string type;
    string definition;
};

vector<Word> Dictionary;
```

### Algorithms

Cleaning: A custom cleanString function removes trailing semicolons and whitespace to ensure data integrity.

Sorting and searching: The First and Last feature scans the vector with string comparison to find alphabetical bounds without requiring sorting.

---

## 📝 Input Data Format

The application expects dictionary_2026S0.txt to follow this specific 4 line pattern per entry

```text
word_name;
word_type;
definition;
<BLANK LINE>
```

Example

```text
abandon;
v;
To give up absolutely; to forsake entirely;

aardvark;
n;
A large burrowing mammal of South Africa;
```

---

## 👨‍💻 Author

**Nadeesh Malaka**  
C++ Console Application  
January 2026
