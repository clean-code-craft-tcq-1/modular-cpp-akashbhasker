/**************************************************************************************
* @file        : ColorCodingTest.cpp
* @brief       : Contains Business Logic to Test and Validate the 25-pair Color Code Feature
*
**************************************************************************************/
#include <iostream>
#include <assert.h>

#include "TelCoColorCoder.h"

/**
 * Description     : testNumberToPair : To validate if the given Pair Number refers to the expected Major Color and Minor Color combination
 *
 */
void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.getColorPairString() << std::endl;

    assert(colorPair.getMajorColor() == expectedMajor);
    assert(colorPair.getMinorColor() == expectedMinor);
}

/**
 * Description     : testPairToNumber : To validate if the given Major Color and Minor Color combination refers to the expected Pair Number
 *
 */
void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;

    assert(pairNumber == expectedPairNumber);
}



int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    TelCoColorCoder::printColorCodeReference();

    return 0;
}
