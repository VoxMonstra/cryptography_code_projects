/*
*   Title: index_of_coincidence.cpp
*   Author: Noah Gregory
*   Date: 02/07/2024
*   Purpose: To calculate the index of coincidence (IC) of a given vigenere ciphertext
*           -Should only take in ciphertext arguments
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{        
    const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string ciphertext; // This is the ciphertext that will be read in from the user.
    int ciphertext_length; // Declares integer variable for the length of the ciphertext.
    float sum = 0; // For calculating the summation of the IC formula.
    float IC, count; // Variable for index of coincidence and variable for counting occurances.
    float ciphertext_occurances[26]; // Stores the total amount of occurances for each letter in ciphertext.

    if(argc < 2) // ensures ciphertext is enetered in command line
    {
        cerr << "No arguments entered" << endl;
        return 1;
    }
    for(int i = 0; i < argc - 1; i++) // This nested for loop checks every letter in the cipher text to see if there are any numbers or special characters.
    {
        for(int j = 0; j < strlen(argv[i + 1]); j++)
        {
            if(!isalpha(argv[i + 1][j]))
            {
                cerr << "Please only use English letters in the cipher text arguments." << endl;
                return 1;
            }
        }
    }
    for(int i = 0; i < argc - 1; i++) // allows for spaces to be put in the ciphertext when it is entered through the command line
    {
        ciphertext = ciphertext.append(argv[i + 1]);
    }

    ciphertext_length = ciphertext.length(); // gets the legnth of the ciphertext

    for(int i = 0; i < 26; i++) // This nested for loop counts every letter in the ciphertext and stores it in cipher_occurances.
    {
        count = 0;
        for(int j = 0; j < ciphertext_length; j++)
        {
            if(alphabet[i] == tolower(ciphertext[j])) count++; 
        }
        ciphertext_occurances[i] = count;
    }

    for(int i = 0; i < 26; i++) // summation of each letter's n(n - 1) value
    {
        sum += ciphertext_occurances[i] * (ciphertext_occurances[i] - 1);
    }

    IC = sum / (ciphertext_length * (ciphertext_length - 1));

    cout << "The Index of Coincidence for the ciphertext is " << IC << endl;

    return 0;
}