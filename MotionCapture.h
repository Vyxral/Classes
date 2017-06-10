#ifndef _MOTIONCAPTURE_H_
#define _MOTIONCAPTURE_H_

#define CAPTUREMODE_TIME		1
#define CAPTUREMODE_DISTANCE	2
#define CAPTUREMODE_POINT		3
#define POINTINTERVAL			500

#include <chrono>
#include <vector>

#include "MouseHandler.h"


typedef struct TimePoint TimePoint;
struct TimePoint
{
	int x;
	int y;
	std::chrono::high_resolution_clock::time_point keyTime;
	bool keyPoint;
};

class MotionCapture
{

	private :
		unsigned int focusPoint;
		unsigned int mode;// 1/2/3
		unsigned int captureInterval;//For a speed base capture (in milliseconds)
		unsigned int captureDuration;//For a speed base capture (in milliseconds)
		unsigned int captureDistance;//For a smooth capture
		unsigned int numberOfPoint;//For the point by point capture
		std::vector<TimePoint> points;


	public :

		//Getters
		unsigned int getFocusPoint();
		unsigned int getMode();
		unsigned int getCaptureInterval();
		unsigned int getCaptureDuration();
		unsigned int getCaptureDistance();
		unsigned int getNumberOfPoint();
		std::vector<TimePoint> getPoints();

		void setFocusPoint(unsigned int);
		void setMode(unsigned int);
		void setCaptureInterval(unsigned int);
		void setCaptureDuration(unsigned int);
		void setCaptureDistance(unsigned int);
		void setNumberOfPoint(unsigned int);

		//Methods
		MotionCapture();

		void capture(MouseHandler);//capture the motion until specified completion
		void clear();
		/*
		load();//load a motion file
		save();//save a motion in a file
		compare();//compare to an other motion
		//*/

};


#endif