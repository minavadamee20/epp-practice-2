#include <iostream>
#include <string>
#include <iterator>
#include <vector>
/*pratice1 is simply counting down one by one until it reaches 1, where it returns and thus exiting out of the function practice1.*/
void practice1(int num) {
	//base case scenario
	if (num == 1) {
		std::cout << std::endl << "\t\t the number is now 1. recursion function has stopped" << std::endl;
		return;
	}
	//recursion statements
	if (num >= 1) {
		std::cout << "the current number is: [ " << num << " ]" << std::endl;
	}
	practice1(num - 1);
}//end of practice 1


/*in practice2 we want to take any string and reverse it using recursion*/
void practice2(const std::string &a) {
	size_t num_of_chars = a.size();
	//base case scenario
	if (num_of_chars == 0) {
		std::cout << std::endl << "\t\t the string that holds: [ " << a << " ] has reached it's end. recursion function has stopped" << std::endl;
	}

	//collpased below description: if we want to skip over displaying a space
	/*
	else if (a[num_of_chars - 1] == ' ') {
		num_of_chars--;
		practice2(a.substr(0, num_of_chars - 1));
	}*/

	else {
		std::cout << std::endl << "the letter now is: " << a[num_of_chars - 1];
		practice2(a.substr( 0, num_of_chars - 1));
	}

}//end of practice 2

/*now lets try the above again but without using substring functions. i don't remember if the EPP allows library pre-defined functions such as substring. */
void practice3(std::string input, int string_position) {

	if (string_position == input.length()) {
		std::cout << std::endl << "\t\t practice 3 has reached it's end. " << std::endl;
		return;
	}
	if (string_position > input.length()) {

	}
	
}


int main() {
	//we start practicing recursions. we start with a simple recursion and learn to progress into different types of recursions
	int sample_number = 9;
	practice1(sample_number);

	std::string sample_string = "Hello there!";
	practice2(sample_string);

	practice3(sample_string, 0);


	
	


	system("pause");
	return 0;
}



// * notes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    *
// * it appears that recursion functions are simply just passing *
// * the function with simple parameters such as				 *
// * function(int num, int num_of_times-1);					     *
// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	     *