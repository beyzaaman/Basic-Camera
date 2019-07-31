#include "pch.h"
#include "video.h"


video::video() :
	playing(false),
	capture(false)
{
}

video::~video()
{	
	close_cam();
}

void video::open_cam()
{
	playing = true;

	thread_vid = std::thread (&video::cam,this);

}

void video::close_cam()
{
	playing = false;

	if (thread_vid.joinable())
	{
		thread_vid.join();
	}

}

void video::cam()
{
	cv::VideoCapture camera(0);
	camera.open(0);
	cv::Mat screen;
	cv::namedWindow("screen", cv::WINDOW_AUTOSIZE);
	cv::Mat frame;

	while(playing)
	{
		camera >> frame;
		cv::imshow("screen", frame);
		cv::waitKey(40);

		if (capture)
		{
			save(frame);
			capture = false;
		}

	}
}

void video::save(const cv::Mat& frame)
{
	
	cv::imwrite(("C:/Users/hp/Desktop/pictures/" + filename_ + type_), frame);

	cv::namedWindow("picture", cv::WINDOW_AUTOSIZE);
	cv::imshow("picture", frame);
	cv::waitKey(2000);
}

void video::capture_image(std::string filename, std::string type)
{
	filename_ = filename;
	type_ = type;

	capture = true;
}

