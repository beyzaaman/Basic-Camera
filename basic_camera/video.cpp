#include "pch.h"
#include "video.h"
#include "console.h"


video::video() :
	thread_flag(1)
{

}

video::~video()
{	
	if (thread_vid.joinable())
	{
		thread_vid.join();
		thread_flag = 0;
	}
}

void video::open_cam()
{
	thread_vid = std::thread (&video::cam,this);

}

void video::close_cam()
{
	if (thread_vid.joinable())
	{
		thread_vid.join();
		thread_flag = 0;
	}
}

void video::cam()
{
	cv::VideoCapture camera(0);
	camera.open(0);

	cv::Mat screen;
	cv::namedWindow("screen", cv::WINDOW_AUTOSIZE);
	cv::Mat live;

	while (thread_flag==1)
	{
		camera >> live;
		cv::imshow("screen", live);
		cv::waitKey(40);
	}

	if (thread_flag==0)
	{
		capture();
	}
	
	
}

void video::capture()
{
	cv::VideoCapture flow_(0);
	if (flow_.isOpened())
	{
		cv::Mat picture;
		cv::namedWindow("picture", cv::WINDOW_AUTOSIZE);

		cv::Mat frame;
		flow_ >>frame;
		cv::imshow("picture", frame);
		cv::waitKey(0);
		
		console get;
		if (get.get_save_type())
		{ 

			cv::imwrite("C:/Users/hp/Desktop/picture.png", frame);
		}
		else
		{
			cv::imwrite("C:/Users/hp/Desktop/picture.jpg", frame);
		}

		

	}

}

void video::set_thread_flag(int val)
{
	thread_flag = val;
}

