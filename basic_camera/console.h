#pragma once
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include "video.h"


class console
{	
public:
	console();
	~console();
	void console_screen();

private:
	video video;
	std::atomic <bool> run_loop;
};
