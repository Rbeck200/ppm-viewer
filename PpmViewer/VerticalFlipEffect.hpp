#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class VerticalFlipEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp_data;

		for (int i = (doc.getHeight() - 1); i >= 0; i--)
		{
			temp_data.push_back(doc[i]);
		}
		doc.setRGBData(temp_data);
	}
};