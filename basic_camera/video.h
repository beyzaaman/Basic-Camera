#pragma once
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include <fstream>

class video
{
public:
	video();
	~video();
	void open_cam();
	void close_cam();
	void set_thread_flag(int val);
	

private:
	std::string type;
	cv::VideoCapture camera;
	std::thread thread_vid;
	std::atomic <int> thread_flag;
	
private:
	void cam();
	void save();
};