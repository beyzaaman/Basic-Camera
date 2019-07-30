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
		return;
	}
	
	flow.set_thread_flag(0);

	choose_type();
	
}

void console::choose_type()
{	
	std::cout << "Please enter your photo's type to save via capital letters :JPG or PNG.\n";
	std::cin >> save_type;
	
}

void console::set_save_type()
{	
	if (save_type == "JPG" or save_type == "jpg")
	{

	}
	else if (save_type == "png" or save_type == "png")
	{

	}
	else
		choose_type();
}
