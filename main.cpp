#include <SFML/Graphics.hpp>
#include <iostream>
#include "Textures.h"

int main()
{
	using namespace sf;
	using namespace std;
	RenderWindow window;
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

	bool bFilled[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	bool bMenudebounce = false;
	int iTurns = 1;

	Sprite sPlaceholder;
	Sprite sBoard[9];
	Sprite sBackground;
	Sprite sMenu;
	sBackground.setTexture(tBoard);
	sMenu.setTexture(tMenu);
	// main loop
	while (window.isOpen())
	{
		if (iTurns % 2 == 0){
			sPlaceholder.setTexture(tGreenpepper);
		}
		else{
			sPlaceholder.setTexture(tRedpepper);
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
				case Keyboard::Return:
					bMenudebounce = true;
					break;
				case Keyboard::Numpad1:
					if (bFilled[0] == false && bMenudebounce == true){
						bFilled[0] = true;
						sBoard[0] = sPlaceholder;
						sBoard[0].setPosition(10, 405);
						iTurns++;
					}
						break;
				case Keyboard::Numpad2:
					if (bFilled[1] == false && bMenudebounce == true){
						bFilled[1] = true;
						sBoard[1] = sPlaceholder;
						sBoard[1].setPosition(270, 407);
						iTurns++;
					}
						break;
				case Keyboard::Numpad3:
					if (bFilled[2] == false && bMenudebounce == true){
						bFilled[2] = true;
						sBoard[2] = sPlaceholder;
						sBoard[2].setPosition(548, 407);
						iTurns++;
					}
						break;
				case Keyboard::Numpad4:
					if (bFilled[3] == false && bMenudebounce == true){
						bFilled[3] = true;
						sBoard[3] = sPlaceholder;
						sBoard[3].setPosition(10, 205);
						iTurns++;
					}
						break;
				case Keyboard::Numpad5:
					if (bFilled[4] == false && bMenudebounce == true){
						bFilled[4] = true;
						sBoard[4] = sPlaceholder;
						sBoard[4].setPosition(270, 207);
						iTurns++;
					}
						break;
				case Keyboard::Numpad6:
					if (bFilled[5] == false && bMenudebounce == true){
						bFilled[5] = true;
						sBoard[5] = sPlaceholder;
						sBoard[5].setPosition(548, 207);
						iTurns++;
					}
						break;
				case Keyboard::Numpad7:
					if (bFilled[6] == false && bMenudebounce == true){
						bFilled[6] = true;
						sBoard[6] = sPlaceholder;
						sBoard[6].setPosition(10, 10);
						iTurns++;
					}
						break;
				case Keyboard::Numpad8:
					if (bFilled[7] == false && bMenudebounce == true){
						bFilled[7] = true;
						sBoard[7] = sPlaceholder;
						sBoard[7].setPosition(270, 10);
						iTurns++;
					}
						break;
				case Keyboard::Numpad9:
					if (bFilled[8] == false && bMenudebounce == true){
						bFilled[8] = true;
						sBoard[8] = sPlaceholder;
						sBoard[8].setPosition(548, 10);
						iTurns++;
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

		}
			window.display();
	}
	return 0;
}