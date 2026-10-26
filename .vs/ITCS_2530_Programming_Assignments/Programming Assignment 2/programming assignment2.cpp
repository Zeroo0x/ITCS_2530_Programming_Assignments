

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
	//Questions 
	std::cout << "Welcome to the anime reccomendation service, may I ask your name?\n";
	std::getline(std::cin, user_name);
	std::cout << "Hey " << user_name << ", how many hours do you watch anime per week? (Enter a number)\n";
	std::cin >> watch_hours;
	std::cin.ignore(); // Ignore the newline character left in the input buffer
	std::cout << "What is your favorite anime?\n";
	std::getline(std::cin, favorite_check);
	//Output plus additional questions for bonus game
	std::cout << "So you said you watch anime for " << watch_hours << " hours per week and your favorite anime is " << favorite_check << ".\n";
	std::cout << "Thanks, now lets play a little game before we go, we will calculate the value of your anime and watching habits.\n";
	std::cout << "If you had to pay money per watch hour, what would be the absoulte most you would be willing to pay? (Exact amount to the second decimal place)\n";
	std::cin >> anime_price;
	//Formula
	double anime_value = watch_hours * anime_price;
	std::cout << "So you said you would pay $" << anime_price << " per watch hour, and you watch anime for " << watch_hours << " hours per week.\n";
	std::cout << "This means your watching habits are worth $" << anime_value << " per week, really makes you think about how much time you watch anime, doesn't it?\n";
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

	report.close();

}

