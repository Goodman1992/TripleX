#include<iostream>
//#include<>

void PrintIntroduction(int Diffculty){

    std::cout << "\n\nYou are a secret agent breaking into a level "<< Diffculty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";

}

bool PlayGame(int Diffculty){
    //vars inishalize 
    int CodeA, CodeB, CodeC, CodeSum, CodeProduct, GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    PrintIntroduction(Diffculty);

    CodeA=4;
    CodeB=3;
    CodeC=2;

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
        std::cout << "\nYou win!";
        return true;
    }else{
        std::cout << "\nYou Lose!";
        return false;
    }
}

void main(){
    bool bLevelComplete;
    int LevelDiffculty =1 ;
    while (true)
    {
        
        bLevelComplete=PlayGame(LevelDiffculty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete){
            LevelDiffculty++;
        }else{
            continue;
        }
    }
}