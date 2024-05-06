#include "Guesser.h"
#include <string>

using std::string;
// Can make new private objects, Do not change the provided functions or make new public fuctions

/*
   Returns an whole number representing the distance between the guess,
   provided as an argument, and the secret. The distance represents the number
   of characters that would have to be changed at the same location to match
   the other string. When the two strings are identical, the distance is 0,
   but for each letter different, the distance increases by 1. When the
   strings are different lengths, each of the extra characters in the longer
   string also counts as an increase in 1 to the distance, up to the length of
   the secret; in other words, if m_secret has a 10 characters and the guess
   has 100, the distance is 10.
   */
// Helper function that tells the distace in how far (characters) the guess is
unsigned int Guesser::distance(string guess){
	unsigned int m_distance = 0;
	unsigned int size = std::min(guess.size(), m_secret.size());
	unsigned int size_diff = abs(guess.size() - m_secret.size());
	for(unsigned int i=0; i<size; i++) {
		if(guess[i] != m_secret[i]) {
			m_distance++;
		}
	}
	return m_distance + size_diff;
}

/*
   Constructor requires that the secret phrase is provided its value as
   an argument. This secret will not change for the lifespan of an instance
   of any Guesser object and must have a length of 32 characters or less,
   otherwise, it will be truncated at that length.
   */
// First 32 Characters
Guesser::Guesser(string secret){
	m_remaining = 3;
	if(secret.size() > 32) {
		m_secret = secret.substr(0, 31); // Truncate the output of the string
	} else {
		m_secret = secret;
	}
}

/*
   Determines and returns whether the provided guess matches the secret
   phrase. However, the function also returns false if the secret is locked,
   which happens if either (or both): 
   (A) there are no remaining guesses allowed
   (B) the function detects brute force, as indicated by a guess that has a
   distance greater than 2 from the secret
   See the remaining() and distance() functions for specifications regarding
   determining how many guesses are remaining and the distance between a guess
   and the secret.
   */
// Will output fail if locked out
// Locked out if too many wrong guesses, to wild of a test
bool Guesser::match(string guess){
	//Return False if there are no more guesses
	if(m_remaining <= 0) {
		return false;
	}
	//Return False if the a brute force is detected
	if(distance(guess) > 2) {
		m_remaining--;
		return false;
	}
	//Return True if guess=m_secret
	if(distance(guess) == 0) {
		m_remaining = 3;
		return true;
	}
	return true;
}

/*
   Returns the number of guesses remaining. A Guesser object allows up to
   three (3) consecutive guesses without a match. If three guesses are made
   without any being a true match, the secret is locked. However, whenever
   an unlocked secret is guessed with a true match, the guesses remaining
   reset to three (3).
   */
// Is reset if the guess is correct
unsigned int Guesser::remaining(){
	return m_remaining;
}

