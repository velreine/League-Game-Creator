// ButtonLocations.h
#include <iostream>

using namespace std;
// Data types::
struct ClickAbleArea
{
	int s_X; // Start X
	int s_Y; // Start Y

	int e_X; // End X
	int e_Y; // End Y
};



// Function prototypes::
POINT GetCenterOfArea(ClickAbleArea in_caa);
void  XClickButton(ClickAbleArea in_caa, int x_offset, int y_offset);
void CreateGame(int category, int gameMode, int gameMap, int gameType);


// Globals::
RECT rctOfClient;

// Objects:
// s_X, s_Y, e_X, e_Y
ClickAbleArea area_PlayButton = { 560, 15, 710, 65 };
ClickAbleArea area_PvPButton = { 240, 92, 415, 146 };
ClickAbleArea area_CoopVsAIButton = { 240, 148, 415, 202 };
ClickAbleArea area_CustomButton = { 240, 204, 415, 258 };
ClickAbleArea area_TutorialsButton = { 240, 260, 415, 314 };
ClickAbleArea area_HomeButton = { 243, 717, 332, 740 };
ClickAbleArea area_GameMode1Button = { 433, 139, 614, 164 };
ClickAbleArea area_GameMode2Button = { 433, 174, 614, 183 };
ClickAbleArea area_GameMode3Button = { 433, 205, 614, 211 };
ClickAbleArea area_GameMap1Button = { 637, 139, 811, 215 };
ClickAbleArea area_GameMap2Button = { 637, 188, 811, 215 };
ClickAbleArea area_GameType1Button = { 846, 146, 1000, 171 };
ClickAbleArea area_GameType2Button = { 846, 188, 1000, 213 };
ClickAbleArea area_GameType3Button = { 846, 231, 1000, 255 };
ClickAbleArea area_GameType4Button = { 846, 272, 1000, 297 };
ClickAbleArea area_Orange1Button = { 670, 685, 845, 735 };
ClickAbleArea area_Orange2Button = { 855, 685, 1030, 735 };
//NOTE:: THE ABOVE OFFSETS ARE OFFSETS FROM WITHIN THE CLIENT, 
//NOTE:: THIS MEANS THAT YOU HAVE TO GET THE POSITION OF THE CLIENT AS WELL.


// Actual functions::


POINT GetCenterOfArea(ClickAbleArea in_caa)
{
	int tmp_width;
	int tmp_height;
	POINT valtoreturn;
	// First we need to calculate width and height.

	tmp_width = (in_caa.e_X - in_caa.s_X); // Width equals EndX - StartX
	tmp_height = (in_caa.e_Y - in_caa.s_Y); // Height equals EndY - StartY

	// Now we simply divide width and height by 2.

	tmp_width = (tmp_width / 2);
	tmp_height = (tmp_height / 2);

	// Now we have values to add to our hard offset

	valtoreturn.x = (in_caa.s_X + tmp_width);
	valtoreturn.y = (in_caa.s_Y + tmp_height);

	return valtoreturn;

}



void XClickButton(ClickAbleArea in_caa, int x_offset, int y_offset)
{
	POINT centerPoints = GetCenterOfArea(in_caa);


	// Set position of the mouse to center of the area.
	SetCursorPos(centerPoints.x + x_offset, centerPoints.y + y_offset);

	// Now simulate the click.

	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, centerPoints.x + x_offset, centerPoints.y + y_offset, 0, 0);

	cout << "clicked x: " << centerPoints.x << endl;
	cout << "clicked y: " << centerPoints.y << endl;
}

void CreateGame(int category, int gameMode, int gameMap, int gameType)
{
	// Categories::
	// 0 = PVP 
	// 1 = Co-op vs. AI
	// 2 = Custom
	// 3 = Tutorials <-- tutorials aren't actually supported, but the bot supports creating the game.

	// Game modes::
	// 0 = Classic / Normal
	// 1 = Dominion
	// 2 = ARAM

	// Game map::
	// 0 = Summoner's Rift
	// 1 = Twisted Treeline

	// Game type::
	// 0 = Normal (Teambuilder)
	// 1 = Normal (Blind Pick)
	// 2 = Normal (Draft Pick)
	// 3 = Ranked Solo/Duo (Draft Pick)
	

	// 1. Click Play
	XClickButton(area_PlayButton, rctOfClient.left, rctOfClient.top);
	Sleep(500);
	// 2. Click Category
	

	switch (category)
	{
		
	case 0:
		XClickButton(area_PvPButton, rctOfClient.left, rctOfClient.top);
		break;

	case 1:
		XClickButton(area_CoopVsAIButton, rctOfClient.left, rctOfClient.top);
		break;

	case 2:
		XClickButton(area_CustomButton, rctOfClient.left, rctOfClient.top);
		break;

	case 3:
		XClickButton(area_TutorialsButton, rctOfClient.left, rctOfClient.top);
		break;
	default:
		// do nothing if no match
		cout << "A game could not be created, because such category doesn't exist!" << endl;

	}
	Sleep(500);

	// 3. Click Game mode
	switch (gameMode)
	{

	case 0:
		XClickButton(area_GameMode1Button, rctOfClient.left, rctOfClient.top);
		break;

	case 1:
		XClickButton(area_GameMode2Button, rctOfClient.left, rctOfClient.top);
		break;

	case 2:
		XClickButton(area_GameMode3Button, rctOfClient.left, rctOfClient.top);
		break;


	default:
		// do nothing if no match
		cout << "A game could not be created, because a game mode with that ID doesn't exist!" << endl;

	}
	Sleep(500);

	// 4. Click Game Map
	switch (gameMap)
	{
	
	case 0: // Summoner's Rift
		XClickButton(area_GameMap1Button, rctOfClient.left, rctOfClient.top);
		break;
	case 1: // Twisted Treeline
		XClickButton(area_GameMap2Button, rctOfClient.left, rctOfClient.top);
		break;

	default:
		// do nothing if no match
		cout << "A game could not be created, because a map with that ID does not exist." << endl;
	}
	Sleep(500);

	// 5. Click Game Type
	switch (gameType)
	{
	case 0:
		XClickButton(area_GameType1Button, rctOfClient.left, rctOfClient.top);
		break;

	case 1:
		XClickButton(area_GameType2Button, rctOfClient.left, rctOfClient.top);
		break;

	case 2:
		XClickButton(area_GameType3Button, rctOfClient.left, rctOfClient.top);
		break;

	case 3:
		XClickButton(area_GameType4Button, rctOfClient.left, rctOfClient.top);
		break;



	default:
		// asdfgh
		cout << "A game could not be created, because no game type matches that ID!" << endl;
	}
	Sleep(500);





	// Now click orange button :-)

	XClickButton(area_Orange1Button, rctOfClient.left, rctOfClient.top);

}













