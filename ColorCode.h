#ifndef COLORCODE_H_
#define COLORCODE_H_

#include <iostream>

namespace TelCoColorCoder
{

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

class ColorPair {
private:
	MajorColor majorColor;
	MinorColor minorColor;
public:
	ColorPair(MajorColor major, MinorColor minor);
	MajorColor getMajor();
	MinorColor getMinor();
	std::string ToString();
};


	ColorPair GetColorFromPairNumber(int pairNumber);
	int GetPairNumberFromColor(MajorColor major, MinorColor minor);


} /* TelCoColorCoder */

#endif /* COLORCODE_H_ */
