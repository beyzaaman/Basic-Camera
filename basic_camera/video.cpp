#include "pch.h"
#include "video.h"
//
//namespace
//{
//	int jpg(0);
//		int png(1);
//		int exit(2);
//}

video::video() :
	camera(0),
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
		thread_flag = 0;
		thread_vid.join();

	}
}

void video::cam()
{
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
	if (thread_flag == 0)
	{
		save();
	}

}


void video::set_thread_flag(int val)
{
	thread_flag = val;
}

void video::save()
{
		cv::Mat picture;
		cv::Mat frame;
		camera>> frame;

		std::cout << "Please enter your photo's format type :JPG or PNG.\n";
		std::cin >> type;
		
		if (type == "JPG" || type == "jpg")
		{
			cv::imwrite("C:/Users/hp/Desktop/picture.jpg", frame);
		}
		else if(type == "png" || type == "png")
		{
			cv::imwrite("C:/Users/hp/Desktop/picture.png", frame);
		}

		cv::namedWindow("picture", cv::WINDOW_AUTOSIZE);
		cv::imshow("picture", frame);
		cv::waitKey(0);
}

