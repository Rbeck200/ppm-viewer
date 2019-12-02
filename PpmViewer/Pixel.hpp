#pragma once
#ifndef PIXEL_H
#define PIXEL_H

#include <istream>
#include <exception>
using namespace std;

class Pixel
{
private:
	int _red = -1;
	int _green = -1;
	int _blue = -1;

public:
	
	Pixel(int red, int green, int blue) {

	}

	Pixel() {

	}

	void setRed(const int& red) {
		_red = red;
	}

	void setGreen(const int& green) {
		_green = green;
	}
	
	void setBlue(const int& blue) {
		_blue = blue;
	}

	void setPixel(const int& red, const int& green, const int& blue) {
		setRed(red);
		setGreen(green);
		setBlue(blue);
	}

	int getRed() const 	{
		return _red;
	}

	int getGreen() const {
		return _green;
	}

	int getBlue() const {
		return _blue;
	}

	void pixelCheck(const int& value) {
		if (getRed() > value) {
			setRed(value);
		}
		else if (getRed() < 0) {
			setRed(0);
		}
		
		if (getGreen() > value) {
			setGreen(value);
		}
		else if (getGreen() < 0) {
			setGreen(0);
		}

		if (getBlue() > value) {
			setBlue(value);
		}
		else if (getBlue() < 0) {
			setBlue(0);
		}
	}


};

istream& operator>>(istream& stream, Pixel& pixel)
{
	//sets local variables in the function
	int r = -1;
	int g = -1;
	int b = -1;

	// passes the data from the stream into variables
	stream >> r >> g >> b;

	//calls setPixel
	pixel.setPixel(r, g, b);
	return stream;
}

ostream& operator<<(ostream& stream, const Pixel& pixel)
{
	stream << pixel.getRed() << " " << pixel.getGreen() << " " << pixel.getBlue();
	return stream;
}

#endif // !PIXEL_H
