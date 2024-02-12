These c++ programs use command line arguments. If the program uses cipher text as command line arguments, spaces are optional. 

-correlation_of_frequencies.cpp - 
		- Only ciphertext required for cmd arguments (spaces optional).
		- Basic function is to match cipher text frequencies with standard english character frequencies.
		- Outputs the top 5 keys with the highest correlation.

-caeser_decipher.cpp - 
		- first argument is the key to the cipher. It should be one letter.
		- The second argument is the ciphertext (spaces optional).
		- Decrypts ciphertext and outputs the plaintext of the caeser cipher.

-index_of_coincidence.cpp -
		-Only ciphertext is required for cmd arguments (spaces optional).
		-The index of coincidence provides a measure of how likely it is to draw two matching letters by randomly selecting two letters from a given text.
		-Outputs the index of coincidence of the given ciphertext.

-cipher_splitter.cpp - 
		-First argument is the number of buckets needed.
		-Second argument is ciphertext (spaces optional).
		-Simply splits the cipher text into X amount of buckets.
		-Outputs each bucket/ alphabet.

vegenere_decipher.cpp -
		-First argument is the keyphrase.
		-Second argument is the ciphertext (spaces optional).
		-Decrypts ciphertext and outputs the plaintext of the vegenere cipher.
