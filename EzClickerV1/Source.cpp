#include <iostream>
#include "windows.h"
#include <thread>
#include "AutoClicker.h"
#include "input.h"
#include "Globals.h"

int main() {
	std::cout << "CPS: ";
	std::cin >> Globals::cps;

	std::thread clickerThread(autoclicker);
	std::thread inputThread(input);

	clickerThread.join();
	inputThread.join();

	return 0;
}