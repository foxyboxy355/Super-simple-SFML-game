#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

namespace oth {
	void Log(std::string text)
	{
		std::cout << text;
	}

	void SlowLog(std::string text)
	{
		for (int x = 0; x < text.length(); x++)
		{
			std::cout << text[x];
			Sleep(30);
		}
	}
};