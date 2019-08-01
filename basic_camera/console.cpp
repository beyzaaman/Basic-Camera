#include "pch.h"
#include "console.h"
#include "video.h"


console::console():
	run_loop(true)
{	
}

console::~console()
{
}

void console::console_screen()
{	
	video.open_cam();
	while (true)
	{
		std::cout << "Please enter filename and saving format -for example file.jpg- when you want to take a photo. To exit, please enter 'q' \n";
		std::string input;
		std::getline(std::cin, input);

		if (!(input != "q" ^ input != ""))
		{
			if (input[0]!='.' && input.find(".")!=std::string::npos)
			{
				std::string filename;
				std::string type;

				std::size_t pos = input.find(".");
				filename = input.substr(0, pos);
				type = input.substr(pos);

				video.capture_image(filename, type);
			}
			
		}

		else
		{
			return;
		}
	}
		
}
