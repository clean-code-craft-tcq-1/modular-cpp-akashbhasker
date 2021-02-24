/**************************************************************************************
* @file        : ColorCode.cpp
* @brief       : Contains Implementation for Color Code Class
*
**************************************************************************************/
#include <iostream>
#include <assert.h>
#include "ColorCode.h"

using namespace TelCoColorCoder;


const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);


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
std::string ColorPair::ToString()
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
