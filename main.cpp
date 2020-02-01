#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <array>
#include <ctime>
#include <string>
#include "NE.h"
#include "ES.h"
#include "SW.h"
#include "WN.h"
#include "vertical.h"
#include "horizontal.h"
#include "four_way.h"
using namespace sf;
using namespace std;
void mainPage(array<array<pipe*, 5>, 5> &);
void game_ground(array<array<pipe*, 5>, 5> &);
void about();
void fillground(array<array<pipe*, 5>, 5> &);
void deleteground(array<array<pipe*, 5>, 5> &);
void runground(array<array<pipe*, 5>, 5> &);
void insurance_answer(array<array<pipe*, 5>, 5> &);
void win();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	array<array<pipe*, 5>, 5> ground;
	fillground(ground);
	insurance_answer(ground);
	mainPage(ground);
	deleteground(ground);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fillground(array<array<pipe*, 5>, 5> &x)
{
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			int a = rand() % 7 + 1;
			if (a == 1)
			{
				x[i][j] = new four_way();
			}
			if (a == 2)
			{
				x[i][j] = new horizontal();
			}
			if (a == 3)
			{
				x[i][j] = new vertical();
			}
			if (a == 4)
			{
				x[i][j] = new NE();
			}
			if (a == 5)
			{
				x[i][j] = new ES();
			}
			if (a == 6)
			{
				x[i][j] = new SW();
			}
			if (a == 7)
			{
				x[i][j] = new WN();
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void deleteground(array<array<pipe*, 5>, 5> &x)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			delete x[i][j];
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void runground(array<array<pipe*, 5>, 5> &ground)
{

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			ground[i][j]->set_water_false();
		}

	}
	char in_out[5][5];
	in_out[0][0] = 'n';
	for (size_t k = 0; k < 25; k++)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				if (in_out[i][j] == 'n')
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						if (i != 4) { in_out[i + 1][j] = 'n'; }
						if (i != 0 && j != 0)
						{
							if (ground[i][j - 1]->get_water() == 1 && (ground[i][j - 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 4))
							{
								in_out[i][j + 1] = 'w';
							}
						}
						
						if (j != 4 && i != 0)
						{
							if (ground[i][j + 1]->get_water() == 1 && (ground[i][j + 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 6))
							{
								in_out[i][j - 1] = 'e';
							}
						}
						
					}
					if (ground[i][j]->pipe_type() == 3)
					{
						if (i != 4)
						{
							ground[i][j]->set_water_true();
							in_out[i + 1][j] = 'n';
						}

					}
					if (ground[i][j]->pipe_type() == 4)
					{
						if (j!=4)
						{
							ground[i][j]->set_water_true();
							in_out[i][j + 1] = 'w';
						}
						
					}
					if (ground[i][j]->pipe_type() == 7)
					{
						if (j != 0)
						{
							ground[i][j]->set_water_true();
							in_out[i][j - 1] = 'e';
						}
						
					}
				}
				if (in_out[i][j] == 'e')
				{
					if (ground[i][j]->pipe_type() == 2)
					{
						if (j != 0)
						{
							ground[i][j]->set_water_true();
							in_out[i][j - 1] = 'e';
						}	
					}
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						in_out[i][j - 1] = 'e';
						if (i != 0 )
						{
							if (ground[i - 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 6))
							{
								in_out[i + 1][j] = 'n';
							}
						}
						if (i != 0 && i != 4)
						{
							if (ground[i + 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 4))
							{
								in_out[i - 1][j] = 's';
							}
						}	
					}
					if (ground[i][j]->pipe_type() == 5)
					{
						if (i != 4)
						{
							ground[i][j]->set_water_true();
							in_out[i + 1][j] = 'n';
						}	
					}
					if (ground[i][j]->pipe_type() == 4)
					{
						if (i != 0)
						{
							ground[i][j]->set_water_true();
							in_out[i - 1][j] = 's';
						}
					}
				}
				if (in_out[i][j] == 'w')
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						in_out[i][j + 1] = 'w';
						if (i != 0) 
						{
							if (ground[i - 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 6))
							{
								in_out[i + 1][j] = 'n';
							}
						}
						if (i != 0 && i != 4)
						{
							if (ground[i + 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 4))
							{
								
								in_out[i - 1][j] = 's';
							}
						}
					}
					if (ground[i][j]->pipe_type() == 2)
					{
						if (j != 4)
						{
							ground[i][j]->set_water_true();
							in_out[i][j + 1] = 'w';
						}
					}
					if (ground[i][j]->pipe_type() == 6)
					{
						if (i != 4)
						{
							ground[i][j]->set_water_true();
							in_out[i + 1][j] = 'n';
						}
					}
					if (ground[i][j]->pipe_type() == 7)
					{
						if (i != 0)
						{
							ground[i][j]->set_water_true();
							in_out[i - 1][j] = 's';
						}
					}
				}
				if (in_out[i][j] == 's')
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						if(i != 0){ in_out[i - 1][j] = 's'; }
						if (j != 0 && i != 0)
						{
							if (ground[i][j - 1]->get_water() == 1 && (ground[i][j - 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 4))
							{
								in_out[i][j + 1] = 'w';
							}
						}
			
						if (j != 4 && i != 0)
						{
							if (ground[i][j + 1]->get_water() == 1 && (ground[i][j + 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 6))
							{
								in_out[i][j - 1] = 'e';
							}
						}
					}
					if (ground[i][j]->pipe_type() == 3)
					{
						if (i != 0)
						{
							ground[i][j]->set_water_true();
							in_out[i - 1][j] = 's';
						}	
					}
					if (ground[i][j]->pipe_type() == 5)
					{
						if (j != 4)
						{
							ground[i][j]->set_water_true();
							in_out[i][j + 1] = 'w';
						}
					}
					if (ground[i][j]->pipe_type() == 6)
					{
						if (j != 0)
						{
							in_out[i][j - 1] = 'e';
						}
						ground[i][j]->set_water_true();
					}
				}
			}
		}
	}
	if ((in_out[4][4] == 'w' && ground[4][4]->pipe_type() == 6) || (in_out[4][4] == 'n' && (ground[4][4]->pipe_type() == 1 || ground[4][4]->pipe_type() == 3)))
	{
		win();
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mainPage(array<array<pipe*, 5>, 5> &ground)
{
	RenderWindow window(VideoMode(314, 598), "Menu", Style::Titlebar | Style::Close);
	Texture image;
	Music music;
	if (!music.openFromFile("in_love.wav"))
	{
		cout << "music error";
	}
	if (!image.loadFromFile("home.png"))
	{
		cout << "error home image!!!";
	}
	Sprite sp(image);
	while (window.isOpen())
	{
		music.play();
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
					game_ground(ground);
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void game_ground(array<array<pipe*, 5>, 5> &ground)
{
	RenderWindow window(VideoMode(582, 582), "Game Plumber", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("gameground.png"))
	{
		std::cout << "error";
	}
	Sprite sp(image);
	int rashti=2;
	runground(ground);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						Texture pic;
						pic.loadFromFile("fourway.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 2)
					{
						Texture pic;
						pic.loadFromFile("horizental.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 3)
					{
						Texture pic;
						pic.loadFromFile("vertical.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 4)
					{
						Texture pic;
						pic.loadFromFile("ne.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 5)
					{
						Texture pic;
						pic.loadFromFile("es.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 6)
					{
						Texture pic;
						pic.loadFromFile("sw.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
					if (ground[i][j]->pipe_type() == 7)
					{
						Texture pic;
						pic.loadFromFile("wn.png");
						Sprite ss(pic);
						ss.setPosition(j * 118, i * 118);
						window.draw(ss);
					}
				}
			}
			window.display();
	
			if (event.mouseButton.button == Mouse::Left)
			{
				if ((event.mouseButton.x >= 0 && event.mouseButton.x <= 118) && (event.mouseButton.y >= 0 && event.mouseButton.y <= 118))
				{
					if (rashti % 2 ==0 )
					{
						ground[0][0]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 118 && event.mouseButton.x <= 238) && (event.mouseButton.y >= 0 && event.mouseButton.y <= 118))
				{
					
					if (rashti % 2 == 0)
					{
						ground[0][1]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 239 && event.mouseButton.x <= 356) && (event.mouseButton.y >= 0 && event.mouseButton.y <= 118))
				{

					if (rashti % 2 == 0)
					{
						ground[0][2]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 356 && event.mouseButton.x <= 474) && (event.mouseButton.y >= 0 && event.mouseButton.y <= 118))
				{

					if (rashti % 2 == 0)
					{
						ground[0][3]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 474 && event.mouseButton.x <= 592) && (event.mouseButton.y >= 0 && event.mouseButton.y <= 118))
				{

					if (rashti % 2 == 0)
					{
						ground[0][4]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 0 && event.mouseButton.x <= 118) && (event.mouseButton.y >= 118 && event.mouseButton.y <= 236))
				{

					if (rashti % 2 == 0)
					{
						ground[1][0]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 118 && event.mouseButton.x <= 236) && (event.mouseButton.y >= 118 && event.mouseButton.y <= 236))
				{

					if (rashti % 2 == 0)
					{
						ground[1][1]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 236 && event.mouseButton.x <= 354) && (event.mouseButton.y >= 118 && event.mouseButton.y <= 236))
				{

					if (rashti % 2 == 0)
					{
						ground[1][2]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 354 && event.mouseButton.x <= 474) && (event.mouseButton.y >= 118 && event.mouseButton.y <= 236))
				{

					if (rashti % 2 == 0)
					{
						ground[1][3]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 474 && event.mouseButton.x <= 592) && (event.mouseButton.y >= 118 && event.mouseButton.y <= 236))
				{

					if (rashti % 2 == 0)
					{
						ground[1][4]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 0 && event.mouseButton.x <= 118) && (event.mouseButton.y >= 236 && event.mouseButton.y <= 354))
				{

					if (rashti % 2 == 0)
					{
						ground[2][0]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 118 && event.mouseButton.x <= 236) && (event.mouseButton.y >= 236 && event.mouseButton.y <= 354))
				{

					if (rashti % 2 == 0)
					{
						ground[2][1]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 236 && event.mouseButton.x <= 354) && (event.mouseButton.y >= 236 && event.mouseButton.y <= 354))
				{

					if (rashti % 2 == 0)
					{
						ground[2][2]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 354 && event.mouseButton.x <= 474) && (event.mouseButton.y >= 236 && event.mouseButton.y <= 354))
				{

					if (rashti % 2 == 0)
					{
						ground[2][3]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 474 && event.mouseButton.x <= 592) && (event.mouseButton.y >= 236 && event.mouseButton.y <= 354))
				{

					if (rashti % 2 == 0)
					{
						ground[2][4]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 0 && event.mouseButton.x <= 118) && (event.mouseButton.y >= 354 && event.mouseButton.y <= 474))
				{

					if (rashti % 2 == 0)
					{
						ground[3][0]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 118 && event.mouseButton.x <= 236) && (event.mouseButton.y >= 354 && event.mouseButton.y <= 474))
				{

					if (rashti % 2 == 0)
					{
						ground[3][1]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 236 && event.mouseButton.x <= 354) && (event.mouseButton.y >= 354 && event.mouseButton.y <= 474))
				{

					if (rashti % 2 == 0)
					{
						ground[3][2]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 354 && event.mouseButton.x <= 474) && (event.mouseButton.y >= 354 && event.mouseButton.y <= 474))
				{

					if (rashti % 2 == 0)
					{
						ground[3][3]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 474 && event.mouseButton.x <= 592) && (event.mouseButton.y >= 354 && event.mouseButton.y <= 474))
				{

					if (rashti % 2 == 0)
					{
						ground[3][4]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 0 && event.mouseButton.x <= 118) && (event.mouseButton.y >= 474 && event.mouseButton.y <= 592))
				{

					if (rashti % 2 == 0)
					{
						ground[4][0]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 118 && event.mouseButton.x <= 236) && (event.mouseButton.y >= 474 && event.mouseButton.y <= 592))
				{

					if (rashti % 2 == 0)
					{
						ground[4][1]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 236 && event.mouseButton.x <= 354) && (event.mouseButton.y >= 474 && event.mouseButton.y <= 592))
				{

					if (rashti % 2 == 0)
					{
						ground[4][2]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 354 && event.mouseButton.x <= 474) && (event.mouseButton.y >= 474 && event.mouseButton.y <= 592))
				{

					if (rashti % 2 == 0)
					{
						ground[4][3]->rotate();
						runground(ground);
					}
					rashti++;
				}
				if ((event.mouseButton.x >= 474 && event.mouseButton.x <= 592) && (event.mouseButton.y >= 474 && event.mouseButton.y <= 592))
				{

					if (rashti % 2 == 0)
					{
						ground[4][4]->rotate();
						runground(ground);
					}
					rashti++;
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void win()
{
	RenderWindow window(VideoMode(805, 493), "About", Style::Titlebar | Style::Close);
	Texture image;
	if (!image.loadFromFile("win.png"))
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void insurance_answer(array<array<pipe*, 5>, 5> &ground)
{
	srand((unsigned)time(NULL));
	int i = rand() % 5 + 1;
	if (i == 1)
	{
		ground[0][0] = new ES();
		ground[0][1] = new horizontal();
		ground[0][2] = new ES();
		ground[1][2] = new four_way();
		ground[2][2] = new vertical();
		ground[3][2] = new SW();
		ground[3][1] = new SW();
		ground[2][1] = new vertical();
		ground[1][1] = new ES();
		ground[1][3] = new SW();
		ground[2][3] = new SW();
		ground[2][4] = new SW();
		ground[3][4] = new horizontal();
		ground[4][4] = new horizontal();
	}
	if (i == 2)
	{
		ground[0][0] = new NE();
		ground[0][1] = new vertical();
		ground[0][2] = new horizontal();
		ground[0][3] = new four_way();
		ground[0][4] = new ES();
		ground[1][4] = new four_way();
		ground[2][4] = new vertical();
		ground[3][4] = new four_way();
		ground[4][4] = new four_way();
	}
	if (i == 3)
	{
		ground[0][0] = new four_way();
		ground[1][0] = new horizontal();
		ground[2][0] = new SW();
		ground[2][1] = new vertical();
		ground[2][2] = new WN();
		ground[1][2] = new ES();
		ground[1][3] = new horizontal();
		ground[1][4] = new WN();
		ground[2][4] = new WN();
		ground[2][3] = new ES();
		ground[3][3] = new SW();
		ground[3][4] = new WN();
		ground[4][4] = new horizontal();
	}
	if (i == 4)
	{
		ground[0][0] = new horizontal();
		ground[1][0] = new WN();
		ground[1][1] = new SW();
		ground[2][1] = new vertical();
		ground[3][1] = new horizontal();
		ground[4][1] = new ES();
		ground[4][2] = new SW();
		ground[3][2] = new four_way();
		ground[2][2] = new horizontal();
		ground[1][2] = new SW();
		ground[1][3] = new NE();
		ground[2][3] = new NE();
		ground[2][4] = new WN();
		ground[3][4] = new four_way();
		ground[4][4] = new four_way();
	}
	if (i == 5)
	{
		ground[0][0] = new ES();
		ground[0][1] = new vertical();
		ground[0][2] = new horizontal();
		ground[0][3] = new NE();
		ground[1][3] = new ES();
		ground[1][2] = new horizontal();
		ground[1][1] = new four_way();
		ground[1][0] = new ES();
		ground[2][0] = new horizontal();
		ground[3][0] = new NE();
		ground[3][1] = new horizontal();
		ground[3][2] = new vertical();
		ground[3][3] = new SW();
		ground[2][3] = new ES();
		ground[2][4] = new WN();
		ground[3][4] = new four_way();
		ground[4][4] = new vertical();
	}
}



