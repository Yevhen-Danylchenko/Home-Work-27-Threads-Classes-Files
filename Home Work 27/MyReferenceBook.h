// File: MyReferenceBook.h
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

namespace MyNamespace {
	class Reference {
	private:	
		std::string companyName;
		std::string companyOwner;
		std::string phoneNumber;
		std::string companyAddress;
		std::mutex mt;
	public:
		explicit Reference(){}
		explicit Reference(std::string companyName, std::string companyOwner, std::string phoneNumber, std::string companyAddress)
			: companyName(companyName), companyOwner(companyOwner), phoneNumber(phoneNumber), companyAddress(companyAddress) {}

		std::string getCompanyName() const { return companyName; }
		std::string getCompanyOwner() const { return companyOwner; }
		std::string getPhoneNumber() const { return phoneNumber; }
		std::string getCompanyAddress() const { return companyAddress; }

		void setCompanyName(const std::string& companyName) { this->companyName = companyName; }
		void setCompanyOwner(const std::string& companyOwner) { this->companyOwner = companyOwner; }
		void setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
		void setCompanyAddress(const std::string& companyAddress) { this->companyAddress = companyAddress; }

		void saveToFile(const std::string& filename) {
			std::lock_guard<std::mutex> lock(mt); // Lock the mutex to ensure thread safety
			std::ofstream file(filename, std::ios::app);
			if (file.is_open()) {
				file << companyName << " : " << companyOwner << " : " << phoneNumber << " : " << companyAddress << std::endl;
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для запису." << std::endl;
			}
		
		}

		void searchForCompany(const std::string& filename, const std::string& companyName) {
			std::lock_guard<std::mutex> lock(mt);
			std::ifstream file(filename);
			if (file.is_open()) {
				std::string line;
				while (std::getline(file, line)) {
					if (line.find(companyName) != std::string::npos) {
						std::cout << "Знайдено: " << line << std::endl;
						return;
					}
				}
				std::cout << "Компанiю не знайдено." << std::endl;
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для читання." << std::endl;
			}
		}

		void searchForOwner(const std::string& filename, const std::string& companyOwner) {
			std::lock_guard<std::mutex> lock(mt);
			std::ifstream file(filename);
			if (file.is_open()) {
				std::string line;
				while (std::getline(file, line)) {
					if (line.find(companyOwner) != std::string::npos) {
						std::cout << "Знайдено: " << line << std::endl;
						return;
					}
				}
				std::cout << "Власника не знайдено." << std::endl;
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для читання." << std::endl;
			}
		}

		void searchForPhoneNumber(const std::string& filename, const std::string& phoneNumber) {
			std::lock_guard<std::mutex> lock(mt);
			std::ifstream file(filename);
			if (file.is_open()) {
				std::string line;
				while (std::getline(file, line)) {
					if (line.find(phoneNumber) != std::string::npos) {
						std::cout << "Знайдено: " << line << std::endl;
						return;
					}
				}
				std::cout << "Телефонний номер не знайдено." << std::endl;
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для читання." << std::endl;
			}
		}

		void addCompany(const std::string& filename, const std::string& companyName, const std::string& companyOwner, const std::string& phoneNumber, const std::string& companyAddress) {
			std::lock_guard<std::mutex> lock(mt);
			std::ofstream file(filename, std::ios::app);
			if (file.is_open()) {
				file << companyName << " : " << companyOwner << " : " << phoneNumber << " : " << companyAddress << std::endl;
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для запису." << std::endl;
			}
		}
		void readOfFile(const std::string& filename) {
			std::lock_guard<std::mutex> lock(mt);
			std::ifstream file(filename);
			if (file.is_open()) {
				std::string line;
				while (std::getline(file, line)) {
					std::cout << line << std::endl;
				}
				file.close();
			}
			else {
				std::cout << "Неможливо вiдкрити файл для читання." << std::endl;
			}
		}

		void show() {
			std::lock_guard<std::mutex> lock(mt);
			std::cout << "----------------------------------------" << std::endl;
			std::cout << "Назва компанiї: " << companyName << std::endl;
			std::cout << "Власник компанiї: " << companyOwner << std::endl;
			std::cout << "Телефонний номер компанiї: " << phoneNumber << std::endl;
			std::cout << "Адреса компанiї: " << companyAddress << std::endl;
			std::cout << "----------------------------------------" << std::endl;
		}
		~Reference() {}		
	};

}



