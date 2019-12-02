#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class NoiseEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				int noise = (rand() % 21) - 10;
				p.setPixel((p.getRed() + (noise)),
					((p.getGreen() + (noise))),
					((p.getBlue() + (noise))));
				p.pixelCheck(doc.getColorDepth());
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};
