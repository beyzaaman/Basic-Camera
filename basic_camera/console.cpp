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
	while (run_loop)
	{
		std::cout << "Please enter filename and saving format -for example file.jpg- when you want to take a photo. To exit, please enter 'q' \n";
		std::string input;
		std::getline(std::cin, input);

		if (!(input != "q" ^ input != ""))
		{
			std::string filename;
			std::string type;
			if (input.find(".")!=std::string::npos)
			{
				std::size_t pos = input.find(".");
				filename = input.substr(0, pos);
				type = input.substr(pos);

				video.capture_image(filename, type);
			}
			
		}

		else
		{
			run_loop = false;
		}
	}
		

}
