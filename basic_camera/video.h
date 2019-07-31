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

public:
	video();
	~video();
	void open_cam();
	void close_cam();
	void capture_image(std::string filename, std::string type);
	

private:
	std::string type_;
	std::string filename_;
	std::thread thread_vid;
	std::atomic<bool> playing;
	std::atomic<bool> capture;
	
private:
	void cam();
	void save(const cv::Mat& frame);
};