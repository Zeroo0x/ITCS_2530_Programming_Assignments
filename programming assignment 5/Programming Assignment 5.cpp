
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif

// Simple color helpers (ANSI)
void enableColors() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BOLD = "\033[1m";

void printWelcomeBanner() {
    //New Intro
    std::cout << BOLD << CYAN;
    std::cout << "==================================================\n";
    std::cout << "          ANIME RECOMMENDATION SERVICE            \n";
    std::cout << "==================================================\n";
    std::cout << RESET;
    std::cout << YELLOW << "     Your personal anime habits analyzer\n" << RESET;
    std::cout << BOLD << CYAN << "==================================================\n\n" << RESET;
}

double calculateAnimeValue(int a, double b) {
	return a * b;
}

void showMenu(int x, double y, std::string& outputstatement1, std::string& outputstatement2) {
    //Menu Function
    int choice;
    do {
        std::cout << "\n" << BOLD << BLUE << "--- Main Menu ---\n" << RESET;
        std::cout << GREEN << "1. View Watching Summary\n";
        std::cout << GREEN << "2. View Spending Summary\n";
        std::cout << RED << "3. Exit\n" << RESET;
        std::cout << CYAN << "Enter your choice: " << RESET;

        std::cin >> choice;

        switch (choice) {
        case 1:
            if (x > 20) {
                outputstatement1 = "Wow, you watch a lot of anime. Over 20 hours a week? perhaps you should tone that down a little\n";
            }
            else if (x > 10 && x <= 20) {
                outputstatement1 = "You watch a decent amount of anime, somewhere between 10 and 20 hours a week, but not too much, nothing crazy.\n";
            }
            else if (x > 1 && x <= 10) {
                outputstatement1 = "You probably have a busy week and are just squeezing in some time for your shows, under 10 hours a week I get it.\n";
            }
            else {
                outputstatement1 = "You don't watch too much anime.";
            }
            std::cout << MAGENTA << outputstatement1 << RESET;
            break;

        case 2:
            if (y > 80) {
                outputstatement2 = "Alright I see you! You are a big spender over 80 bucks! \n";
            }
            else if (y > 20 && y <= 80) {
                outputstatement2 = "You are willing to pay a decent amount for your anime over 20 bucks, but nothing too crazy\n";
            }
            else if (y > 1 && y <= 20) {
                outputstatement2 = "You are likely on a budget or don't want to spend too much on watching a show, keeping it under 20 dollars which is understandable.\n";
            }
            else {
                outputstatement2 = "You don't watch anime or you are beyond frugal!\n";
            }
            std::cout << MAGENTA << outputstatement2 << RESET;
            break;

        case 3:
            break;
        default:
            std::cout << RED << "Invalid selection!\n" << RESET;
            break;
        }
    } while (choice != 3);
}

void generateReport(const std::string& user_name,
    const std::string& favorite_check,
    int watch_hours,
    double anime_price,
    double anime_value,
    const std::string& outputstatement1,
    const std::string& outputstatement2) {
    // Write the report file
    std::ofstream report("report.txt");

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

    // Read and display the report
    std::ifstream read_report("report.txt");
    std::string line;

    std::cout << "\n" << BOLD << CYAN << "===== REPORT =====\n" << RESET;
    while (std::getline(read_report, line)) {
        std::cout << GREEN << line << "\n" << RESET;
    }
    read_report.close();
}

