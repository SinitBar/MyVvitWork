#include <SFML/Graphics.hpp> // ��� ����������� �����
#include <iostream> 
#include <conio.h> // ��� _getch
#include <windows.h> // ��� SetConsoleCP()
using namespace std;
using namespace sf;
double lessCoordinate = 0.25, moreCoordinate = 0.75; // ������������ ��� ��������� ����� �����
RenderWindow window(VideoMode(640, 480), L"������� ������"); //������� ���� 640�480  � ����������
// ������ ��������� �����
VertexArray line(Lines, 2 /*���������� �����*/); // ������� ������ �� ���� �����
void DrawLine(int x1, int y1, int x2, int y2, VertexArray line, RenderWindow &window)
{
	line[0].position = Vector2f(x1, y1); // ������� ������ �����: X, Y (�����)
	line[1].position = Vector2f(x2, y2); // ������� ����� �����: X, Y (��� ������)
	window.draw(line); // ����� ����� � �����
}
void DrawRectangle(int width, int height, VertexArray line, RenderWindow& window)
{
	//// �������� �������� ������������� � ������� ������ = �������� ������, ������������� � ������
	DrawLine(width * lessCoordinate, height * lessCoordinate, width * moreCoordinate, height * lessCoordinate, line, window); // ������� �������
	DrawLine(width * moreCoordinate, height * lessCoordinate, width * moreCoordinate, height * moreCoordinate, line, window); // ������ �������
	DrawLine(width * lessCoordinate, height * moreCoordinate, width * moreCoordinate, height * moreCoordinate, line, window); // ������ �������
	DrawLine(width * lessCoordinate, height * lessCoordinate, width * lessCoordinate, height * moreCoordinate, line, window); // ����� �������
    //// ��������� �������� �������������
}
void EndOnTheUpLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int xi = width * lessCoordinate; xi < width * moreCoordinate; xi++) // �������� �� �������
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(xi, height * lessCoordinate); // ������� ����� �����: X, Y (��� ������)
		window.draw(line); // ����� ����� � �����
		sleep(milliseconds(time));
		window.display(); // ����� ������������ �� ������
		window.clear();
	}
}
void EndOnTheRightLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int yi = height * lessCoordinate; yi < height * moreCoordinate; yi++) // �������� �� ������
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(width * moreCoordinate, yi); // ������� ����� �����: X, Y (��� ������)
		window.draw(line); // ����� ����� � �����
		sleep(milliseconds(time));
		window.display(); // ����� ������������ �� ������
		window.clear();
	}
}
void EndOnTheDownLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int xi = width * moreCoordinate - 1; xi >= width * lessCoordinate; xi--) // �������� �� ������
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(xi, height * moreCoordinate); // ������� ����� �����: X, Y (��� ������)
		window.draw(line); // ����� ����� � �����
		sleep(milliseconds(time));
		window.display(); // ����� ������������ �� ������
		window.clear();
	}
}
void EndOnTheLeftLine(int time, int width, int height, VertexArray line, RenderWindow& window)
{
	for (int yi = height * moreCoordinate - 1; yi >= height * lessCoordinate; yi--) // �������� �� �����
	{
		DrawRectangle(width, height, line, window);
		line[1].position = Vector2f(width * lessCoordinate, yi); // ������� ����� �����: X, Y (��� ������)
		window.draw(line); // ����� ����� � �����
		sleep(milliseconds(time));
		window.display(); // ����� ������������ �� ������
		window.clear();
	}
}
int main()
{
	SetConsoleCP(1251); //��������� ������� ����� � ������ �����
	SetConsoleOutputCP(1251); //��������� ������� ����� � ������ ������
	int time = 10; // ����� � ������������� - ������ �� �������� �������� �����
	Vector2u size = window.getSize(); // ��������� ������� ������� �������� ���� (x, y)
	unsigned int width = size.x, height = size.y; // ������ � ������ ���� ��������������
	window.clear(); // ������� ����
	// ���������� ��������� �����
	line[0].color = Color::White; // ���� ������ �����
	line[1].color = Color::Blue; // ���� ����� �����
	line[0].position = Vector2f(width / 2, height / 2); // ������� ������ �����: X, Y (�����)
	//xi, yi - ��������������� ���������� �� x � �� y - ��� ����������� ������ � ����� ������� �����
	EndOnTheUpLine(time, width, height, line, window);
	EndOnTheRightLine(time, width, height, line, window);
	EndOnTheDownLine(time, width, height, line, window);
	EndOnTheLeftLine(time, width, height, line, window);
	window.close();
	return 0;
}