//Include the necessary libraries 
#include <iostream> 
#include <windows.h> 

//Define constants for setting the window position 
const int WINDOW_WIDTH = 500; 
const int WINDOW_HEIGHT = 250; 

//Main function of the program 
int main() 
{ 
        //Declare a HWND handle 
        HWND lockDownBrowserWindow; 
  
        //Find the handle of the LockDown Browser to keep it on top 
        lockDownBrowserWindow = FindWindow(NULL, "LockDown Browser"); 
  
        //If LockDown Browser is running, move it to the front 
        if (lockDownBrowserWindow) 
        { 
                //Move the window to the top left corner 
                MoveWindow(lockDownBrowserWindow, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, TRUE); 
  
                //Set it to stay on top of other windows 
                SetWindowPos(lockDownBrowserWindow, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); 
        } 
        //If LockDown Browser is not running, display an error message 
        else 
        { 
                MessageBox(NULL, "LockDown Browser is not running!", "Error", MB_OK); 
                return 0; 
        } 
  
        //Stay in an infinite loop to maintain the browser on top of other windows 
        while (true) 
        { 
                Sleep(1000); 
        } 
  
        return 0; 
}