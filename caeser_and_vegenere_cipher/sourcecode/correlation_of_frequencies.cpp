/*
*   Title: correlation_of_frequencies.cpp
*   Author: Noah Gregory
*   Date: 02/06/2024
*   Purpose: Compute the correlation of frequencies for a caeser cipher
*            -It will use a command line arguments, spaces are allowed in ciphertext.
*            -It will assume only english letters are used in the ciphertext.
*            -It will read in the cipher text of a ceaser cipher, and calculate the frequencies of each letter.
*            -It will match the frequencies of the cipher text letters to the frequencies of standard english letters.
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

    const float standard_frequencies[26] = {0.080, 0.015, 0.030, 0.040, 0.130, 0.020, 0.015, 0.060, 0.065, 0.005, 0.005, 0.035, 0.030, 0.070, 
                                            0.080, 0.020, 0.002, 0.065, 0.060, 0.090, 0.030, 0.010, 0.015, 0.005, 0.020, 0.002};
    const char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        // Standard frequencies show the frequencies of each letter in the english alphabet as they generally appear in normal writing.
        // the frequency indecies correspond with the alphabet indecies


    float ciphertext_frequencies[26]; // array of floats for the frequency of each letter in the cipher text
    float correlation_of_frequencies[27]; // array to store the correlation of frequencies for each possible key
    string ciphertext; // this is the ciphertext that will be read in from the user
    int ciphertext_length; // declares integer variable for the length of the ciphertext
    int greatest_five[5] = {26, 26, 26, 26, 26}; // array used to store the five values of i that yeild the greatest COF values 
    float cor_of_freq_sum, cor_of_freq_temp; // values used to calculate and store the correlation of frequencies
    float count; // number of times a given letter appears in a sttring

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


    /*
    *   This nested for loop will: for every letter in the alphabet, count how many times 
    *   it occurs in the ciphertext and calculate it frequency by dividing it by the total
    *   length of the ciphertext, and store that value into ciphertext_frequencies
    */
    for(int i = 0; i < 26; i++)
    {
        count = 0;

        for(int j = 0; j < ciphertext_length; j++)
        {
            if(alphabet[i] == tolower(ciphertext[j])) count++;
        }

        ciphertext_frequencies[i] = static_cast<float>(count) / static_cast<float>(ciphertext_length); // static_cast<float> makes sure that the quotient is also a float
    }

    correlation_of_frequencies[26] = 0.0; // a zero variable to initialize greatest_five with so that it fixes the same key showing up multiple times

    /*
    *   This nested loop performs the calculation for correlation of frequencies (COF).
    *   for every possible key, i, it calculates the COF by multiplying the frequency of each letter in the
    *   ciphertext by the frequency of its assumed plaintext frequency, and adding them all together. 
    *   This is done for each possible key and stored in an array.
    */

    for(int i = 0; i < 26; i++)
    {
        cor_of_freq_sum = 0;

        for(int j = 0; j < 26; j++)
        {
            cor_of_freq_temp = ciphertext_frequencies[j] * standard_frequencies[(26 + j - i) % 26];
            cor_of_freq_sum += cor_of_freq_temp;
        }

        correlation_of_frequencies[i] = cor_of_freq_sum;
    }

    cout << "KEY | COF" << endl; // This line and for loop below print out each letter and their COF
    for(int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << "   | " << correlation_of_frequencies[i] << endl; 
    }

    for(int i = 0; i < 26; i++) // fills greatest_five with the letters/ keys that are the top 5 COF
    {
        if(correlation_of_frequencies[i] > correlation_of_frequencies[greatest_five[0]])
        {
            greatest_five[4] = greatest_five[3];
            greatest_five[3] = greatest_five[2];
            greatest_five[2] = greatest_five[1];
            greatest_five[1] = greatest_five[0];
            greatest_five[0] = i;
        }
        else if(correlation_of_frequencies[i] > correlation_of_frequencies[greatest_five[1]])
        {
            greatest_five[4] = greatest_five[3];
            greatest_five[3] = greatest_five[2];
            greatest_five[2] = greatest_five[1];
            greatest_five[1] = i;
        }
        else if(correlation_of_frequencies[i] > correlation_of_frequencies[greatest_five[2]])
        {
            greatest_five[4] = greatest_five[3];
            greatest_five[3] = greatest_five[2];
            greatest_five[2] = i;
        }
        else if(correlation_of_frequencies[i] > correlation_of_frequencies[greatest_five[3]])
        {
            greatest_five[4] = greatest_five[3];
            greatest_five[3] = i;
        }
        else if(correlation_of_frequencies[i] > correlation_of_frequencies[greatest_five[4]])
        {
            greatest_five[4] = i;
        }
    }

    cout << endl << endl << "The top 5 keys that most likely corresponds to this cipher in descending order:" << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << greatest_five[i] << " (" << alphabet[greatest_five[i]] << ")" << endl;
    }

    return 0;
}