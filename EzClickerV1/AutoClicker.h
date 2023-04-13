#pragma once
#include "windows.h"
#include "Globals.h"
#include "cFunc.h"

POINT getMousePos(/*int* const& x, int* const& y*/) {
	POINT pos;

	GetCursorPos(&pos);

	/**y = pos.x;
	*x = pos.y;*/

	return pos;
}

void mouse1Click(int xPos, int yPos) {
	/*INPUT Inputs[3] = {0};

	Inputs[0].type = INPUT_MOUSE;
	Inputs[0].mi.dx = xPos; // desired X coordinate
	Inputs[0].mi.dy = yPos; // desired Y coordinate
	Inputs[0].mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;

	Inputs[1].type = INPUT_MOUSE;
	Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	Inputs[2].type = INPUT_MOUSE;
	Inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(3, Inputs, sizeof(INPUT));*/

	mouse_event(MOUSEEVENTF_LEFTDOWN, xPos, yPos, 100, 100);
	mouse_event(MOUSEEVENTF_LEFTUP, xPos, yPos, 200, 200);
}

void autoclicker() {

	//if (!Globals::cEnabled) { return; }
	
	while (1) {
		if (Globals::cEnabled) {
			Globals::cDelay = (1000 / Globals::cps);

			//int xPos, yPos;
			//getMousePos(&xPos, &yPos);

			POINT mPos = getMousePos();

			mouse1Click(mPos.x, mPos.y);

			//std::cout << "x: " << mPos.x << " y: " << mPos.y << " delay: " << Globals::cDelay << std::endl;

			Sleep(Globals::cDelay);
		}
	}
}