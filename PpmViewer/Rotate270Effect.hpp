#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class Rotate270Effect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		vector<vector<Pixel>> temp_data;
		for (int i = 0; i < doc.getHeight(); i++)
		{
			vector<Pixel> temp_line;
			for (int j = (doc.getWidth() - 1); j >= 0; j--)
			{
				temp_line.push_back(doc[i][j]);
			}
			temp_data.push_back(temp_line);
		}
		doc.setRGBData(temp_data);
		temp_data.clear();
		for (int i = (doc.getHeight() - 1); i >= 0; i--)
		{
			temp_data.push_back(doc[i]);
		}
		doc.setRGBData(temp_data);
		temp_data.clear();
		for (int i = 0; i < doc.getWidth(); i++)
		{
			vector<Pixel> temp_line;
			for (int j = (doc.getHeight() - 1); j >= 0; j--)
			{
				temp_line.push_back(doc[j][i]);
			}
			temp_data.push_back(temp_line);
		}
		doc.setRGBData(temp_data);
		doc.setWidth(doc.getHeight());
		doc.setHeight(temp_data.size());
	}
};