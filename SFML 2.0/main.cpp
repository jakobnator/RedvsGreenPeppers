#include <SFML/Graphics.hpp>
#include <iostream>
#include "Textures.h"


using namespace sf;
using namespace std;

int iFilled[9] = { 0 }; //0 unfilled, 1 green , 2 red
bool bWin = false;

RectangleShape winLine(Vector2f(770, 20));



void checkWin()
{
	if (iFilled[0] == 1 && iFilled[1] == 1 && iFilled[2] == 1) {
		bWin = true;
		winLine.setPosition(12, 500);
	}
	else
	if (iFilled[3] == 1 && iFilled[4] == 1 && iFilled[5] == 1) {
		bWin = true;
		winLine.setPosition(12, 300);
	}
	else
	if (iFilled[6] == 1 && iFilled[7] == 1 && iFilled[8] == 1) {
		bWin = true;
		winLine.setPosition(12, 100);
	}
	else
	if (iFilled[0] == 1 && iFilled[3] == 1 && iFilled[6] == 1) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(150, 10);
	}
	else
	if (iFilled[1] == 1 && iFilled[4] == 1 && iFilled[7] == 1) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(400, 10);
	}
	else
	if (iFilled[2] == 1 && iFilled[5] == 1 && iFilled[8] == 1) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(700, 10);
	}
	else
	if (iFilled[0] == 1 && iFilled[4] == 1 && iFilled[8] == 1) {
		bWin = true;
		winLine.setRotation(-40);
		winLine.setPosition(100, 550);
	}
	else
	if (iFilled[2] == 1 && iFilled[4] == 1 && iFilled[6] == 1) {
		bWin = true;
		winLine.setRotation(220);
		winLine.setPosition(700, 550);
	}
	if (iFilled[0] == 2 && iFilled[1] == 2 && iFilled[2] == 2) {
		bWin = true;
		winLine.setPosition(12, 500);
	}
	else
	if (iFilled[3] == 2 && iFilled[4] == 2 && iFilled[5] == 2) {
		bWin = true;
		winLine.setPosition(12, 300);
	}
	else
	if (iFilled[6] == 2 && iFilled[7] == 2 && iFilled[8] == 2) {
		bWin = true;
		winLine.setPosition(12, 100);
	}
	else
	if (iFilled[0] == 2 && iFilled[3] == 2 && iFilled[6] == 2) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(150, 10);
	}
	else
	if (iFilled[1] == 2 && iFilled[4] == 2 && iFilled[7] == 2) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(400, 10);
	}
	else
	if (iFilled[2] == 2 && iFilled[5] == 2 && iFilled[8] == 2) {
		bWin = true;
		winLine.setRotation(90);
		winLine.setPosition(700, 10);
	}
	else
	if (iFilled[0] == 2 && iFilled[4] == 2 && iFilled[8] == 2) {
		bWin = true;
		winLine.setRotation(-40);
		winLine.setPosition(100, 550);
	}
	else
	if (iFilled[2] == 2 && iFilled[4] == 2 && iFilled[6] == 2) {
		bWin = true;
		winLine.setRotation(220);
		winLine.setPosition(700, 550);
	}
}



