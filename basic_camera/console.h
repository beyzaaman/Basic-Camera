#pragma once
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include <mutex>

class console
{	
public:
	console();
	~console();
	void welcome();
	void choose_type();
	void set_save_type();

private:
	std::string input;
	std::string save_type;


};