// Programmer: Lokesh Das
// Date: 20/02/2025
// File: wordgame.cpp
// Assignment: HW2
// Purpose: This file contains the main function of the program, which will create a short version of the game Wordle. 

#include <iostream> 
#include <string>
#include <ctype.h>
using namespace std;

int main() {
    while (true) {
        string player1; //Assigns the name of the player to the first player.
        string player2; //Assigns the name of the player to the second player.
        int friendship; //Accepts an integer value within the range of 0 to 100.
        string word; //Assigns the string to be guessed by the player 1. 
        int attempt; //The number of attempts Player 2 will make to obtain the correct answer 
        string guess; // Take the guessed word of Player 2 
        string event; // Assign the letters “Y” for “Yes” and “N” for “No” to the input.
        
        //Store the name of player 1 and player 2 
        cout << "Welcome to the Game of word with Friends - Wordle";
        
        cout <<"\nPlayer 1, Please enter your name: ";
        getline(cin, player1);
        cout << "Welcome " << player1 << "!" << endl;
      
        cout << "\nNow Player 2, Please enter your name: ";
        getline(cin, player2);
        cout << "Welcome " << player2 << "!" << endl;
        cout << "\nGet Ready, it will be Fun " << player1 << " and " << player2  <<" !!" << endl;
        
        // Take the friendship level
        cout << "\nTo begin, let’s establish the level of your friendship.[on the scale of 0-100] ";
        cin >> friendship;
        cin.ignore(); //clear the input buffer
         
        //verify if it falls into the range or not  
        while (friendship < 0 || friendship > 100) {
            cout << "\nYour Value is outside of the range. Please enter the value within the scale of 0 to 100: ";
            cin >> friendship;
            cin.ignore();
           }
        
        if (friendship > 50) {
            cout << "\nYou rate your friendship level: " << friendship << ", You must be a good friend" << endl;
        } else {
            cout << "\nYou rate your friendship level: " << friendship << ", You will be a good friend after this Game" << endl;
        }
        
        cout << "\nLet's start, WORDLE!!\n" << endl;
        
        
        //Ask the 5-letter UPPERCASE word from player 1
        cout << player1 << ", I need a word of 5 letters (for eg. CYCLE): ";
        cin >> word;
        
        while (true) {
            if (word.length() != 5) {
                cout << player1 << ", this is not allowed. I only accept a word with 5 letters. Please put a valid word ";
                cin >> word;
            }
            
            for (char c : word) {
                if (!isalpha(c)){
                    cout << "come on " << player1 << ", You cannot trick me." << endl;
                    cout << "Now, come up with a 5 letter Dictionary word ";
                    cin >> word;
                }
            }
            break;
        }
        
        cout << "\nWonderful " << player1 << ", Nice pick. Now, I will secure this with me." << endl;
        cout << "Hey " << player2 << ", now that it's your turn to guess the correct word that your friend " << player1 << " recently told me." << endl;
        cout << "You will get 6 attempts to make the guess" << endl;
        cout << "Don't worry! Don’t sweat it! I’ll be your guide, showing you if the letters are in the word and where they are.\n" << endl;
        cout << "So, " << player2 << " what do you think the word is? " << endl;
        
        attempt = 0;
        while (attempt < 6) {
            cout << "Attempt: " << attempt++ << endl;
            cout << "Please enter a five letter word you think that " << player1 << " has given me ";
            cin  >> guess; 
            
            while (true) {
                if (guess.length() != 5) {
                    cout << player2 << ", this is not allowed. I only accept a word with 5 letters. Please put a valid word ";
                    cin >> guess;
                }
            
                for (char c : word) {
                    if (!isalpha(c)){
                        cout << "I cannot take this. I need a word with 5 alphabets all in uppercase. Please follow the rules of game";
                        cout << "Now come up with a 5 letter Dictionary word ";
                        cin >> guess;
                    }
                }
                break;
            }
            
            if (guess == word) {
                cout << "Oh WOW!!! You just got that in the "<< attempt <<  " attempt. CONGRATULATIONS!!";
                break;
            } else {
                cout << "Hint:\n";
                for (int index = 0; index  < static_cast<int>(guess.length()); index++) {
                    if (guess.at(index) == word.at(index)) {
                        cout << guess.at(index) << " : ^o^" << endl;  
                    } else if (word.find(guess.at(index)) != string::npos) {
                        cout << guess.at(index) << " : ^( '-' )^" << endl; 
                    } else {
                        cout << guess.at(index) << " : @.@" << endl; 
                    }
                }
            }
            
        if (attempt == 6) {
            cout << "\nOpps, " << player2 << ", You are out of attempt. Better Luck Next time"<< endl;
        }
        }
        
        //friendship level update
        friendship += attempt;
        if (friendship == 100) {
            cout << "friendship level: " << friendship << ". OMG!! Your Friendship level is at max. Cannot be more than this. CONGRATULATIONS!!" << endl;
        } else if (friendship == 0) {
            cout << "friendship level: " << friendship << ". Zero is still above negative. You should try to be more friendly" << endl;
            cout << "All the best" << endl;
        } else {
            cout << "\nfriendship level: " << friendship << ". Great!" << endl;
        }
        cout << "\nReal friendship means never having to pretend";
        
        cout << "\nDo you want to play again(Y/N)? " << player1 << " ";
        cin >> event;
        cout << "\nEvery attempt may not be right, but a true friend stays until you get it right.";
                
        if (event == "N"){
            cout << "\nDo you really don't want to play again(Y/N)? " << player1 << " ";
            cin >> event;
            if (event == "N"){
                cout << "Goodbye!! " << player1 << " and " << player2 << ". See you Again!" << endl;
                break;
            }
        }
        
    }    
    return 0;

}
