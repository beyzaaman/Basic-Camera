#include "pch.h"
#include "console.h"
#include "video.h"


console::console()
{	
}

console::~console()
{
}

void console::welcome()
{
	video flow;
	flow.open_cam();
	std::cout << "Please hit enter button when you want to take a photo. To exit, please hit 'e' and enter key.\n";
	input = std::cin.get();


	if (input == "e")
	{
		flow.set_thread_flag(2);
		
	}
	else
	{
		flow.close_cam();
	}
	
}






