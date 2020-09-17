#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Prints welcome messages to the terminal
    std::cout << "\n\nYou are a swabbie breaking into a level " << Difficulty;
    std::cout << " chest within the ship's hold...";
    std::cout << "\nYou need to crack the code on the chest to access the treasures within...";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and product to the terminal
    std::cout << std::endl;
    std::cout <<"\n\n+ There are 3 numbers in the code";
    std::cout <<"\n+ The codes add up to: "<< CodeSum;
    std::cout <<"\n+ The codes multiply to give: "<< CodeProduct;
    
    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >>GuessC;
    std::cout << "\n\nYou entered:" << GuessA << GuessB << GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\nThe chest unlocks and you are granted access to the legendary treasure!";
        return(true);
    }

    else 
    {
        std::cout << "\n\nThe chest bursts into flames in a fit of rage!";
        std::cout << "\nPlease try again.";
        return(false);
    }
}

int main()
{
    srand(time(NULL)); // create new randome sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 6;

    while (LevelDifficulty <= MaxLevel) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears errors
        std::cin.ignore(); // Discards buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; //increases level difficulty
        }

    }   

    std::cout << "\n\n*** You have unlocked all the chests within the ship's hold. You are truly a legendary pirate!***";
    return 0;
}