int main()
{
	RenderWindow window;
	winLine.setFillColor(Color(255, 215, 0));
	window.create(VideoMode(800, 600), "Red vs. Green Peppers", Style::Close);

	Texture tGreenpepper;
	if (tGreenpepper.loadFromFile("Assets/Greenpepper.png"))
		cout << "Loaded Greenpepper.png" << endl;

	Texture tRedpepper;
	if (tRedpepper.loadFromFile("Assets/Redpepper.png"))
		cout << "Loaded Redpepper.png" << endl;

	Texture tBoard;
	if (tBoard.loadFromFile("Assets/Board.png"))
		cout << "Loaded Board.png" << endl;

	Texture tMenu;
	if (tMenu.loadFromFile("Assets/Menu.png"))
		cout << "Loaded Menu.png" << endl;


	bool bMenudebounce = false;
	int iTurns = 2;
	bool bCurrentturn; //false green, true red

	Sprite sEmpty;
	Sprite sPlaceholder;
	Sprite sBoard[9];
	Sprite sBackground;
	Sprite sMenu;
	sBackground.setTexture(tBoard);
	sMenu.setTexture(tMenu);

	// main loop
	while (window.isOpen())
	{
		checkWin();

		if (iTurns % 2 == 0){
			sPlaceholder.setTexture(tGreenpepper);
			bCurrentturn = false;
		}
		else{
			sPlaceholder.setTexture(tRedpepper);
			bCurrentturn = true;
		}
		Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyReleased:
				switch (Event.key.code)
				{
				case Keyboard::Escape:
					bMenudebounce = false;
					bWin = false;
					iTurns = 2;
					sBoard[0] = sEmpty;
					sBoard[1] = sEmpty;
					sBoard[2] = sEmpty;
					sBoard[3] = sEmpty;
					sBoard[4] = sEmpty;
					sBoard[5] = sEmpty;
					sBoard[6] = sEmpty;
					sBoard[7] = sEmpty;
					sBoard[8] = sEmpty;
					memset(iFilled, 0, sizeof(iFilled));
					break;
				case Keyboard::Return:
					bMenudebounce = true;
					break;
				case Keyboard::Numpad1:
					if (iFilled[0] == false && bMenudebounce == true && bWin == false){
						sBoard[0] = sPlaceholder;
						sBoard[0].setPosition(10, 405);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[0] = 1;
						else
							iFilled[0] = 2;
					}
						break;
				case Keyboard::Numpad2:
					if (iFilled[1] == false && bMenudebounce == true && bWin == false){
						sBoard[1] = sPlaceholder;
						sBoard[1].setPosition(270, 407);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[1] = 1;
						else
							iFilled[1] = 2;
					}
						break;
				case Keyboard::Numpad3:
					if (iFilled[2] == false && bMenudebounce == true && bWin == false){
						sBoard[2] = sPlaceholder;
						sBoard[2].setPosition(548, 407);
						iTurns++; 
						if (bCurrentturn == false)
							iFilled[2] = 1;
						else
							iFilled[2] = 2;
					}
						break;
				case Keyboard::Numpad4:
					if (iFilled[3] == false && bMenudebounce == true && bWin == false){
						sBoard[3] = sPlaceholder;
						sBoard[3].setPosition(10, 205);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[3] = 1;
						else
							iFilled[3] = 2;
						
					}
						break;
				case Keyboard::Numpad5:
					if (iFilled[4] == false && bMenudebounce == true && bWin == false){
						sBoard[4] = sPlaceholder;
						sBoard[4].setPosition(270, 207);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[4] = 1;
						else
							iFilled[4] = 2;
					}
						break;
				case Keyboard::Numpad6:
					if (iFilled[5] == false && bMenudebounce == true && bWin == false){
						sBoard[5] = sPlaceholder;
						sBoard[5].setPosition(548, 207);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[5] = 1;
						else
							iFilled[5] = 2;
					}
						break;
				case Keyboard::Numpad7:
					if (iFilled[6] == false && bMenudebounce == true && bWin == false){
						sBoard[6] = sPlaceholder;
						sBoard[6].setPosition(10, 10);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[6] = 1;
						else
							iFilled[6] = 2;
					}
						break;
				case Keyboard::Numpad8:
					if (iFilled[7] == false && bMenudebounce == true && bWin == false){
						sBoard[7] = sPlaceholder;
						sBoard[7].setPosition(270, 10);
						iTurns++;
						if (bCurrentturn == false)
							iFilled[7] = 1;
						else
							iFilled[7] = 2;
					}
						break;
				case Keyboard::Numpad9:
					if (iFilled[8] == false && bMenudebounce == true && bWin == false){
						sBoard[8] = sPlaceholder;
						sBoard[8].setPosition(548,10);
						iTurns++;
						if (bCurrentturn == false)
 							iFilled[8] = 1;
						else
							iFilled[8] = 2;
					}
						break;
				default:
					break;
				}
			}
		}
		if (bMenudebounce == false){
			window.draw(sMenu);
		}

		if (bMenudebounce == true){
			window.draw(sBackground);
			window.draw(sBoard[0]);
			window.draw(sBoard[1]);
			window.draw(sBoard[2]);
			window.draw(sBoard[3]);
			window.draw(sBoard[4]);
			window.draw(sBoard[5]);
			window.draw(sBoard[6]);
			window.draw(sBoard[7]);
			window.draw(sBoard[8]);
			if (bWin == true)
				window.draw(winLine);
		}
			window.display();
	}
	return 0;
}
