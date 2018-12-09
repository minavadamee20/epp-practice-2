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
//void practice3(std::string input, int string_position) {
//
//	if (string_position == input.length()) {
//		std::cout << std::endl << "\t\t practice 3 has reached it's end. " << std::endl;
//		return;
//	}
//	if (string_position > input.length()) {
//
//	}
//	
//}

//in practice 3 we want to get an array of numbers and be able to sort them without using any predefined sort functions from the library, the following practice number will use a recursive function to do the same thing
void practice3(int sample_array[]) {
	int *ptr = &sample_array[0];
	int *next = ptr + 1;
	int temp;
	for (int x = 0; x < sizeof(sample_array); x++) {
		ptr = &sample_array[0];
		next = ptr +1;
		
		for(int firstloop = 0; firstloop < sizeof(sample_array); firstloop++) { //next is smaller
			if (*ptr > *next) {
				temp = *ptr;
				*ptr = *next;
				*next = temp;
				ptr++; next++;
			}
			else { ptr++; next++; }
		}
	}

	next = sample_array;
	std::cout << "the new array is: [ ";
	for (int readloop = 0; readloop < sizeof(sample_array)+1; readloop++) {
		std::cout << *next << " ";
		next++;
	}
	std::cout << "]" << std::endl;
	return;
}
/*the problem: the problem that I had a pointer that would point to the beginning of the array (*temp). and everytime I would use temp to store the temporarily store the value, it would point to the first value within the array
because i was not also increasing temp along with the function. 
	Now I could've also just simply also increased temp with the function, but a simple fix was just to make temp an int holder*/


//in practice 4, we'll be asking for an array to be input, meaning the array can be as large as the user wants it to be, and then we'll use the above sort algorithm to find the largest and smallest item within the array. 
void practice4() {
	int array_size;
	int values;
	std::cout << "enter values: ";
	int element_location = 0;
	while (values > 0) {
		std::cin >> values;
	}
	std::cout << "last value: " << values;

	
	
}


int main() {
	//we start practicing recursions. we start with a simple recursion and learn to progress into different types of recursions
	int sample_number = 9;
	practice1(sample_number);

	std::string sample_string = "Hello there!";
	practice2(sample_string);

	int some_array[100] = { 0,5,9,2,1 };
	practice3(some_array);

	practice4();

	
	


	system("pause");
	return 0;
}



// * notes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    *
// * it appears that recursion functions are simply just passing *
// * the function with simple parameters such as				 *
// * function(int num, int num_of_times-1);					     *
// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	     *