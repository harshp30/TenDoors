/*
A terminal based math game.
Harsh Patel
*/

// Included Libraries
#include <iostream>
#include <ctime>

void PrintLevel(int Difficulty)
{
    std::cout << std::endl;
    std::cout << "Unlock door number " << Difficulty << ".\n\n";
}// End PrintLevel()

bool PlayGame(int Difficulty)
{
    PrintLevel(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "- There are 3 numbers in the code\n";
    std::cout << "- The codes add-up to: " << CodeSum << "\n";
    std::cout << "- The code multiply to give: " << CodeProduct << "\n\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct (Game Logic)
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "***Door Unlocked***\n";
        return true;
    }// End if
    else 
    {
        std::cout << "***Incorrect Code***\n";
        return false;
    }// End else

    std::cout << std::endl;

}// End PlayGame()

int main()
{

    std::cout << "\n";
    // Print initial messages to the terminal
    std::cout << "Welcome to 10 Doors...\n";
    std::cout << "You have been kindapped by a bunch of computer hackers who want to kill you because you said linux sucks...\n";
    std::cout << "To escape from your kidnappers eneter the correct codes to unlock the doors...\n\n";

    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }// End if
    }// End while

    std::cout << "\nYou have escaped. Run before the computer people catch you again!!!\n";

    return 0;
}// End main()
