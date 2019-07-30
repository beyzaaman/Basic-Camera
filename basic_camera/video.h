#pragma once
#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>

class video
{
public:
	video();
	~video();
	void cam();
	void open_cam();
	void close_cam();
	void set_thread_flag(int val);
	void save();

private:
	cv::VideoCapture camera;
	std::thread thread_vid;
	std::atomic <int> thread_flag;
	std::string type;
	

};