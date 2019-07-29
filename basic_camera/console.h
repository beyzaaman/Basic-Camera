#pragma once
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>

class console
{
public:
	
	std::thread display_th;
	std::string input;

public:
	console();
	~console();
	void take_pic();
	void choose_type();


};