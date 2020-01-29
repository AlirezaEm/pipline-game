#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace sf;

void mainPage();
void game_ground();
void about();

int main()
{
	mainPage();
	return 0;
}

void mainPage()
{
	RenderWindow window(VideoMode(314, 598), "Menu", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("home.png"))
	{
		std::cout << "error";
	}

	Sprite sp(image);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (event.mouseButton.button == Mouse::Left)
			{
				if ((event.mouseButton.x >= 40 && event.mouseButton.x <= 270) && (event.mouseButton.y >= 90 && event.mouseButton.y <= 205))
				{
					game_ground();
					
				}

				if ((event.mouseButton.x >= 42 && event.mouseButton.x <= 270) && (event.mouseButton.y >= 250 && event.mouseButton.y <= 365))
				{
					about();
				}
				if ((event.mouseButton.x >= 42 && event.mouseButton.x <= 270) && (event.mouseButton.y >= 414 && event.mouseButton.y <= 532))
				{
					window.close();
				}
			}

		}

		window.clear();
		window.draw(sp);
		window.display();

	}

}
void game_ground()
{
	RenderWindow window(VideoMode(582, 582), "Game Plumber", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("gameground.png"))
	{
		std::cout << "error";
	}

	Sprite sp(image);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}

		

		}

		window.clear();
		window.draw(sp);
		window.display();

	}

}
void about()
{
	RenderWindow window(VideoMode(396, 398), "About", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("about.png"))
	{
		std::cout << "error";
	}

	Sprite sp(image);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}



		}

		window.clear();
		window.draw(sp);
		window.display();

	}

}

