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

void mainPage();
void game_ground();
void about();
//void fillground(array<array<pipe*, 5>, 5> &);
//void deleteground(array<array<pipe*, 5>, 5> &);
//void runground(array<array<pipe*, 5>, 5> &);

int main()
{
	array<array<pipe*, 5>, 5> ground;
	//fillground(ground);
	ground[0][0] = new NE();
	ground[0][1] = new horizontal();
	ground[0][2] = new SW();
	ground[1][2] = new four_way();
	ground[2][2] = new WN();
	ground[2][1] = new NE();
	ground[1][1] = new ES();
	ground[1][3] = new horizontal();
	ground[1][4] = new SW();
	ground[2][4] = new WN();
	ground[2][3] = new ES();
	ground[3][3] = new NE();
	ground[3][4] = new SW();
	ground[4][4] = new vertical();

	/*ground[0][0]= new vertical();
	ground[1][0]= new four_way();
	ground[2][0]= new vertical();
	ground[3][0]= new vertical();
	ground[4][0]= new NE();
	ground[4][1]= new horizontal;
	ground[4][2]= new four_way();
	ground[4][3]= new four_way();
	ground[4][4]= new SW(); wiiiiin */

	//runground(ground);

	//cout<<ground[0][3]->get_water()<<endl;
	//cout<<ground[1][4]->get_water()<<endl;
	//cout<<ground[0][4]->get_water()<<endl;
	//cout<<ground[1][3]->get_water()<<endl;
	//cout<<ground[1][1]->get_water()<<endl;





	//deleteground(ground);
	mainPage();
	return 0;
}

/*void fillground(array<array<pipe*, 5>, 5> &x)
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
						in_out[i + 1][j] = 'n';
						if (ground[i][j - 1]->get_water() == 1 && (ground[i][j - 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 4))
						{
							in_out[i][j + 1] = 'w';
						}
						if (ground[i][j + 1]->get_water() == 1 && (ground[i][j + 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 6))
						{
							in_out[i][j - 1] = 'e';
						}
					}
					if (ground[i][j]->pipe_type() == 3)
					{
						ground[i][j]->set_water_true();
						in_out[i + 1][j] = 'n';
					}
					if (ground[i][j]->pipe_type() == 4)
					{
						ground[i][j]->set_water_true();
						in_out[i][j + 1] = 'w';
					}
					if (ground[i][j]->pipe_type() == 7)
					{
						ground[i][j]->set_water_true();
						in_out[i][j - 1] = 'e';
					}
				}
				if (in_out[i][j] == 'e')
				{
					if (ground[i][j]->pipe_type() == 2)
					{
						ground[i][j]->set_water_true();
						in_out[i][j - 1] = 'e';

					}
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						in_out[i][j - 1] = 'e';
						if (ground[i - 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 6))
						{
							in_out[i + 1][j] = 'n';
						}
						if (ground[i + 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 4))
						{
							in_out[i - 1][j] = 's';
						}
					}
					if (ground[i][j]->pipe_type() == 5)
					{
						ground[i][j]->set_water_true();
						in_out[i + 1][j] = 'n';
					}
					if (ground[i][j]->pipe_type() == 4)
					{
						ground[i][j]->set_water_true();
						in_out[i - 1][j] = 's';
					}
				}
				if (in_out[i][j] == 'w')
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						in_out[i][j + 1] = 'w';
						if (ground[i - 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 6))
						{
							in_out[i + 1][j] = 'n';
						}
						if (ground[i + 1][j]->get_water() == 1 && (ground[i - 1][j]->pipe_type() == 3 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 4))
						{
							in_out[i - 1][j] = 's';
						}
					}
					if (ground[i][j]->pipe_type() == 2)
					{
						ground[i][j]->set_water_true();
						in_out[i][j + 1] = 'w';
					}
					if (ground[i][j]->pipe_type() == 6)
					{
						ground[i][j]->set_water_true();
						in_out[i + 1][j] = 'n';
					}
					if (ground[i][j]->pipe_type() == 7)
					{
						ground[i][j]->set_water_true();
						in_out[i - 1][j] = 's';
					}

				}
				if (in_out[i][j] == 's')
				{
					if (ground[i][j]->pipe_type() == 1)
					{
						ground[i][j]->set_water_true();
						in_out[i - 1][j] = 's';
						if (ground[i][j - 1]->get_water() == 1 && (ground[i][j - 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 5 || ground[i - 1][j]->pipe_type() == 4))
						{
							in_out[i][j + 1] = 'w';
						}
						if (ground[i][j + 1]->get_water() == 1 && (ground[i][j + 1]->pipe_type() == 2 || ground[i - 1][j]->pipe_type() == 7 || ground[i - 1][j]->pipe_type() == 6))
						{
							in_out[i][j - 1] = 'e';
						}
					}
					if (ground[i][j]->pipe_type() == 3)
					{
						ground[i][j]->set_water_true();
						in_out[i - 1][j] = 's';

					}
					if (ground[i][j]->pipe_type() == 5)
					{
						ground[i][j]->set_water_true();
						in_out[i][j + 1] = 'w';
					}
					if (ground[i][j]->pipe_type() == 6)
					{
						ground[i][j]->set_water_true();
						in_out[i][j - 1] = 'e';
					}

				}
			}
		}
	}





	//cout<<"is: "<<in_out[1][3]<<endl;

	if ((in_out[4][4] == 'w' && ground[4][4]->pipe_type() == 6) || (in_out[4][4] == 'n' && (ground[4][4]->pipe_type() == 1 || ground[4][4]->pipe_type() == 3)))
	{
		cout << endl << "wwwwwwiiiiiiiiiiiiiiinnnnnnnnnnn" << endl;
	}




}*/







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
	Texture image2;
	
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

