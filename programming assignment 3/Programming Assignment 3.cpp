
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main()
{
    //Variables
    std::string user_name;
    std::string anime_check;
    int watch_hours;
    double anime_price;
    std::string favorite_check;
    std::string outputstatement1;
    std::string outputstatement2;

    //Questions 
    std::cout << "Welcome to the anime reccomendation service, may I ask your name?\n";
    std::getline(std::cin, user_name);

    std::cout << "Hey " << user_name << ", how many hours do you watch anime per week? (Enter a number)\n";
    std::cin >> watch_hours;
    std::cin.ignore();

    std::cout << "What is your favorite anime?\n";
    std::getline(std::cin, favorite_check);

    //Output plus additional questions for bonus game
    std::cout << "So you said you watch anime for " << watch_hours << " hours per week and your favorite anime is " << favorite_check << ".\n";
    std::cout << "Thanks, now lets play a little game before we go, we will calculate the value of your anime and watching habits.\n";
    std::cout << "If you had to pay money per watch hour, what would be the absoulte most you would be willing to pay? (Exact amount to the second decimal place)\n";
    std::cin >> anime_price;
    int choice;


    //Formula
    double anime_value = watch_hours * anime_price;

    std::cout << "So you said you would pay $" << anime_price << " per watch hour, and you watch anime for " << watch_hours << " hours per week.\n";
    std::cout << "This means your watching habits are worth $" << anime_value << " per week, really makes you think about how much time you watch anime, doesn't it?\n";

    std::cout << "\n--- Main Menu ---\n";
    std::cout << "1. View Watching Summary\n";
    std::cout << "2. View Spending Summary\n";
    std::cout << "Enter your choice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
        // Display watching summary
        if (watch_hours > 20)
        {
            outputstatement1 = "Wow, you watch a lot of anime. Over 20 hours a week? perhaps you should tone that down a little\n";
        }
        else if (watch_hours > 10 && watch_hours <= 20)
        {
            outputstatement1 = "You watch a decent amount of anime, somewhere between 10 and 20 hours a week, but not too much, nothing crazy.\n";
        }
        else if (watch_hours > 1 && watch_hours <= 10)
        {
            outputstatement1 = "You probably have a busy week and are just squezing in some time for your shows, under 10 hours a week I get it.\n";
        }
        else
        {
            outputstatement1 = "You don't watch too much anime.";
        }
        std::cout << outputstatement1;
        break;

    case 2:
        // Display spending summary
        if (anime_price > 80)
        {
            outputstatement2 = "Alright I see you! You are a big spender over 80 bucks! \n";
        }
        else if (anime_price > 20 && anime_price <= 80)
        {
            outputstatement2 = "You are willing to pay a decent amount for your anime over 20 bucks, but nothing too crazy\n";
        }
        else if (anime_price > 1 && anime_price <= 20)
        {
            outputstatement2 = "You are likely on a budget or don't want to spend too much on watching a show,keeping it under 20 dollars which is understandable.\n";
        }
        else
        {
            outputstatement2 = "You don't watch anime or you are beyond frugal!\n";
        }
        std::cout << outputstatement2;
        break;

    default:
        std::cout << "Invalid selection!\n";
        break;
    }






    std::ofstream report("C:\\Users\\Owner\\source\\repos\\ITCS_2530_Programming_Assignments\\programming assignment 3\\report.txt");

    //Reporting
    report << std::left;
    report << std::setw(30) << "ANIME WATCHING REPORT" << "\n";
    report << std::setw(30) << "---------------------" << "\n";
    report << std::setw(30) << "Category"
        << std::setw(20) << "Value" << "\n";
    report << std::setw(30) << "---------------------"
        << std::setw(20) << "----------------" << "\n";

    report << std::setw(30) << "Name"
        << std::setw(20) << user_name << "\n";

    report << std::setw(30) << "Favorite Anime"
        << std::setw(20) << favorite_check << "\n";

    report << std::setw(30) << "Hours Per Week"
        << std::setw(20) << watch_hours << "\n";

    report << std::setw(30) << "Price Per Hour"
        << "$" << std::fixed << std::setprecision(2)
        << anime_price << "\n";

    report << std::setw(30) << "Weekly Anime Value"
        << "$" << std::fixed << std::setprecision(2)
        << anime_value << "\n";

    report << std::setw(30) << "Concluding Judgment"
        << std::setw(20) << outputstatement1 << outputstatement2;
    report.close();

    return 0;
}
