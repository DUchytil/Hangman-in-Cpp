#include <iostream> //Allows us to gather input and display output for the user
#include <string>
#include <list>
#include "PlayerStats.h" //Header file for class

//Function to gather input from the user
//Parameters: None
//Return: String
std::string getInput() {

    //Defining word variable
    std::string userInput;

    //Asking user for input
    std::cout << "Please enter a word to guess: ";

    //Gathering word from user
    std::getline(std::cin, userInput);

    //Printing word entered by user (debugging)
//    std::cout << "You entered " << userInput << std::endl;

    return userInput;
}

//Function to gather input from the user and return a single character
//Parameters: None
//Return: char
char getGuess(){

    //Initializing variable to store user guess as string temporarily
    std::string guess;

    //User entry prompt
    std::cout << std::endl;
    std::cout << "Please enter a guess: ";

    //Gathering user input
    std::getline(std::cin, guess);

    //Returning only first character of user entry as char
    return guess[0];

}

//Function to assess if player has guessed all char values
//Parameters: None
//Return: bool
bool isOver(std::list<char> placeholderList){
    bool isDone = true;


    /*FOLLOWING 5 LINES OF CODE PROVIDED BY ChatGPT*/

    // Iterate through the list and compare each character
    for (const auto& currentChar : placeholderList) {
        if (currentChar == '_') {
            isDone = false;
        }
    }

    //Returning status
    return isDone;

}


/*THIS FUNCTION WAS PROVIDED BY ChatGPT*/
void displayHangman(int stage) {
    if (stage < 0 || stage > 7) {
        std::cerr << "Invalid stage for hangman display." << std::endl;
        return;
    }

    // Array of hangman stages
    const char* hangmanStages[] = {
            R"(
            +---+
                |
                |
                |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
                |
                |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
                |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
            |   |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
           /|   |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
           /|\  |
                |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
           /|\  |
           /    |
                |
        ==========
        )",
            R"(
            +---+
            |   |
            O   |
           /|\  |
           / \  |
                |
        ==========
        )"
    };

    // Display the specified stage
    std::cout << hangmanStages[stage] << std::endl;
}

//Function to display to the user that they successfully guessed all characters
//Parameters: None
//Return: None
void displayWinningMessage(){

    std::cout  << std::endl;
    std::cout << "Nice job! You guessed all the letters!" << std::endl;
}


//Function to hide word that was just entered by the user so the person playing can't see it
//Parameters: None
//Return: None
void hideWord(){
    for (int i = 0; i < 300; ++i){
        std::cout << std::endl;
    }
}


//Function to display to the user that they ran out of guesses
//Parameters: None
//Return: None
void displayLosingMessage(){

    std::cout  << std::endl;
    std::cout << "Sorry, you're out of guesses! Better luck next time!" << std::endl;
}


int main() {

    bool isPlaying = true;
    char guess;
    int iteratorIndex = 0;
    bool correct = true;
    int gameStage = 0;
    int countIndex = 0;
    int numOfGuesses = 0;

    //Instantiating object to keep track of player stats
    PlayerStats player;  // Creating an object of MyClass

    //Gathering player name
    std::cout << "Please enter your name: ";
    std::getline(std::cin, player.playerName);
    std::cout << std::endl;


    //List to store individual characters of our word to be guessed
    std::list<char> guessWordCharList;
    
    //List to store _ characters for every character contained in the word to be guessed
    std::list<char> placeholderList;

    //Defining variable for storing the word
    std::string stringToGuess = getInput();
    hideWord();

    for (int i = 0; i < stringToGuess.length(); ++i){

        //Appending individual characters to the list
        guessWordCharList.push_back(stringToGuess[i]);

        //Appending "_" characters to the placeholder list
        placeholderList.push_back('_');
    }

    /*************************************DEBUGGING***************************************/

//    // Display characters using an iterator
//    std::cout << "Elements in the list: ";
//    for (auto it = guessWordCharList.begin(); it != guessWordCharList.end(); ++it) {
//        std::cout << *it << " ";
//    }
//
//    // Displaying placeholder list using an iterator
//    std::cout << "Elements in the list: ";
//    for (auto it = placeholderList.begin(); it != placeholderList.end(); ++it) {
//        std::cout << *it << " ";
//    }


    /*************************************DEBUGGING***************************************/


    // Displaying placeholder list using an iterator
    std::cout << std::endl;
    std::cout << "Word: ";
    for (auto it = placeholderList.begin(); it != placeholderList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;



    while (isPlaying){

        std::cout << std::endl;
        guess = getGuess();
        ++numOfGuesses; //Incrementing guess count

        // Iterate through the list and compare each character with guess entered by user
        for (const auto& currentChar : guessWordCharList) {
            if (currentChar == guess) {

                if (countIndex == 0){
                    std::cout << std::endl;
                    std::cout << "Letter found! " << guess << " is in the word." << std::endl;
                    correct = true;
                    ++countIndex;
                }

                //Inserting matching char into placeholder list at appropriate index
                // Inserting character at respective location
                auto it = std::next(placeholderList.begin(), iteratorIndex);  // Iterator pointing to the position to replace
                placeholderList.insert(it, currentChar);  // Insert the new value

                //Removing previous character
                auto it2 = std::next(placeholderList.begin(), iteratorIndex + 1);  // Iterator pointing to the position to replace
                placeholderList.erase(it);  // Remove the old value

            }

            //Incrementing iterator index value
            ++iteratorIndex;

        }


        //Displaying a character not found message
        if (countIndex == 0){
            std::cout << "Sorry, there's no " << guess << " in the word." << std::endl;
            correct = false;
        }


        //Checking to see if the user has guess all char values
        if (isOver(placeholderList)){
            isPlaying = false;
        }
        else {
            isPlaying = true;
        }

        iteratorIndex = 0;
        countIndex = 0;


        // Displaying placeholder list using an iterator
        std::cout << std::endl;
        std::cout << "Word: ";
        for (auto it = placeholderList.begin(); it != placeholderList.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        //Incrementing game stage if guess was not correct
        if (not correct){
            ++gameStage;

            //Displaying current hangman status
            displayHangman(gameStage);
        }



        if (gameStage >= 7){

            //Displaying losing messaqe to player
            displayLosingMessage();
            player.didWin = false;
            break;
        }

    }

    if (isPlaying == false){

        //Displaying to the user that they won!
        displayWinningMessage();
        player.didWin = true;
    }


    //Recording performance of the player inside player obejct
    player.playerScore = numOfGuesses;
    player.playerWord = stringToGuess;
    player.wordCharacterCount = stringToGuess.length();


    std::cout << std::endl;
    std::cout << std::endl;


    //Printing player stats
    std::cout << "Name of player: " << player.playerName << std::endl;
    std::cout << "Game status: ";

    if (player.didWin)
        std::cout << "You won! ";

    else
        std::cout << "You lost. ";

    std::cout << std::endl;
    std::cout << "Number of guesses: " << player.playerScore << std::endl;
    std::cout << "Word character count: " << player.wordCharacterCount << std::endl;
    std::cout << "The word was: " << player.playerWord;

    std::cout << std::endl;
    std::cout << std::endl;
    std:: cout << "Thanks for playing!";

    return 0;
}




