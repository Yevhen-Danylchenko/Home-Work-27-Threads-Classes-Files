// Created by Yevhen Danylchenko on 10.05.2025.
// Threads and Mutexes and Synchronization and Files
// Classes and Objects and Namespaces

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <locale>
#include <thread>
#include <mutex>
#include <fstream>

#include "MyReferenceBook.h"


void MyMainReference() {
	using namespace MyNamespace;
	
	std::locale::global(std::locale("uk_UA.UTF-8"));
	std::wcout.imbue(std::locale());

	Reference obj1("MyItCompany", "Yevhen Dan", "+380123456789", "Kyiv, Ukraine");
	Reference obj2("AvtoMoto", "Alexandr Dan", "+380987654321", "Lviv, Ukraine");
	Reference obj3("HimicTechnologycs", "Vlad Dan", "+380669740567", "Odesa, Ukraine");
	Reference obj4("MedicalTechnologycs", "Georgiy Romanov", "+380673451287", "Kharkiv, Ukraine");
	Reference obj5;

	std::thread t1(&Reference::saveToFile, &obj1, "references.txt");
	std::thread t2(&Reference::saveToFile, &obj2, "references.txt");
	std::thread t3(&Reference::saveToFile, &obj3, "references.txt");
	std::thread t4(&Reference::saveToFile, &obj4, "references.txt");

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	std::thread t5(&Reference::searchForCompany, &obj1, "references.txt", "MyItCompany");
	std::thread t6(&Reference::searchForCompany, &obj2, "references.txt", "AvtoMoto");	
	std::thread t7(&Reference::searchForCompany, &obj3, "references.txt", "HimicTechnologycs");
	std::thread t8(&Reference::searchForCompany, &obj4, "references.txt", "MedicalTechnologycs");

	t5.join();
	t6.join();
	t7.join();
	t8.join();

	std::thread t9(&Reference::searchForOwner, &obj1, "references.txt", "Yevhen Dan");
	std::thread t10(&Reference::searchForOwner, &obj2, "references.txt", "Alexandr Dan");
	std::thread t11(&Reference::searchForOwner, &obj3, "references.txt", "Vlad Dan");
	std::thread t12(&Reference::searchForOwner, &obj4, "references.txt", "Georgiy Romanov");

	t9.join();
	t10.join();
	t11.join();
	t12.join();

	std::thread t13(&Reference::searchForPhoneNumber, &obj1, "references.txt", "+380123456789");
	std::thread t14(&Reference::searchForPhoneNumber, &obj2, "references.txt", "+380987654321");
	std::thread t15(&Reference::searchForPhoneNumber, &obj3, "references.txt", "+380669740567");
	std::thread t16(&Reference::searchForPhoneNumber, &obj4, "references.txt", "+380673451287");

	t13.join();
	t14.join();
	t15.join();
	t16.join();

	std::thread t17(&Reference::readOfFile, &obj1, "references.txt");
	std::thread t18(&Reference::readOfFile, &obj2, "references.txt");
	std::thread t19(&Reference::readOfFile, &obj3, "references.txt");
	std::thread t20(&Reference::readOfFile, &obj4, "references.txt");
	std::thread t21(&Reference::addCompany, &obj5, "references.txt", "MyRoboticsCompany", "Yevhen Dan", "+380123456789", "Kyiv, Ukraine");

	t17.join();
	t18.join();
	t19.join();
	t20.join();
	t21.join();

	std::thread t22(&Reference::show, &obj1);
	std::thread t23(&Reference::show, &obj2);
	std::thread t24(&Reference::show, &obj3);
	std::thread t25(&Reference::show, &obj4);	
	std::thread t26(&Reference::show, &obj5);	
	
	t22.join();
	t23.join();
	t24.join();
	t25.join();
	t26.join();
}
