#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class GrayscaleEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				int temp = 0;
				Pixel& p = doc[i][j];
				temp = ((p.getRed() + p.getBlue() + p.getGreen()) / 3);

				p.setPixel(temp, temp, temp);
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};
