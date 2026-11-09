
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
    int watched_anime;
    int shonen_score = 0;
    int seinen_score = 0;
    int drama_score = 0;
    int liked_anime = 0;
    int like_shonen = 0;
    int like_seinen = 0;
    int like_drama = 0;
    int like_counter = 0;

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
    //Loop for menu
    do {
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

        case 3:
            break;
        default:
            std::cout << "Invalid selection!\n";
            break;
        }
    } while (choice != 3);

    //For loop for watched anime
    for (int i = 0; i < 3; i++) {
        std::cout << "Have you watched any of the following anime?\n";
        std::cout << "1. Naruto\n";
        std::cout << "2. One Piece\n";
        std::cout << "3. Dragon Ball\n";
        std::cout << "4. Berserk\n";
        std::cout << "5. Attack on Titan\n";
        std::cout << "6. Death Note\n";
        std::cout << "7. Monster\n";
        std::cout << "8. Vinland Saga\n";
        std::cout << "9. Another\n";
        std::cout << "0. None\n";
        std::cin >> watched_anime;

        switch (watched_anime)
        {
        case 1:
        case 2:
        case 3:
            std::cout << "Shonen, I see...\n";
            shonen_score++;
            break;
        case 4:
        case 5:
        case 8:
            std::cout << "Seinen, I see...\n";
            seinen_score++;
            break;
        case 6:
        case 7:
        case 9:
            std::cout << "Drama, I see...\n";
            drama_score++;
            break;
        case 0:
            std::cout << "You haven't watched any of these anime.\n";
            break;
        default:
            std::cout << "You didn't select a valid option.\n";
            break;

        }

    }
    if (shonen_score > seinen_score && shonen_score > drama_score) {
        std::cout << "You seem to watch Shonen anime the most!\n";
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score) {
        std::cout << "You seem to watch Seinen anime the most!\n";
    }
    else {
        std::cout << "You seem to watch Drama anime the most!\n";
    }
    //While loop for liked anime
    while (like_counter < 5) {
        std::cout << "Do you like any of the following anime?\n";
        std::cout << "1. Naruto\n";
        std::cout << "2. One Piece\n";
        std::cout << "3. Dragon Ball\n";
        std::cout << "4. Berserk\n";
        std::cout << "5. Attack on Titan\n";
        std::cout << "6. Death Note\n";
        std::cout << "7. Monster\n";
        std::cout << "8. Vinland Saga\n";
        std::cout << "9. Another\n";
        std::cout << "0. None\n";
        std::cin >> liked_anime;

        switch (liked_anime)
        {
        case 1:
        case 2:
        case 3:
            std::cout << "Shonen, I see...\n";
            like_shonen++;
            break;
        case 4:
        case 5:
        case 8:
            std::cout << "Seinen, I see...\n";
            like_seinen++;
            break;
        case 6:
        case 7:
        case 9:
            std::cout << "Drama, I see...\n";
            like_drama++;
            break;
        case 0:
            std::cout << "You haven't watched any of these anime.\n";
            break;
        default:
            std::cout << "You didn't select a valid option.\n";
            break;

        }
        like_counter++;

    }
    if (shonen_score > seinen_score && shonen_score > drama_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << "So you mostly watch shonen and mostly enjoy shonen.\n";
    }
    else if (shonen_score > seinen_score && shonen_score > drama_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << "So you mostly watch shonen but mostly enjoy seinen.\n";
    }
    else if (shonen_score > seinen_score && shonen_score > drama_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << "So you mostly watch shonen but mostly enjoy drama.\n";
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << "So you mostly watch seinen but mostly enjoy shonen.\n";
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << "So you mostly watch seinen and mostly enjoy seinen.\n";
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << "So you mostly watch seinen but mostly enjoy drama.\n";
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << "So you mostly watch drama but mostly enjoy shonen.\n";
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << "So you mostly watch drama but mostly enjoy seinen.\n";
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << "So you mostly watch drama and mostly enjoy drama.\n";
    }

    std::ofstream report("report.txt");

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
        << std::setw(20) << outputstatement1 << "\n" << outputstatement2;
    report.close();

    std::ifstream read_report("report.txt");

    std::string line;

    while (std::getline(read_report, line))
    {
        std::cout << line << "\n";
    }

    read_report.close();
    return 0;

}
