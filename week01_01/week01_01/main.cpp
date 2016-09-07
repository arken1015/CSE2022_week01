//first function
#include <iostream>
#include <fstream>

class my_variables
{
public:
	int a;
	int b;

	void print()
	{
		printf_s("%d %d\n", a, b);
	}
};

std::ostream &operator << (std::ostream &stream, my_variables obj)
{
	stream << obj.a << " " << obj.b << std::endl;

	return stream;
}

void main()
{
	my_variables val;

	val.a = 1;
	val.b = 2;

	FILE *of = fopen(".\cstyle.txt", "w");

	fprintf_s(of, "%d %d", val.a, val.b);

	fclose(of);

	std::ofstream ofile(".\cppstyle.txt");
	ofile << val << std::endl;

	//val.print();

	//std::cout << val << std::endl;

	//printf_s("hello, world!\n");
	//std::cout << "this is c++ style!\n" << std::endl;
}