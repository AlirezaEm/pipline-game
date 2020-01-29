#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
using namespace sf;

void mainPage();

int main()
{
	mainPage();
	return 0;
}

void mainPage()
{
	RenderWindow window(VideoMode(1280, 891), "Game Plumber", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("BGP.PNG"))
	{
		return;
	}
	Sprite sp(image);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					window.close();
				break;
			}

		}

		window.clear();
		window.draw(sp);
		window.display();

	}

}