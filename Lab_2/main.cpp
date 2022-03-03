#include"Header.h"
void Format()
{
	for (;;)
	{
		switch (getch()) {
		case 72:
			std::cout << "\nup";
			break;
		case 80:
			std::cout << "\ndown";
			break;
		case 75:
			std::cout << "\nleft";
			break;
		case 77:
			std::cout << "\nright";
			break;
		}
	}
}



int main()
{
	//POINT
	int x, y,speed;
	std::cout << "Enter M: \n";
	cout << "Enter x: ";
	std::cin >> x;
	cout << "Enter y: ";
	std::cin >> y;
	cout << "Enter speed: ";
	std::cin >> speed;
	Point M(x,y,speed);
	std::cout << "M: ";
	M.show();
	Point N(2, 2, 1);
	//Segment s(M, N);
	//SEGMENT

	return 0;
}