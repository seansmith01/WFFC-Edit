#pragma once

struct InputCommands
{
	bool forward;
	bool back;
	bool right;
	bool left;
	bool up;
	bool down;

	int mousePosX;
	int mousePosY;
	
	bool mouseLeftDown;
	bool mouseRightDown;
	bool multiSelectDown;

	bool copy;
	bool paste;
};
