/*
*   Title:cipher_splitter.cpp
*   Author:Noah Gregory
*   Date:02/078/2024
*   Purpose:To split a given cipher into a specified number of buckets
*           -Arguments should be an integer for the number of buckets, and ciphertext. Ciphertext may include spaces.
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
    if(argc < 3) // if statement makes sure there is at least two arguments
    {
        cerr << "Please enter the number of buckets, and then the ciphertext" << endl;
        return 1;
    }

    int k = 0;
    while(k < strlen(argv[1])) // while loop makes sure the first argument is a number
    {
        if(isalpha(argv[1][k]))
        {
            cerr << "Please enter in a number for the first argument.";
            return 1;
        }
        k++;
    }

    for(int i = 0; i < argc - 2; i++) // makes sure the ciphertext arguments dont have any numbers/ special characters
    {
        for(int j = 0; j < strlen(argv[i + 2]); j++)
        {
            if(!isalpha(argv[i + 2][j]))
            {
                cerr << "Please only use English letters for the ciphertext arguments" << endl;
                return 1;
            }
        }
    }

    int num_buckets = stoi(argv[1]);
    string bucket_array[num_buckets];
    string ciphertext; // will store the whole ciphertext without spaces
    string temp; // temporary string for splitting characters

    for(int i = 0; i < argc - 2; i++) // allows for spaces to be put in the ciphertext when it is entered through the command line
    {
        ciphertext = ciphertext.append(argv[i + 2]);
    }

    for(int i = 0; i < ciphertext.length(); i++) // loads every character in the ciphertext into its respective bucket.
    {
        temp = ciphertext.at(i);
        bucket_array[i % num_buckets].append(temp);
    }
    
    for(int i = 0; i < num_buckets; i++) // prints out each alphabet bucket.
    {
        cout << endl << "Alphabet #" << i + 1 << ": " << bucket_array[i];
    }

    return 0;
}