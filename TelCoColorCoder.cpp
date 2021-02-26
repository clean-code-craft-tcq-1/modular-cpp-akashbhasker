/**************************************************************************************
* @file        : TelCoColorCoder.cpp
* @brief       : Contains Implementation for Color Code Class and Utility functions
*
**************************************************************************************/
#include <iostream>
#include <assert.h>
#include <iomanip>

#include "TelCoColorCoder.h"
using namespace TelCoColorCoder;


const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

const int TelCoColorCoder::numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const int TelCoColorCoder::numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


/**
 * Description     : ColorPair : Constructor
 *
 */
ColorPair::ColorPair(MajorColor major, MinorColor minor)
:majorColor(major),
 minorColor(minor)
{
}

/**
 * Description     : ~ColorPair : Destructor
 *
 */
ColorPair::~ColorPair()
{
}

/**
 * Description     : getMajorColor : To get the Major Color Value
 *
 */
MajorColor ColorPair::getMajorColor()
{
	return majorColor;
}

/**
 * Description     : getMinorColor : To get the Minor Color Value
 *
 */
MinorColor ColorPair::getMinorColor()
{
	return minorColor;
}

/**
 * Description     : ToString : To get Minor and Major Color String
 *
 */
std::string ColorPair::getColorPairString()
{
	std::string colorPairStr = MajorColorNames[majorColor];
	colorPairStr += " ";
	colorPairStr += MinorColorNames[minorColor];
	return colorPairStr;
}

/**
 * Description     : GetColorFromPairNumber : To get the Color Pair for the given Pair Number
 *
 * @param[in]      : int
 * @return         : ColorPair
 */
ColorPair TelCoColorCoder::GetColorFromPairNumber(int pairNumber)
{
	int zeroBasedPairNumber = pairNumber - 1;

	MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
	MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);

	return ColorPair(majorColor, minorColor);
}

/**
 * Description     : GetPairNumberFromColor : To get the Pair Number for the given Major and Minor Color
 *
 * @param[in]      : MajorColor
 * @param[in]      : MinorColor
 * @return         : int
 */
int TelCoColorCoder::GetPairNumberFromColor(MajorColor major, MinorColor minor)
{
	return major * numberOfMinorColors + minor + 1;
}

/**
 * Description     : printColorCodeReference : To print a reference Manual for the 25-pair Color Code
 *
 */
void TelCoColorCoder::printColorCodeReference()
{
	std::cout << "----------------------------- "<< std::endl;
	std::cout << " Color Code reference Manual "<< std::endl;
	std::cout << "----------------------------- "<< std::endl;
	std::cout << "PairNumber | MajorColor | MinorColor "<< std::endl;

	int maxPairCount = TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors;

	for (int pairNumber = 1 ; pairNumber <= maxPairCount ; ++ pairNumber )
	{
		TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
		std::cout << std::setw(6)<< pairNumber << " \t   | \t "<< colorPair.getColorPairString() << std::endl ;
	}
}
