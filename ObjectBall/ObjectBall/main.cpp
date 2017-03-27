#include <iostream>
#include <string>

using namespace std;

class Ball
{
private:
	string m_color;
	double m_radius;
public:
	Ball(string color = "black", double radius = 10.0)
		:m_color(color), m_radius(radius) {}
	Ball(double radius) :Ball("black", radius) {}
	void print()
	{
		cout << "color: " << m_color << ", radius: " << m_radius << endl;
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	system("pause");
	return 0;
}