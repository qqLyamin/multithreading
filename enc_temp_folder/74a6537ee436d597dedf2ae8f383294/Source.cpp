#include <iostream>

#include <thread>

#include <chrono>


void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID ������ : " << std::this_thread::get_id() << "\tDoWork\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //�������� ������ ������������ 
	}

	/*while (true)
	{ �������� �� ����������� ���� ������������ ������
	}*/

	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Rus");

	std::thread myth(DoWork); //��� ����� ������
	myth.detach(); //����� ����� ����������� ��������������, �� �� ����� ������ main()

	//myth.join(); //��� ������ ����� ����������� � ������ �������, �� ���������������, ����� �������� ����� �������� ����� join
	//DoWork(); ������ � ����� ������

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID ������ : " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	try
	{
		myth.join(); //�������� ���, ��� �� ����� ��������� ���������� ������
	}
	catch (std::system_error & ex)
	{
		std::cout << ex.what() << std::endl;
		__asm nop
	}
	return 0;
}