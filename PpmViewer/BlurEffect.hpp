#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class BlurEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int z = 0; z < 10; z++) 
		{
			vector<vector<Pixel>> temp_data;
			//temp_data = doc.getRGBData();
			for (int j = 0; j < doc.getHeight(); j++)
			{
				vector<Pixel> temp_line;
				for (int i = 0; i < doc.getWidth(); i++)
				{
					Pixel a;
					int temp_red = 0;
					int temp_green = 0;
					int temp_blue = 0;

					if (i == 0) 
					{
						temp_red = ((doc[j][i].getRed() + doc[j][i + 1].getRed()) / 2);
						temp_green = ((doc[j][i].getGreen() + doc[j][i + 1].getGreen()) / 2);
						temp_blue = ((doc[j][i].getBlue() + doc[j][i + 1].getBlue()) / 2);
					}
					else if (i == doc[j].size() - 1)
					{
						temp_red = ((doc[j][i - 1].getRed() + doc[j][i].getRed()) / 2);
						temp_green = ((doc[j][i - 1].getGreen() + doc[j][i].getGreen()) / 2);
						temp_blue = ((doc[j][i - 1].getBlue() + doc[j][i].getBlue()) / 2);
					}
					else {
						temp_red = ((doc[j][i - 1].getRed() + doc[j][i].getRed() + doc[j][i + 1].getRed()) / 3);
						temp_green = ((doc[j][i - 1].getGreen() + doc[j][i].getGreen() + doc[j][i + 1].getGreen()) / 3);
						temp_blue = ((doc[j][i - 1].getBlue() + doc[j][i].getBlue() + doc[j][i + 1].getBlue()) / 3);
					}

					a.setPixel(temp_red, temp_green, temp_blue);
					temp_line.push_back(a);
				}
				temp_data.push_back(temp_line);
			}
			doc.setRGBData(temp_data);
			temp_data.clear();
			temp_data.resize(doc.getHeight());
			for (int i = 0; i < doc.getWidth(); i++) {
				for (int j = 0; j < doc.getHeight(); j++) {
					Pixel a;
					int temp_red = 0;
					int temp_green = 0;
					int temp_blue = 0;
					if (j == 0) {
						temp_red = ((doc[j][i].getRed() + doc[j + 1][i].getRed()) / 2);
						temp_green = ((doc[j][i].getGreen() + doc[j + 1][i].getGreen()) / 2);
						temp_blue = ((doc[j][i].getBlue() + doc[j + 1][i].getBlue()) / 2);
					}
					else if (j == (doc.getHeight() - 1)) {
						temp_red = ((doc[j - 1][i].getRed() + doc[j][i].getRed()) / 2);
						temp_green = ((doc[j - 1][i].getGreen() + doc[j][i].getGreen()) / 2);
						temp_blue = ((doc[j - 1][i].getBlue() + doc[j][i].getBlue()) / 2);
					}
					else {
						temp_red = ((doc[j - 1][i].getRed() + doc[j][i].getRed() + doc[j + 1][i].getRed()) / 3);
						temp_green = ((doc[j - 1][i].getGreen() + doc[j][i].getGreen() + doc[j + 1][i].getGreen()) / 3);
						temp_blue = ((doc[j - 1][i].getBlue() + doc[j][i].getBlue() + doc[j + 1][i].getBlue()) / 3);
					}
					a.setPixel(temp_red, temp_green, temp_blue);
					temp_data[j].push_back(a);
				}
			}
			doc.setRGBData(temp_data);
		}
	}
};
