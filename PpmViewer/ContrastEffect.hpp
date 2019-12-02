#pragma once
#include "PpmDocument.hpp"
#include "ImageEffect.hpp"
class ContrastEffect : public ImageEffect
{
public:
	virtual void applyEffect(PpmDocument& doc)
	{
		for (int i = 0; i < doc.getHeight(); i++)
		{
			for (int j = 0; j < doc.getWidth(); j++)
			{
				Pixel& p = doc[i][j];
				if (p.getRed() > doc.getColorDepth() / 2) {
					p.setRed(doc.getColorDepth());
				}
				else {
					p.setRed(0);
				}

				if (p.getGreen() > doc.getColorDepth() / 2) {
					p.setGreen(doc.getColorDepth());
				}
				else {
					p.setGreen(0);
				}

				if (p.getBlue() > doc.getColorDepth() / 2) {
					p.setBlue(doc.getColorDepth());
				}
				else {
					p.setBlue(0);
				}
				//not necessary as we're using references but it makes our intent more clear
				doc[i][j] = p;
			}
		}
	}
};
