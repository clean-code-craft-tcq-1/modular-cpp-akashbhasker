/**************************************************************************************
* @file        : ColorCode.h
* @brief       : Contains definition for ColorPair class and Utility Functions
*
**************************************************************************************/
#ifndef TELCOCOLORCODER_H_
#define TELCOCOLORCODER_H_

#include <iostream>

namespace TelCoColorCoder
{

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

extern const int numberOfMajorColors;
extern const int numberOfMinorColors;

class ColorPair
{
public:
	ColorPair(MajorColor major, MinorColor minor);
	~ColorPair();

	MajorColor getMajorColor();
	MinorColor getMinorColor();
	std::string getColorPairString();

private:
	MajorColor majorColor;
	MinorColor minorColor;
};

	ColorPair GetColorFromPairNumber(int pairNumber);
	int GetPairNumberFromColor(MajorColor major, MinorColor minor);
	void printColorCodeReference();


} /* namespace TelCoColorCoder*/

#endif /* TELCOCOLORCODER_H_ */
