
#include <iostream>
#include <string>


// rules for roman numbers:
/*

letters have a value, all these values are added up or subtracted from eachother
I one
V five
X ten
L fifty
C one hundred
D five hundred
M one thousand


all letters must be ordered from large to small, except when a letter has to be subtracted from the next value

only one subtraction allowed ?!?





*/

std::string getCharNTimes(char in, int times){
	std::string r;

	// debug, removed
	//std::cout << times << "amount of times\n";
	for (int i = 0; i < times; i++){
		r += in;
	}
	return r;
}



std::string toRoman(int in){
	// repeat this for every operation
	int mCount = in / 1000;
	in -= mCount * 1000;
	
	int dCount = in / 500;
	in -= dCount * 500;

	int cCount = in / 100;
	in -= cCount * 100;

	int lCount = in / 50;
	in -= lCount * 50;

	int xCount = in / 10;
	in -= xCount * 10;

	int vCount = in / 5;
	in -= vCount * 5;

	int iCount = in;
	// removing delta from in isn't needed anymore, because we won't utilize in any more



	// check for (n-1) 's
	// basically: if something is m = 1, d = 1, and c = 4, the total will be 1900, this can be written as MDCCCC, but also can be written as MCM, this subtracts C from M making it 1000 - 100 = 900, add 1000 from the first M to that and you get 1900, the same but with much less characters

	// iSubtract doesn't exist
	char mSubtract = 0, dSubtract = 0, cSubtract = 0, lSubtract = 0, xSubtract = 0, vSubtract = 0;
	
	// MDCCCC -> MCM
	if (dCount == 1 && cCount == 4){
		mSubtract = 'C';
		dCount -= 1;
		cCount -= 4;	
	}

	// CCCC -> CD
	if (cCount == 4){
		dSubtract = 'C';
		cCount -= 4;
	}

	// LL can't exist, so LX can't exist, no checking needed for that 


	// LXXXX -> XC
	if (xCount == 4 && lCount == 1){
		cSubtract = 'X';
		lCount -= 1;
		xCount-= 4;
	}
	// XXXX -> XL
	if (xCount == 4){
		lSubtract = 'X';
		xCount -= 4;
	}

	if (vCount == 1 && iCount == 4){
		xSubtract = 'I';
		vCount -= 1;
		iCount -= 4;
	}

	if (iCount == 4){
		vSubtract = 'I';
		iCount -= 4;
	}






	// now, nSubtract contains if a value needs to be subtracted, and nCount contains the rest of the values
	std::string outputValue;
	
	// add M part of the value, could be something like MMM or MCM or MXM maybe even
	outputValue += getCharNTimes('M', mCount);
	if (mSubtract != 0){
		outputValue += mSubtract;
		outputValue += "M";
	}


	outputValue += getCharNTimes('D', dCount);
	if (dSubtract != 0){
		outputValue += dSubtract;
		outputValue += "D";
	}

	outputValue += getCharNTimes('C', cCount);
	if (cSubtract != 0){
		outputValue += cSubtract;
		outputValue += "C";
	}

	outputValue += getCharNTimes('L', lCount);
	if (lSubtract != 0){
		outputValue += lSubtract;
		outputValue += "L";
	}

	outputValue += getCharNTimes('X', xCount);
	if (xSubtract != 0){
		outputValue += xSubtract;
		outputValue += "X";
	}

	outputValue += getCharNTimes('V', vCount);
	if (vSubtract != 0){
		outputValue += vSubtract;
		outputValue += "V";
	}
	outputValue += getCharNTimes('I', iCount);


	


	
	
	
	
	
	
	

	return outputValue;

}




std::string alphabet = "MDCLXVI";
int values[] = {1000, 500, 100, 50, 10, 5, 1};
int toDecimal(std::string in){
	
	int mCount = 0, dCount = 0, cCount = 0, lCount = 0, xCount = 0, vCount = 0, iCount = 0;
	for (int i = 0; i < in.size(); i++){
		for (int ii = 0; ii < alphabet.size(); ii++){
			
		}
		
	}
	
	return 0;
}









// arguments will -again- use the same way as i did in lunaconvert
int main(int argc, char *argv[]){
	// argument handler part 1

	if (argc < 3){

		if (argc == 2 && argv[1][0] == 'h'){
			std::cout << "rn: roman numeral converter\nconverts decimal numbers to roman numerals and vice versa\nuse `rn <options> dddd'\nwhere dddd can be any number\nmultiple options allowed\npossible options:\nh\tshow help\ni\tinverted operation, instead of converting to roman numerals, convert from roman numerals\n";
			return 0;
		}

		std::cout << "error: not enough arguments provided, run `rn h' to get help";
		return -1;
	}

	// argument handler part 2
	bool operateInverted = false;
	while (*(argv[1]) != 0){
		if (*argv[1] == 'i'){
			// operate inverted, instead of greg -> luna, do luna -> gegr
			operateInverted = true;
		}
		*(argv[1])++;
	}


	


	if (operateInverted){

	} 
	else {
		std::cout << toRoman(std::stoi(argv[2]));
	}
	

}