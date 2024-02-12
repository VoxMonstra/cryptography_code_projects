/*
*   Title: caeser_decipher.cpp
*   Author: Noah Gregory
*   Date: 02/07/2024
*   Purpose: To take in a key (character) and a caesr ciphertext, and return the plaintext yeilded by the key
            -The arguments for the program should be: 1st, a single character that will act as a key and 2nd, any number of cipher text words
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char plaintext_char;
    string plaintext;
    int key, cipher_index;
    

    // error checking for correct arguments entered
    if(argc < 2)
    {
        cerr << "No arguments entered" << endl;
        return 1;
    }
    if(strlen(argv[1]) > 1)
    {
        cerr << "Please use a single alphabet character key for the first argument" << endl;
        return 1;
    }
    if(!isalpha(argv[1][0]))
    {
        cerr << "Please use a letter for the key" << endl;
        return 1;
    }
    if(argc == 2)
    {
        cerr << "Please enter in the ciphertext" << endl;
        return 1;
    }
    for(int i = 0; i < argc - 2; i++) // This nested for loop checks every letter in the cipher text to see if there are any numbers or special characters.
    {
        for(int j = 0; j < strlen(argv[i + 2]); j++)
        {
            if(!isalpha(argv[i + 2][j]))
            {
                cerr << "Please only use English letters in the cipher text arguments." << endl;
                return 1;
            }
        }
    }

    /*
    *   Finds the numerical value of the key from the first argument
    */
    int k = 0;
    while(k < 26)
    {
        if(alphabet[k] == tolower(argv[1][0]))
        {
            break;
        }
        k++;
    }
    key = k;

    /*
    *   These nested for/while loops decipher each word and prints it to the screen.
    */
    cout << "The plaintext is: ";
    for(int i = 0; i < argc - 2; i++)
    {
        plaintext = "";
        for(int j = 0; j < strlen(argv[i + 2]); j++)
        {
            cipher_index = 0;
            while(cipher_index < 26)
            {
                if(alphabet[cipher_index] == tolower(argv[i + 2][j]))
                {
                    break;
                }
                cipher_index++;
            }
            plaintext_char = toupper(alphabet[(cipher_index + 26 - key) % 26]);
            plaintext += plaintext_char;
        }
        cout << plaintext << " ";
    }

    return 0;
}