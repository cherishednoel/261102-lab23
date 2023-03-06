#include <windows.h>
#include <stdio.h>
#include <string>

HWND textfield, input1, input2, button1, button2, button3, button4;
char buffer1[100];
char buffer2[100];

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE: {
			textfield = CreateWindow(
				"Static", "Please input two numbers", 
				WS_CHILD | WS_VISIBLE | SS_CENTER, 
				20, 10, 200, 20, hwnd, NULL, NULL, NULL 
			);
			SendMessage(textfield, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), TRUE); 
			input1 = CreateWindow(
				"Edit", "", 
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				20, 40, 200, 20, hwnd, NULL, NULL, NULL 
			);
			input2 = CreateWindow(
				"Edit", "", 
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				20, 70, 200, 20, hwnd, NULL, NULL, NULL 
			);
			button1 = CreateWindow(
				"Button", "+", 
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				20, 100, 45, 20, hwnd, (HMENU) 1, NULL, NULL 
			);
			button2 = CreateWindow(
				"Button", "-",
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				75, 100, 40, 20, hwnd, (HMENU) 2, NULL, NULL
			);
			button3 = CreateWindow(
				"Button", "*", 
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				125, 100, 40, 20, hwnd, (HMENU) 3, NULL, NULL
			);
			button4 = CreateWindow(
				"Button", "/", 
				WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 
				175, 100, 45, 20, hwnd, (HMENU) 4, NULL, NULL
			);
			break;
		}

		case WM_CTLCOLORSTATIC: {
			SetBkMode((HDC)wParam, TRANSPARENT);
			return (LRESULT)GetStockObject(HOLLOW_BRUSH);
		}

		case WM_COMMAND: {
			switch(LOWORD(wParam)) {
				case 1: {
					GetWindowText(input1, buffer1, 100);
					GetWindowText(input2, buffer2, 100);
					double a = std::stod(buffer1);
					double b = std::stod(buffer2);
					double result = a + b;
					char resultString[100];
					sprintf(resultString, "%f", result);
					MessageBox(hwnd, resultString, "Result", MB_OK);
					break;
				}
				case 2: {
					GetWindowText(input1, buffer1, 100);
					GetWindowText(input2, buffer2, 100);
					double a = std::stod(buffer1);
					double b = std::stod(buffer2);
					double result = a - b;
					char resultString[100];
					sprintf(resultString, "%f", result);
					MessageBox(hwnd, resultString, "Result", MB_OK);
					break;
				}
				case 3: {
					GetWindowText(input1, buffer1, 100);
					GetWindowText(input2, buffer2, 100);
					double a = std::stod(buffer1);
					double b = std::stod(buffer2);
					double result = a * b;
					char resultString[100];
					sprintf(resultString, "%f", result);
					MessageBox(hwnd, resultString, "Result", MB_OK);
					break;
				}
				case 4: {
					GetWindowText(input1, buffer1, 100);
					GetWindowText(input2, buffer2, 100);
					double a = std::stod(buffer1);
					double b = std::stod(buffer2);
					double result = a / b;
					char resultString[100];
					sprintf(resultString, "%f", result);
					MessageBox(hwnd, resultString, "Result", MB_OK);
					break;
				}
			}
			break;
		}
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}

		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; 
	HWND hwnd; 
	MSG msg; 

	memset(&wc,0,sizeof(wc));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc; 
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	wc.hbrBackground = CreateSolidBrush(RGB(0, 255, 213));
	wc.lpszClassName = "WindowClass";
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,CW_USEDEFAULT,CW_USEDEFAULT, 250, 200, NULL, NULL, hInstance, NULL);

	if(hwnd == NULL) {
		MessageBox(NULL,"Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg,NULL,0,0) > 0) { 
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}
	return msg.wParam;
}
