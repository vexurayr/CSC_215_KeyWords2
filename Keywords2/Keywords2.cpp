// Keywords 2, a spin-off of the game Hangman, harder than Keywords 1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Functions
void introduction();
string logIn();

int main()
{
    srand(time(0));
    chrono::duration<int, milli> timespan(2500);
    const int MAX_WRONG = 8;    // Max incorrect guesses
    int answeredWrong = 0;    // Current number of incorrect guesses
    char guess;
    bool repeatGame = false;
    char yesOrNo;
    bool loopQuitOrPlayAgain;

    // Display Title of the program to the user
    introduction();

    // Ask the recruit to log in using their name
    string username = logIn();    // Hold the recruit's name in a var, and address them by it throughout the simulation.

    // Display an overview of what Keywords II is to the recruit 
    cout << "This simulation is meant to test those that have made it past the first stage of training.\n";
    this_thread::sleep_for(timespan);
    cout << "It's only going to get more challenging from here.\n";
    this_thread::sleep_for(timespan);
    cout << "This advanced drill will help you detect real enemy's scrambled keywords.\n";
    this_thread::sleep_for(timespan);
    cout << "You won't have the benefit of seeing the scrambled letters or recieving any hints.\n\n";
    this_thread::sleep_for(timespan);

    // Display directions to the recruit on how to use Keywords
    cout << "So, " << username << ", you will guess letters of the word until you know the whole word.\n";
    this_thread::sleep_for(timespan);
    cout << "Each run of the simulation will select three words which you must guess all correctly to pass.\n";
    this_thread::sleep_for(timespan);
    cout << "Failure to guess any word in eight guesses means you will have to start over.\n";
    this_thread::sleep_for(timespan);
    cout << "The simulation will give you the status of your guess and which letters you have already guessed.\n\n";
    this_thread::sleep_for(timespan);

    // Create a collection of 10 words you had written down manually
    vector<string>keyWords;
    keyWords.push_back("INFLUENCE");
    keyWords.push_back("DICTATOR");
    keyWords.push_back("UNDERCOVER");
    keyWords.push_back("REDACTED");
    keyWords.push_back("SILENT");
    keyWords.push_back("BATTLEFIELD");
    keyWords.push_back("SPOTTED");
    keyWords.push_back("CAUTIOUS");
    keyWords.push_back("DARKNESS");
    keyWords.push_back("SHELTER");

    // Create an int var to count the number of simulations being run starting at 1
    int simulationsRun = 1;

    do
    {
        // Display the simulation # is starting to the recruit. 
        cout << "Number of times simulation has been run: " << simulationsRun << "\n\n";
        this_thread::sleep_for(timespan);
        answeredWrong = 0;
        
        // Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
        random_shuffle(keyWords.begin(), keyWords.end());
        const string WORD1 = keyWords[0];    // First word to guess
        const string WORD2 = keyWords[1];    // Second word to guess
        const string WORD3 = keyWords[2];    // Third word to guess

        string soFar1(WORD1.size(), '-');    // Starts with a dash for every letter in the first word
        string soFar2(WORD2.size(), '-');    // And will display the word guessed so far
        string soFar3(WORD3.size(), '-');
        string usedLetters = "";    // Letters that have already been guessed

        // Main loop, first word
        cout << "Time to guess the first word, " << username << ".\n\n";
        this_thread::sleep_for(timespan);

        // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
        while ((answeredWrong < MAX_WRONG) && (soFar1 != WORD1))
        {
            //     Tell recruit how many incorrect guesses he or she has left
            cout << "You have " << (MAX_WRONG - answeredWrong) << " incorrect guesses left.\n\n";
            this_thread::sleep_for(timespan);

            //     Show recruit the letters he or she has guessed
            cout << "You have guessed the following letters:\n" << usedLetters << "\n\n";
            this_thread::sleep_for(timespan);

            //     Show player how much of the secret word he or she has guessed
            cout << "The word is:\n" << soFar1 << "\n\n";
            this_thread::sleep_for(timespan);

            //     Get recruit's next guess
            cout << "Enter your guess: ";
            cin >> guess;
            cout << "\n";
            guess = toupper(guess);    // Makes the guessed letter uppercase

            //     While recruit has entered a letter that he or she has already guessed
            while (usedLetters.find(guess) != string::npos)
            {
                cout << "You've already guessed " << guess << ".\n\n";
                cout << "Enter your guess: ";
                cin >> guess;
                cout << "\n";
                guess = toupper(guess);
            }

            //     Add the new guess to the group of used letters
            usedLetters += guess;

            //     If the guess is in the secret word
            if (WORD1.find(guess) != string::npos)
            {
                //          Tell the recruit the guess is correct
                cout << "Good guess. " << guess << " is in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                //          Update the word guessed so far with the new letter
                for (int i = 0; i < WORD1.length(); ++i)
                {
                    if (WORD1[i] == guess)
                    {
                        soFar1[i] = guess;
                    }
                }
            }
            //     Otherwise
            else
            {
                //          Tell the recruit the guess is incorrect
                cout << "Unfortunately, " << guess << " was not in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                //          Increment the number of incorrect guesses the recruit has made
                ++answeredWrong;
            }

            // If the recruit has made too many incorrect guesses
            if (answeredWrong == MAX_WRONG)
            {
                //     Tell the recruit that he or she has failed the Keywords II course.
                cout << "I'm afraid you've guessed too many wrong, " << username << ".\n";
                this_thread::sleep_for(timespan);
                cout << "Lucky for you, this failure is not a major setback.\n";
                this_thread::sleep_for(timespan);
                cout << "But you'll have to restart from the beginning if you want to pass.\n\n";
                this_thread::sleep_for(timespan);
                goto onFailure;
            }
            // Otherwise
            else if (soFar1 == WORD1)
            {
                //     Congratulate the recruit on guessing the secret word
                cout << "Congratulations, " << username << ", you have successfully guessed the first word.\n\n";
                this_thread::sleep_for(timespan);
                cout << "But the test isn't over. You have two words left to go.\n\n";
                this_thread::sleep_for(timespan);
            }
        }
        cout << "The word was " << WORD1 << ".\n\n";
        this_thread::sleep_for(timespan);

        // Second word
        cout << "Time to guess the second word, " << username << ".\n\n";
        this_thread::sleep_for(timespan);
        answeredWrong = 0;
        usedLetters = "";
        while ((answeredWrong < MAX_WRONG) && (soFar2 != WORD2))
        {
            cout << "You have " << (MAX_WRONG - answeredWrong) << " incorrect guesses left.\n\n";
            this_thread::sleep_for(timespan);

            cout << "You have guessed the following letters:\n" << usedLetters << "\n\n";
            this_thread::sleep_for(timespan);

            cout << "The word is:\n" << soFar2 << "\n\n";
            this_thread::sleep_for(timespan);

            cout << "Enter your guess: ";
            cin >> guess;
            cout << "\n";
            guess = toupper(guess);

            while (usedLetters.find(guess) != string::npos)
            {
                cout << "You've already guessed " << guess << ".\n\n";
                cout << "Enter your guess: ";
                cin >> guess;
                cout << "\n";
                guess = toupper(guess);
            }

            usedLetters += guess;

            if (WORD2.find(guess) != string::npos)
            {
                cout << "Good guess. " << guess << " is in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                for (int i = 0; i < WORD2.length(); ++i)
                {
                    if (WORD2[i] == guess)
                    {
                        soFar2[i] = guess;
                    }
                }
            }

            else
            {
                cout << "Unfortunately, " << guess << " was not in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                ++answeredWrong;
            }

            if (answeredWrong == MAX_WRONG)
            {
                cout << "I'm afraid you've guessed too many wrong, " << username << ".\n";
                this_thread::sleep_for(timespan);
                cout << "Lucky for you, this failure is not a major setback.\n";
                this_thread::sleep_for(timespan);
                cout << "But you'll have to restart from the beginning if you want to pass.\n\n";
                this_thread::sleep_for(timespan);
                goto onFailure;
            }
            
            else if (soFar2 == WORD2)
            {
                cout << "Congratulations, " << username << ", you have successfully guessed the second word.\n";
                this_thread::sleep_for(timespan);
                cout << "But the test isn't over. You have one final word left to guess.\n\n";
                this_thread::sleep_for(timespan);
            }
        }
        cout << "The word was " << WORD2 << ".\n\n";
        this_thread::sleep_for(timespan);

        // Third and final word
        cout << "Time to guess the third word, " << username << ".\n\n";
        this_thread::sleep_for(timespan);
        answeredWrong = 0;
        usedLetters = "";
        while ((answeredWrong < MAX_WRONG) && (soFar3 != WORD3))
        {
            cout << "You have " << (MAX_WRONG - answeredWrong) << " incorrect guesses left.\n\n";
            this_thread::sleep_for(timespan);

            cout << "You have guessed the following letters:\n" << usedLetters << "\n\n";
            this_thread::sleep_for(timespan);

            cout << "The word is:\n" << soFar3 << "\n\n";
            this_thread::sleep_for(timespan);

            cout << "Enter your guess: ";
            cin >> guess;
            cout << "\n";
            guess = toupper(guess);

            while (usedLetters.find(guess) != string::npos)
            {
                cout << "You've already guessed " << guess << ".\n\n";
                cout << "Enter your guess: ";
                cin >> guess;
                cout << "\n";
                guess = toupper(guess);
            }

            usedLetters += guess;

            if (WORD3.find(guess) != string::npos)
            {
                cout << "Good guess. " << guess << " is in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                for (int i = 0; i < WORD3.length(); ++i)
                {
                    if (WORD3[i] == guess)
                    {
                        soFar3[i] = guess;
                    }
                }
            }

            else
            {
                cout << "Unfortunately, " << guess << " was not in the keyword.\n\n";
                this_thread::sleep_for(timespan);

                ++answeredWrong;
            }

            if (answeredWrong == MAX_WRONG)
            {
                cout << "I'm afraid you've guessed too many wrong, " << username << ".\n";
                this_thread::sleep_for(timespan);
                cout << "Lucky for you, this failure is not a major setback.\n";
                this_thread::sleep_for(timespan);
                cout << "But you'll have to restart from the beginning if you want to pass.\n\n";
                this_thread::sleep_for(timespan);
                goto onFailure;
            }

            else if (soFar3 == WORD3)
            {
                cout << "Congratulations, " << username << ", you have successfully guessed the final word!\n";
                this_thread::sleep_for(timespan);
                cout << "The test is over. You have proven to be quite the guesser.\n";
                this_thread::sleep_for(timespan);
                cout << "You can keep playing for fun, or move on to your next assignment.\n";
                this_thread::sleep_for(timespan);
                cout << "You've done well, " << username << ".\n\n";
                this_thread::sleep_for(timespan);
            }
        }
        cout << "The word was " << WORD3 << ".\n\n";
        this_thread::sleep_for(timespan);

        onFailure:
        do
        {
            // Ask the recruit if they would like to run the simulation again
            cout << username << ", would you like to play again? y/n: ";
            cin >> yesOrNo;
            cout << endl;

            switch (yesOrNo) {    // If the recruit wants to run the simulation again
            case 'y':
            case 'Y':
                cout << "Resetting the simulation.\n\n";
                ++simulationsRun;    //     Increment the number of simulations ran counter
                repeatGame = true;    //     Move program execution back up to // Display the simulation # is starting to the recruit. 
                loopQuitOrPlayAgain = false;
                this_thread::sleep_for(timespan);
                system("pause");    //     Pause the Simulation with press any key to continue
                cout << endl;
                break;

                // Otherwise 
            case 'n':
            case 'N':
                //     Display End of Simulations to the recruit
                cout << "Terminating simulation. See you around, " << username << ".\n\n";
                repeatGame = false;
                loopQuitOrPlayAgain = false;
                this_thread::sleep_for(timespan);
                break;

            default:
                cout << "Please respond with y/n.\n\n";
                loopQuitOrPlayAgain = true;
            }
        } while (loopQuitOrPlayAgain);

    } while (repeatGame);

    return 0;
}

void introduction()
{
    chrono::duration<int, milli> timespan(1000);
    char line1[] = { "Welcome to the Keywords II Simulation for rookie operatives.\n" };

    for (int i = 0; i < strlen(line1); i++)
    {
        chrono::duration<int, milli> timespan(40);
        putchar(line1[i]);
        this_thread::sleep_for(timespan);
    }
    this_thread::sleep_for(timespan);
}

string logIn()
{
    chrono::duration<int, milli> timespan(1000);
    printf("What is your name, cadet?\n");
    this_thread::sleep_for(timespan);
    printf("Name: ");
    string username;
    cin >> username;
    cout << "\nWelcome to the simulation, " << username << ". Let's proceed.\n\n";
    this_thread::sleep_for(timespan);
    return username;
}