int main()
{
	enableColors();
    printWelcomeBanner();
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
    std::cout << RED << "Welcome to the anime reccomendation service, may I ask your name?\n" << RESET;
    std::getline(std::cin, user_name);

    std::cout << RED << "Hey " << user_name << ", how many hours do you watch anime per week? (Enter a number)\n" << RESET;
    std::cin >> watch_hours;
    std::cin.ignore();

    std::cout << RED << "What is your favorite anime?\n" << RESET;
    std::getline(std::cin, favorite_check);

    //Output plus additional questions for bonus game
    std::cout << RED << "So you said you watch anime for " << watch_hours << " hours per week and your favorite anime is " << favorite_check << ".\n" << RESET;
    std::cout << RED << "Thanks, now lets play a little game before we go, we will calculate the value of your anime and watching habits.\n" << RESET;
    std::cout << RED << "If you had to pay money per watch hour, what would be the absoulte most you would be willing to pay? (Exact amount to the second decimal place)\n" << RESET;
    std::cin >> anime_price;
    int choice;


    //Formula
    double anime_value = calculateAnimeValue(watch_hours, anime_price);

    std::cout << RED << "So you said you would pay $" << anime_price << " per watch hour, and you watch anime for " << watch_hours << " hours per week.\n" << RESET;
    std::cout << RED << "This means your watching habits are worth $" << anime_value << " per week, really makes you think about how much time you watch anime, doesn't it?\n" << RESET;
	//Menu Call
	showMenu(watch_hours, anime_price, outputstatement1, outputstatement2);

    //For loop for watched anime
    for (int i = 0; i < 3; i++) {
        std::cout << YELLOW << "Have you watched any of the following anime?\n" << RESET;
        std::cout << YELLOW << "1. Naruto\n" << RESET;
        std::cout << YELLOW << "2. One Piece\n" << RESET;
        std::cout << YELLOW << "3. Dragon Ball\n" << RESET;
        std::cout << YELLOW << "4. Berserk\n" << RESET;
        std::cout << YELLOW << "5. Attack on Titan\n" << RESET;
        std::cout << YELLOW << "6. Death Note\n" << RESET;
        std::cout << YELLOW << "7. Monster\n" << RESET;
        std::cout << YELLOW << "8. Vinland Saga\n" << RESET;
        std::cout << YELLOW << "9. Another\n" << RESET;
        std::cout << YELLOW << "0. None\n" << RESET;
        std::cin >> watched_anime;

        switch (watched_anime)
        {
        case 1:
        case 2:
        case 3:
            std::cout << GREEN << "Shonen, I see...\n" << RESET;
            shonen_score++;
            break;
        case 4:
        case 5:
        case 8:
            std::cout << RED << "Seinen, I see...\n" << RESET;   
            seinen_score++;
            break;
        case 6:
        case 7:
        case 9:
            std::cout << BLUE << "Drama, I see...\n" << RESET;
            drama_score++;
            break;
        case 0:
            std::cout << RED << "You haven't watched any of these anime.\n" << RESET;
            break;
        default:
            std::cout << RED << "You didn't select a valid option.\n" << RESET;
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
        std::cout << MAGENTA << "Do you like any of the following anime?\n" << RESET;
        std::cout << MAGENTA << "1. Naruto\n" << RESET;
        std::cout << MAGENTA << "2. One Piece\n" << RESET;
        std::cout << MAGENTA << "3. Dragon Ball\n" << RESET;
        std::cout << MAGENTA << "4. Berserk\n" << RESET;
        std::cout << MAGENTA << "5. Attack on Titan\n" << RESET;
        std::cout << MAGENTA << "6. Death Note\n" << RESET;
        std::cout << MAGENTA << "7. Monster\n" << RESET;
        std::cout << MAGENTA << "8. Vinland Saga\n" << RESET;
        std::cout << MAGENTA << "9. Another\n" << RESET;
        std::cout << MAGENTA << "0. None\n" << RESET;
        std::cin >> liked_anime;

        switch (liked_anime)
        {
        case 1:
        case 2:
        case 3:
            std::cout << GREEN <<  "Shonen, I see...\n" << RESET;
            like_shonen++;
            break;
        case 4:
        case 5:
        case 8:
            std::cout << RED << "Seinen, I see...\n" << RESET;
            like_seinen++;
            break;
        case 6:
        case 7:
        case 9:
            std::cout << BLUE << "Drama, I see...\n" << RESET;
            like_drama++;
            break;
        case 0:
            std::cout << RED << "You haven't watched any of these anime.\n" << RESET;
            break;
        default:
            std::cout << RED << "You didn't select a valid option.\n" << RESET;
            break;

        }
        like_counter++;

    }
    if (shonen_score > seinen_score && shonen_score > drama_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << CYAN << "So you mostly watch shonen and mostly enjoy shonen.\n" << RESET;
    }
    else if (shonen_score > seinen_score && shonen_score > drama_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << CYAN << "So you mostly watch shonen but mostly enjoy seinen.\n" << RESET;
    }
    else if (shonen_score > seinen_score && shonen_score > drama_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << CYAN << "So you mostly watch shonen but mostly enjoy drama.\n" << RESET;
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << CYAN << "So you mostly watch seinen but mostly enjoy shonen.\n" << RESET;
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << CYAN << "So you mostly watch seinen and mostly enjoy seinen.\n" << RESET;
    }
    else if (seinen_score > shonen_score && seinen_score > drama_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << CYAN << "So you mostly watch seinen but mostly enjoy drama.\n" << RESET;
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_shonen > like_seinen && like_shonen > like_drama) {
        std::cout << CYAN << "So you mostly watch drama but mostly enjoy shonen.\n" << RESET;       
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_seinen > like_shonen && like_seinen > like_drama) {
        std::cout << CYAN << "So you mostly watch drama but mostly enjoy seinen.\n" << RESET;
    }
    else if (drama_score > shonen_score && drama_score > seinen_score && like_drama > like_shonen && like_drama > like_seinen) {
        std::cout << CYAN << "So you mostly watch drama and mostly enjoy drama.\n" << RESET;
    }

	generateReport(user_name, favorite_check, watch_hours, anime_price, anime_value, outputstatement1, outputstatement2);
	return 0;

}
