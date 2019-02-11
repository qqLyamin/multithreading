#include <iostream>

#include <thread>

#include <chrono>

//КОДИРОВКА utf8
void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока : " << std::this_thread::get_id() << "\tDoWork\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //имитация бурной деятельности 
	}

	std::thread myth2(DoWork); //создали бесконечную рекурсию вызова потоков (КАКИМ ОБРАЗОМ В ТАКОМ СЛУЧАЕ ПРЕДУСМОТРЕТЬ ВЫХОД ИЗ РЕКУРСИИ????????????)
	/*while (true)
	{ проверка на бесконечный цикл многоразовый запуск
	}*/

	system("pause");
}

//Tools > Options > Environment > Documents > Save documents as Unicode when data cannot be saved in codepage

int main()
{
	setlocale(LC_ALL, "Rus");

	std::thread myth(DoWork); //так будет ошибка
	//myth.detach(); //поток может выполняться самостоятельно, но до конца работы main()


	//myth.join(); //так задачи будут выполняться в разных потоках, но последовательно, важно понимать когда вызывать метод join
	//DoWork(); работа в одном потоке

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "ID потока : " << std::this_thread::get_id() << "\tmain\t" << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	try
	{
		myth.join(); //вызываем там, где мы хотим дождаться выполнения потока
	}
	catch (std::system_error & ex) // направил join в атаку на detach
	{
		std::cout << ex.what() << std::endl;
		__asm nop
	}

	return 0;
}