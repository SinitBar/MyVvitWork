#include <SFML/Graphics.hpp> // для графических фигур
#include <iostream> 
#include <conio.h> // для _getch
#include <windows.h> // для SetConsoleCP()
using namespace std;
using namespace sf;
double lessCoordinate = 0.25, moreCoordinate = 0.75; // коэффициенты для координат точек линии
RenderWindow window(VideoMode(640, 480), L"Простые фигуры"); //создаем окно 640х480  с заголовком
// задаем параметры линии
VertexArray line(Lines, 2 /*количество точек*/); // создаем массив из двух точек
void DrawLine(int x1, int y1, int x2, int y2, VertexArray line, RenderWindow &window)
{
	line[0].position = Vector2f(x1, y1); // позиция начала линии: X, Y (центр)
	line[1].position = Vector2f(x2, y2); // позиция конца линии: X, Y (низ экрана)
	window.draw(line); // вывод линии в буфер
}
void DrawRectangle(int width, int height, VertexArray line, RenderWindow& window)
{
	//// начинаем рисовать прямоугольник с длинами сторон = половине экрана, расположенный в центре
	DrawLine(width * lessCoordinate, height * lessCoordinate, width * moreCoordinate, height * lessCoordinate, line, window); // верхняя сторона
	DrawLine(width * moreCoordinate, height * lessCoordinate, width * moreCoordinate, height * moreCoordinate, line, window); // правая сторона
	DrawLine(width * lessCoordinate, height * moreCoordinate, width * moreCoordinate, height * moreCoordinate, line, window); // нижняя сторона
	DrawLine(width * lessCoordinate, height * lessCoordinate, width * lessCoordinate, height * moreCoordinate, line, window); // левая сторона
    //// закончили рисовать прямоугольник
}
void EndOnTheUpLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int xi = width * lessCoordinate; xi < width * moreCoordinate; xi++) // проходит по верхней
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(xi, height * lessCoordinate); // позиция конца линии: X, Y (низ экрана)
		window.draw(line); // вывод линии в буфер
		sleep(milliseconds(time));
		window.display(); // буфер отображается на экране
		window.clear();
	}
}
void EndOnTheRightLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int yi = height * lessCoordinate; yi < height * moreCoordinate; yi++) // проходит по правой
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(width * moreCoordinate, yi); // позиция конца линии: X, Y (низ экрана)
		window.draw(line); // вывод линии в буфер
		sleep(milliseconds(time));
		window.display(); // буфер отображается на экране
		window.clear();
	}
}
void EndOnTheDownLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int xi = width * moreCoordinate - 1; xi >= width * lessCoordinate; xi--) // проходит по нижней
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(xi, height * moreCoordinate); // позиция конца линии: X, Y (низ экрана)
		window.draw(line); // вывод линии в буфер
		sleep(milliseconds(time));
		window.display(); // буфер отображается на экране
		window.clear();
	}
}
void EndOnTheLeftLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int yi = height * moreCoordinate - 1; yi >= height * lessCoordinate; yi--) // проходит по левой
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(width * lessCoordinate, yi); // позиция конца линии: X, Y (низ экрана)
		window.draw(line); // вывод линии в буфер
		sleep(milliseconds(time));
		window.display(); // буфер отображается на экране
		window.clear();
	}
}
int main()
{
	SetConsoleCP(1251); //разрешить русский текст в потоке ввода
	SetConsoleOutputCP(1251); //разрешить русский текст в потоке вывода
	int time = 10; // время в миллисекундах - влияет на скорость движения линии
	Vector2u size = window.getSize(); // получение вектора размера текущего окна (x, y)
	unsigned int width = size.x, height = size.y; // ширина и высота окна соответственно
	window.clear(); // очистка окна
	// начинается рисование линий
	line[0].color = Color::White; // цвет начала линии
	line[1].color = Color::Blue; // цвет конца линии
	line[0].position = Vector2f(width / 2, height / 2); // позиция начала линии: X, Y (центр)
	//xi, yi - вспомогательные координаты по x и по y - для обозначений начала и конца текущей линии
	EndOnTheUpLine(time, width, height, line, window);
	EndOnTheRightLine(time, width, height, line, window);
	EndOnTheDownLine(time, width, height, line, window);
	EndOnTheLeftLine(time, width, height, line, window);
	window.close();
	return 0;
}