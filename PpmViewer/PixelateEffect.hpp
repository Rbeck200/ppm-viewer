#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class PixelateEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp_data;
		vector<Pixel> temp_line;
		int distance = (rand() % 5) + 1;
		for (int i = 0; i < doc.getHeight(); i++)
		{
			Pixel a;

			if (i % distance == 0) {

				temp_line.clear();

				for (int j = 0; j < doc.getWidth(); j++)
				{
		
					if (j % distance == 0) {
						a = doc[i][j];
						temp_line.push_back(a);
					}
					else {
						temp_line.push_back(a);
					}
				}
				temp_data.push_back(temp_line);
			}
			else {
				temp_data.push_back(temp_line);
			}
		}
		doc.setRGBData(temp_data);
	}
};
