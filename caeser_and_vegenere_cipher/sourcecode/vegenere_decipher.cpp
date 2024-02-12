/*
*   Title: vegenere_decipher.cpp
*   Author: Noah Gregory
*   Date: 02/07/2024
*   Purpose: To decipher a vegenere cipher:
*                   -First argument: Key phrase
*                   -Second argument/s: ciphertext
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
    if(argc < 3) //  makes sure that there are at least 2 arguments: key phrase and ciphertext
    {
        cerr << "Please enter in a keyphrase, and ciphertext." << endl;
        return 1; 
    }
    for(int i = 0; i < strlen(argv[1]); i++) // checks to see that the key argument is only english letters
    {
        if(!isalpha(argv[1][i]))
        {
            cerr << "Please use only English letters for the key." << endl;
            return 1;
        }
    }
    for(int i = 0; i < argc - 2; i++)
    {
        for(int j = 0; j < strlen(argv[i + 2]); j++)
        {
            if(!isalpha(argv[i + 2][j]))
            {
                cerr << "Please only use Enlgish letters in the cypher text" << endl;
                return 1;
            }
        }
    }

    const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string ciphertext, plaintext = "", plaintext_char, keyphrase = argv[1]; // variables to store ciphertext, keyphrase, and plaintext
    int ciphertext_length, cipher_index, keyphrase_length = keyphrase.length();
    int keyphrase_values[keyphrase_length];

    for(int i = 0; i < keyphrase_length; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(tolower(keyphrase[i]) == alphabet[j])
            {
                keyphrase_values[i] = j;
                break;
            }
        }
    }

    for(int i = 0; i < argc - 2; i++) // allows for spaces to be put in the ciphertext when it is entered through the command line
    {
        ciphertext = ciphertext.append(argv[i + 2]);
    }

    ciphertext_length = ciphertext.length(); // gets the length of the ciphertext

    for(int i = 0; i < ciphertext_length; i++) // for loop decodes the ciphertext into plain text
    {
            cipher_index = 0;
            while(cipher_index < 26)
            {
                if(alphabet[cipher_index] == tolower(ciphertext[i]))
                {
                    break;
                }
                cipher_index++;
            }
            plaintext_char = toupper(alphabet[(cipher_index + 26 - keyphrase_values[i % keyphrase_length]) % 26]); // gets the plaintext character
            plaintext += plaintext_char;
    }
    
    cout << "The plaintext is: " << plaintext << endl;

    return 0;
}