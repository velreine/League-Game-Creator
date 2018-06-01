#include <iostream>
#include <Windows.h>
#include "Buttons.h"

using namespace std;

// Function prototypes:
void SetMouseFunc();

// Globals





int main()
{
	int pauseint;
	bool infiniteloop = true;

	POINT MouseCoords;
	HWND wHandle = FindWindow(0, "PVP.net Client");
	
	
	while (infiniteloop)
	{
		system("cls");
		GetCursorPos(&MouseCoords);
		cout << "Mouse pos X:" << MouseCoords.x << endl;
		cout << "Mouse pos Y:" << MouseCoords.y << endl;
		

		// If we haven't found a handle:

		if (wHandle == NULL)
		{
			cout << "Still looking for PVP.net Client, is it open?" << endl;
			//wHandle // League of Legends 5.6.15_03_19_15_46
		}
		
		if (wHandle != NULL)
		{

			GetWindowRect(wHandle, &rctOfClient); // will this work?
			cout << "Rect left: " << rctOfClient.left << endl;			// Start X of client.
			cout << "Rect top: " << rctOfClient.top << endl;			// Start Y of client.
			cout << "Rect right: " << rctOfClient.right << endl;		// End X of client.
			cout << "Rect bottom: " << rctOfClient.bottom << endl;		// End Y of client.
		}
		
		

		if (GetAsyncKeyState(VK_F1))
		{
			infiniteloop = false;
		}

		if (GetAsyncKeyState(VK_F2))
		{
			//SetMouseFunc();
			//XClickButton(area_PlayButton, rctOfClient.left, rctOfClient.top);
			// REMEMBER: STILL NEED TO GET POSITION OFF CLIENT FIRST. ELSE WILL CLICK RANDOM AT SCREEN.
			CreateGame(0, 0, 0, 1);
			
		}



		Sleep(500);

	}
	
	
	
	
	
	
	
	
	
	// Std, don't touch.
	cout << "\n" << "Press ANY key to exit program." << endl;
	cin >> pauseint;
	return 0;
}




void SetMouseFunc()
{
	bool infloop = true;
	int in_x;
	int in_y;
	
	while (infloop)
	{ 
		cout << "Mouse will also left click at X/Y location!" << endl;
		cout << "X position to set mouse to: ";
		cin >> in_x;
		cout << "Y position to set mouse to: ";
		cin >> in_y;
		cout << endl;

		SetCursorPos(in_x, in_y);
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, in_x, in_y, 0, 0);

	}
	


}


