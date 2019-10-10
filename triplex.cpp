#include <iostream>
//#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou're house is infested with level "<< Difficulty <<" fruit flies...\n";
    std::cout << "Enter the correct code to secure the vial containing the cure...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou've completed level " << Difficulty;
        std::cout << "! The fruit flies will be eradicated in no time...";
        return true;
    }
    else
    {
        std::cout << "\nOh no... They're everywhere! You'll be sleeping under the bridge tonight...";
        return false;
    }
}



int main()
{  
    //srand(time(NULL));

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
            std::cout << "AHHHHH" <<LevelDifficulty;
        }
        
    }
    std::cout << "\n\nCongratulations on destroying all of the fruit flies!\n";
    return 0;
}