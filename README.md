# Phrase Search in Text File using Binary Search Tree

This repository contains a C program that performs a phrase search within a text file using a binary search tree (BST) data structure.

## Description
The program reads a text file (`fichier.txt`) containing phrases and constructs a binary search tree where each node represents a unique word found in the phrases along with the positions of the phrases where the word occurs.

The program provides functionalities for:
- Building the BST from the phrases in the text file.
- Searching for a phrase index given a set of words.
- Displaying the constructed BST.

## Instructions
1. Ensure you have a C compiler installed on your system.
2. Clone this repository to your local machine.
3. Compile the C program using the provided source code.
    ```bash
    gcc main.c -o phrase_search
    ```
4. Run the compiled program.
    ```bash
    ./phrase_search
    ```
5. Follow the prompts to input phrases and perform searches.

## Files
- `main.c`: Contains the main source code of the program.
- `fichier.txt`: Text file containing the input phrases.
- `README.md`: This README file providing an overview of the program.

## Usage
- Upon running the program, you will be prompted to enter a phrase for searching.
- Enter the phrase in the prompt and press Enter.
- The program will then display the positions of the given phrase within the text file.

## Additional Notes
- Ensure the text file `fichier.txt` is present in the same directory as the executable for proper file reading.
- The program utilizes a binary search tree data structure for efficient searching of phrases.
- Feel free to modify the code or input phrases to test different scenarios.

If you have any questions or encounter any issues, please feel free to reach out.

Happy coding!
