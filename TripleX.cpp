#include<iostream>
#include<ctime>

void PrintIntroduction(int Diffculty){

    std::cout << "\n\nYou are a secret agent breaking into a level "<< Diffculty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";

}

bool PlayGame(int Diffculty){
    //vars inishalize 
    int CodeA, CodeB, CodeC, CodeSum, CodeProduct, GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    PrintIntroduction(Diffculty);

    CodeA=( rand() % Diffculty )+Diffculty;
    CodeB=( rand() % Diffculty )+Diffculty;
    CodeC=( rand() % Diffculty )+Diffculty;

    CodeSum=CodeA+CodeB+CodeC;
    CodeProduct=CodeA*CodeB*CodeC;
    //print sum and produce to terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code \n";
    std::cout << "+ The codes add-up to : " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to: "<< CodeProduct << std::endl; 

    //get player guess
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    GuessSum=GuessA+GuessB+GuessC;
    GuessProduct=GuessA*GuessB*GuessC;

    //winnning condition
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going!***";
        return true;
    }else{
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again!***";
        return false;
    }
}

void main(){
    srand(time(NULL)); // creates new random seq based on time of the day
    int const MaxDifficulty = 5;
    int LevelDiffculty =1 ;

    bool bLevelComplete;

    while (LevelDiffculty<=MaxDifficulty) // Loop game untill all game completes
    {
        bLevelComplete=PlayGame(LevelDiffculty);
        std::cin.clear(); // clear any errors
        std::cin.ignore(); // discards the buffer
        if (bLevelComplete){
            LevelDiffculty++;
        }
    }
    std::cout<<"\n *** Great work agent! You got all the files! Now get out of there! ***\n";
}