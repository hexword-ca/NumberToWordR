/*
   Copyright 2024 Hammad Rauf <rauf.hammad@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/
// WinNumbToWordsR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//                       Visit Scribbles for detailed article: 
//                       https://hammadr.wordpress.com/2016/10/27/number-to-words-recursive/
//                       https://andromedabay.ddns.net/number-to-words-recursive/


#include <sstream>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <list>
#include <string>


class WinNumberToWordR {

public:
	std::string convert(uint64_t numb, int depth);

private:
	std::string convertInner(uint64_t numb);
	std::string matcher(int digit, int placeValue);
	std::string matchXtoWords(std::string xs);
};


std::string WinNumberToWordR::convert(uint64_t numb, int depth) {
	std::string words = "", words2 = "";
	std::string part_words = "";
	std::string part_xx = "", part_xword = "";
	uint64_t part_bigger = 0;
	uint64_t small_part = 0;
	int last3 = 0;

	if (numb < 1000) {
		words = convertInner(numb);
	}
	else {
		part_bigger = numb / 1000;
		small_part = numb - (part_bigger * 1000);
		part_words = convert(part_bigger, depth + 1);

		if (part_bigger > 1000) {
			std::ostringstream ss;
			std::string  st = "";
			//st = std::to_string(part_bigger);
			ss << part_bigger;
			st = ss.str();
			std::string se = st.substr(st.length() - 3);
			//last3 = std::stoi(se);
			std::istringstream is(se);
			is >> last3;
		}
		else
			last3 = (int)part_bigger;
		if (last3 > 0)
			part_words += " ";
		part_xx = "";
		do {
			part_xx += "X";
			depth--;
		} while (depth >= 0);
		part_xword = matchXtoWords(part_xx);
		if (last3 > 0) {
			part_words += part_xword;
			part_words += " ";
		}

		words2 = convertInner(small_part);
		words = part_words + words2;
	}
	return words;
}

std::string WinNumberToWordR::convertInner(uint64_t numb) {
	std::string words = "";
	std::string wordTen = "";
	int hundred = 0;
	int tens = 0;
	int units = 0;
	bool teens = false;

	if ((numb < 1000) & (numb > 0)) {
		hundred = numb / 100;
		numb -= (hundred * 100);
		tens = numb / 10;
		numb -= (tens * 10);
		units = numb;
	}

	words += matcher(hundred, 100);
	if (hundred != 0)
		words += " hundred";
	wordTen += matcher(tens, 10);
	if ((wordTen.compare("ten") == 0) && (units > 0)) {
		teens = true;
		switch (units) {
		case 1: wordTen = "eleven"; break;
		case 2: wordTen = "twelve"; break;
		case 3: wordTen = "thirteen"; break;
		case 4: wordTen = "fourteen"; break;
		case 5: wordTen = "fifteen"; break;
		case 6: wordTen = "sixteen"; break;
		case 7: wordTen = "seventeen"; break;
		case 8: wordTen = "eighteen"; break;
		case 9: wordTen = "nineteen"; break;
		case 0: break;
		}
	}
	if ((hundred != 0) && ((tens != 0) || (units != 0)))
		words += " ";
	words += wordTen;
	if ((!teens) && (hundred != 0) && (tens != 0) && (units != 0))
		words += " ";
	if (!teens)
		words += matcher(units, 1);

	return words;
}

std::string WinNumberToWordR::matcher(int digit, int placeValue) {
	std::string result = "";

	if ((placeValue == 1) | (placeValue == 100)) {
		switch (digit) {
		case 1: result = "one"; break;
		case 2: result = "two"; break;
		case 3: result = "three"; break;
		case 4: result = "four"; break;
		case 5: result = "five"; break;
		case 6: result = "six"; break;
		case 7: result = "seven"; break;
		case 8: result = "eight"; break;
		case 9: result = "nine"; break;
		case 0: result = "";
		}
	}

	if (placeValue == 10) {
		switch (digit) {
		case 1: result = "ten"; break;
		case 2: result = "twenty"; break;
		case 3: result = "thirty"; break;
		case 4: result = "forty"; break;
		case 5: result = "fifty"; break;
		case 6: result = "sixty"; break;
		case 7: result = "seventy"; break;
		case 8: result = "eighty"; break;
		case 9: result = "ninety"; break;
		case 0: result = "";
		}
	}

	return result;
}

std::string WinNumberToWordR::matchXtoWords(std::string xs) {
	std::string result = "";

	if (xs.compare("X") == 0)
		result = "thousand";
	else if (xs.compare("XX") == 0)
		result = "million";
	else if (xs.compare("XXX") == 0)
		result = "billion";
	else if (xs.compare("XXXX") == 0)
		result = "trillion";
	else if (xs.compare("XXXXX") == 0)
		result = "quadrillion";
	else if (xs.compare("XXXXXX") == 0)
		result = "quintillion";
	else if (xs.compare("XXXXXXX") == 0)
		result = "sextillion";
	else if (xs.compare("XXXXXXXX") == 0)
		result = "septillion";
	else if (xs.compare("XXXXXXXXX") == 0)
		result = "octillion";
	else if (xs.compare("XXXXXXXXXX") == 0)
		result = "nonillion";
	else if (xs.compare("XXXXXXXXXXX") == 0)
		result = "decillion";
	else if (xs.compare("XXXXXXXXXXXX") == 0)
		result = "undecillion";
	else if (xs.compare("XXXXXXXXXXXXX") == 0)
		result = "duodecillion";
	else result = xs;

	return result;
}

using namespace std;

int main(int argc, char* argv[])
{
	uint64_t n = ((uint64_t)2147483647) << 30;
	//int64_t n=2147483647;
	//int n=98427543;
	//int n=900;
	printf("Hello World!\n");
	cout << "Number to Convert: " << n << endl;
	WinNumberToWordR n1;
	cout << "Converted result: " << (n1.convert(n, 0)) << endl;
	getchar();
	return 0;
}