#pragma once
#include "RemoveRedEffect.hpp"
#include "RemoveGreenEffect.hpp"
#include "RemoveBlueEffect.hpp"
#include "NegateRedEffect.hpp"
#include "NegateGreenEffect.hpp"
#include "NegateBlueEffect.hpp"
#include "GrayscaleEffect.hpp"
#include "ContrastEffect.hpp"
#include "NoiseEffect.hpp"
#include "BlurEffect.hpp"
#include "PixelateEffect.hpp"
#include "HorizontalFlipEffect.hpp"
#include "VerticalFlipEffect.hpp"
#include "Rotate90Effect.hpp"
#include "Rotate180Effect.hpp"
#include "Rotate270Effect.hpp"

enum class ImageEffectType
{
	RemoveRed = 1,
	RemoveGreen,
	RemoveBlue,
	NegateRed,
	NegateGreen,
	NegateBlue,
	Grayscale,
	Contrast,
	Noise,
	Blur,
	Pixelate,
	VerFlip,
	HorFlip,
	Rotate90,
	Rotate180,
	Rotate270
};

class EffectFactory
{
public:
	static ImageEffect* createEffect(ImageEffectType effect_type)
	{
		switch (effect_type)
		{
		case ImageEffectType::RemoveRed:
			return new RemoveRedEffect{};
			break;

		case ImageEffectType::RemoveGreen:
			return new RemoveGreenEffect{};
			break;


		case ImageEffectType::RemoveBlue:
			return new RemoveBlueEffect{};
			break;

		case ImageEffectType::NegateRed:
			return new NegateRedEffect{};
			break;

		case ImageEffectType::NegateGreen:
			return new NegateGreenEffect{};
			break;

		case ImageEffectType::NegateBlue:
			return new NegateBlueEffect{};
			break;

		case ImageEffectType::Grayscale:
			return new GrayscaleEffect{};
			break;

		case ImageEffectType::Contrast:
			return new ContrastEffect{};
			break;

		case ImageEffectType::Noise:
			return new NoiseEffect{};
			break;

		case ImageEffectType::Blur:
			return new BlurEffect{};
			break;

		case ImageEffectType::Pixelate:
			return new PixelateEffect{};
			break;

		case ImageEffectType::HorFlip:
			return new HorizontalFlipEffect{};
			break;

		case ImageEffectType::VerFlip:
			return new VerticalFlipEffect{};
			break;

		case ImageEffectType::Rotate90:
			return new Rotate90Effect{};
			break;

		case ImageEffectType::Rotate180:
			return new Rotate180Effect{};
			break;

		case ImageEffectType::Rotate270:
			return new Rotate270Effect{};
			break;

		default: 
			break;
		}
	}
};