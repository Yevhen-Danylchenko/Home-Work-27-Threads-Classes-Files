// Created by Yevhen Danylchenko on 10.05.2025.
// Threads and Mutexes and Synchronization and Files
// Classes and Objects

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <thread>
#include <mutex>
#include <fstream>
#include "MyReferenceBook.h"
#include "MyMainReference.h"

int main()
{
	// Set the locale to Ukrainian
	std::locale::global(std::locale("uk_UA.UTF-8"));
	std::wcout.imbue(std::locale());

	// Create an instance of MyReferenceBook
	MyMainReference();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	

	std::cout << "Введіть будьякий символ для виходу з програми: \t";
	std::cin.get();

	return 0;
}



