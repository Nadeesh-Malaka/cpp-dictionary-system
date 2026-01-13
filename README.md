# 📚 Dictionary Management System (C++)

![Language](https://img.shields.io/badge/Language-C++11-blue?style=for-the-badge&logo=c%2B%2B)
![Status](https://img.shields.io/badge/Status-Complete-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A robust, console-based Dictionary Management System that parses, searches, and organizes dictionary data efficiently using the Standard Template Library (STL).

---

## 📑 Table of Contents
- [✨ Key Features](#-key-features)
- [📂 File Structure](#-file-structure)
- [🚀 How to Compile & Run](#-how-to-compile--run)
- [📖 Usage Guide](#-usage-guide)
- [⚙️ Technical Implementation](#-technical-implementation)
- [📝 Input Data Format](#-input-data-format)
- [👨‍💻 Author](#-author)

---

## ✨ Key Features

### 1. 📥 Load Dictionary
- Parses raw text data from `dictionary_2026S0.txt`.
- **Robust Parsing:** Automatically cleans invisible characters (like Windows `\r`) and handles messy formatting.
- Displays the total count of loaded words.

### 2. 🔍 Search Word
- **Case-Insensitive:** Search for "Code", "code", or "CODE".
- **Rich Output:** Displays the word type (noun, verb, etc.) and all available definitions numbered clearly.

### 3. 📊 First and Last Words
- Generates an alphabetical report.
- Displays the **first** and **last** word found for every letter (A-Z).
- Handles letters with no entries gracefully.

### 4. 🛡️ Error Handling
- Prevents searching before loading data.
- Validates menu inputs (prevents infinite loops on non-numeric input).
- Displays clear error messages for missing files.

---

## 📂 File Structure

```text
cpp-dictionary-system/
├── Assessment1.cpp         # 🧠 Main application logic
├── dictionary_2026S0.txt   # 📖 Dictionary database (Required)
├── README.md               # 📄 Project documentation
└── .gitignore
```


## 👨‍💻 Author
- Nadeesh Malaka
- Language: C++
- Project Type: Console Application
- Date: January 2026
