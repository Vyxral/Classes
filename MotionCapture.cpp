#include "MotionCapture.h"


MotionCapture::MotionCapture()
{
	focusPoint = 0;
	mode = CAPTUREMODE_POINT;
	captureInterval = 250;
	captureDuration = 2000;
	captureDistance = 20;
	numberOfPoint = 20;
	std::vector<TimePoint> points;
	points.clear();
}


////////////////////////////////////////////////////
//                                                //
//                    GETTERS                     //
//                                                //
////////////////////////////////////////////////////

unsigned int MotionCapture::getFocusPoint()
{
	return focusPoint;
}

unsigned int MotionCapture::getMode()
{
	return mode;
}

unsigned int MotionCapture::getCaptureInterval()
{
	return captureInterval;
}

unsigned int MotionCapture::getCaptureDuration()
{
	return captureDuration;
}

unsigned int MotionCapture::getCaptureDistance()
{
	return captureDistance;
}

unsigned int MotionCapture::getNumberOfPoint()
{
	return numberOfPoint;
}

std::vector<TimePoint> MotionCapture::getPoints()
{
	return points;
}

void MotionCapture::setFocusPoint(unsigned int p)
{
	focusPoint = p%points.size();
}

void MotionCapture::setMode(unsigned int m)
{
	mode = m;
	points.clear();
}

void MotionCapture::setCaptureInterval(unsigned int i)
{
	captureInterval = i;
}

void MotionCapture::setCaptureDuration(unsigned int d)
{
	captureDuration = d;
}

void MotionCapture::setCaptureDistance(unsigned int d)
{
	captureDistance = d;
}

void MotionCapture::setNumberOfPoint(unsigned int p)
{
	numberOfPoint = p;
}



////////////////////////////////////////////////////
//                                                //
//                    METHODS                     //
//                                                //
////////////////////////////////////////////////////

void MotionCapture::capture(MouseHandler m)
{
	TimePoint timePoint;
	std::chrono::high_resolution_clock::time_point nowTime = std::chrono::high_resolution_clock::now();
	
	switch (mode)
	{
		case CAPTUREMODE_TIME:
			if ((points.size() == 0) || (std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - points.at(0).keyTime).count()<captureDuration))
			{
				timePoint.x = m.getPosition().x;
				timePoint.y = m.getPosition().y;
				timePoint.keyTime = nowTime;
				timePoint.keyPoint = false;
				points.push_back(timePoint);
			}
			break;
		case CAPTUREMODE_DISTANCE :
			if ((points.size() == 0) || std::abs(m.getPosition().x-points.at(points.size()-1).x) + std::abs(m.getPosition().y - points.at(points.size() - 1).y)>captureDistance)
			{
				timePoint.x = m.getPosition().x;
				timePoint.y = m.getPosition().y;
				timePoint.keyTime = nowTime;
				timePoint.keyPoint = false;
				points.push_back(timePoint);
			}
			break;
		case CAPTUREMODE_POINT:
			if (m.isButtonPressed(0) && points.size() < numberOfPoint)
			{
				if((points.size() == 0) || std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - points.at(points.size() - 1).keyTime).count()>POINTINTERVAL)
				{
					timePoint.x = m.getPosition().x;
					timePoint.y = m.getPosition().y;
					timePoint.keyTime = nowTime;
					timePoint.keyPoint = false;
					points.push_back(timePoint);
				}
			}
			break;
		default:

			break;
	}
}

void MotionCapture::clear()
{
	points.clear();
}
