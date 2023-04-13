#pragma once
#include "windows.h"
#include "Globals.h"
#include <iostream>

void input() {
	while (1) {
		if (GetAsyncKeyState(VK_F6) && !Globals::holdingToggle) {
			Globals::holdingToggle = true;

			Globals::cEnabled = !Globals::cEnabled;

			std::cout << "Clicker: " << Globals::cEnabled << std::endl;
		}
		else if (!GetAsyncKeyState(VK_F6)) {
			Globals::holdingToggle = false;
		}

		if (GetAsyncKeyState(VK_F5) && !Globals::holdingCPS) {
			Globals::holdingCPS = true;

			std::cout << "CPS: ";
			std::cin >> Globals::cps;
		}
		else if (!GetAsyncKeyState(VK_F5)) {
			Globals::holdingCPS = false;
		}
	}
}