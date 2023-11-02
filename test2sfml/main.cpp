#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#define W 800
#define H 600
using namespace sf;

void print(int& p1, int& i, float& c, int& scal,int& x0, int& y0, RenderWindow* window, CircleShape& point,float& q1, float& l1, float& q2, float& l2)
{
	float x = p1 + i / c;//делает график плотнее

	float y = (q2*sin((q1*x)+l1))+l2;//q2 растягивает
	//q1 сжимает а l1 l2 двигают по горизантали и вертикали

	float x1 = x0 + x * scal;
	float y1 = y0 - y * scal;

	point.setPosition(x1, y1);
	window->draw(point);
}


int main()
{
	float q1, l1, q2, l2;
	std::cout << "Dlya operaciy nad grafikom\n";
	std::cout << "q1 defolt 1\n";
	std::cin >> q1;
	std::cout << "l1 defolt 0\n";
	std::cin >> l1;
	std::cout << "q2 defolt 1\n";
	std::cin >> q2;
	std::cout << "l2 defolt 0\n";
	std::cin >> l2;
	VideoMode sz(W,H);
	RenderWindow* window=new RenderWindow(sz,"Grafik");


	int x0 = (W / 2)-100;//немного сдвинутая
	int y0 = H / 2;

	CircleShape point(1.f);
	point.setFillColor(Color::Green);

	int p1 = -10;//начальные промежутки
	int p2 = 10;
	float c = 100;//для плотности между точками
	int prom = (((p1) * (-1) + p2) * c + 1000);//количество точек
	int scal = 30;//масштабирование


	RectangleShape* OsX=new RectangleShape(Vector2f(W, 1));
	OsX->setFillColor(Color::Blue);
	OsX->setPosition(0, y0);

	RectangleShape* OsY=new RectangleShape(Vector2f(1, H));
	OsY->setFillColor(Color::Blue);
	OsY->setPosition(x0, 0);



	int anim = 0;// скорость анимации

	while (window->isOpen() and window!=NULL)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		if (anim < prom)
			anim += 5;

		window->clear(Color::Black);
		window->draw(*OsX);
		window->draw(*OsY);

		for (int i = 0; i < anim; i++) {
			print(p1, i, c, scal, x0, y0, window,point,q1,l1,q2,l2);

		}
		window->display();
	}
	delete window;
	delete OsX;
	delete OsY;



	return 0;
}
