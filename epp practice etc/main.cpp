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
				*next = temp;		//a better version of the above algorithm is std::swap (*ptr, *next); and it works all the same
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
/*the problem: the problem was that I had a pointer that would point to the beginning of the array (*temp). and everytime I would use temp to store the temporarily store the value, it would point to the first value within the array
because i was not also increasing temp along with the function. 
	Now I could've also just simply also increased temp with the function, but a simple fix was just to make temp an int holder rather than a int pointer*/












//
////for practice 3 we'll be doing the recursions functions using the practice 3 algorithm, in practice 5 we will try to return a new int array that has been made on the heap
//void practice4(
//	int sample_array[], 
//	int firstcounter, 
//	int secondcounter, 
//	int *ptr,
//	int *next) {	//remember: that in our last function we used the size of the array to know when to stop the array. so we can do that in this case as well.
//														//in this case however we will have to pass a num that will essentially be firstloop variable that was delcared in the second loop, and we'll also pass another variable
//														//that'll act as the first variable x in the first loop function
//
//
//	int temp_value_holder;	//this is to temporarily store the int that is located in *ptr or *next_ptr. 
//
//	//first we need our base case, that says if the array is empty, then we'll return back to the function 
//	if (firstcounter == 0) {
//		ptr = sample_array;
//		std::cout << std::endl << std::endl << "\t\t\t the contents of the new array are: [ ";
//		for (int p = 0; p < sizeof(sample_array) + 1; p++) {
//			std::cout << *ptr << " "; ptr++;
//		}
//		std::cout << " ]" << std::endl;
//		return;
//	}
//	//another case that says if first counter reaches 0 we will return back to the main function 
//	if (secondcounter == 0) {
//		practice4(sample_array, firstcounter--, secondcounter = sizeof(sample_array), ptr = &sample_array[0], next = ptr++);
//	}
//	if (*ptr > *next) {
//		temp_value_holder = *ptr;
//		*ptr = *next;
//		*next = temp_value_holder;
//		practice4(sample_array, firstcounter, secondcounter--, ptr++, next++);
//		/*ptr++; next++;
//		secondcounter--;*/
//	}
//	else 
//		practice4(sample_array, firstcounter, secondcounter--, ptr++, next++);
//
//}






//in practice 4 we'll be using vectors to help further understand vectors, then in the next practice we'll cover recursions using vectors again
std::vector<int> practice4(std::vector<int> v1) {

	std::cout << "\t\t input your values, end your input by inputting a number below 0: ";
	int values;
	while(std::cin>>values && values >= 0){
		v1.push_back(values);
	}
	std::vector<int>::iterator it;
	std::cout << std::endl << "\t end of inputting values." << std::endl << " \t\t new vector that has been created reads: ";
	for (it = v1.begin(); it < v1.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	return v1;
}
//now let's try using the least to greatest algorithm that we obtained in practice 3
std::vector<int> practice5(std::vector<int> v2) {
	std::vector<int>* swap_pointer = new std::vector<int>(v2);
	
	int x = 0;
	std::vector<int>::iterator it = v2.begin();
	std::vector<int>::iterator next_it = v2.begin() + 1;
	std::vector<int>::iterator first_loop = v2.begin();
	
	/*check notes about what is wrong with the below function within the code*/

	it = swap_pointer->begin();
	
	for (first_loop = v2.begin(); first_loop < v2.end(); first_loop++) {	//can this be changed so that it's swap_pointer?
		it = swap_pointer->begin();	//when looping back the first time, the pointer points to the end of the list and the second pointer points to the first element....why?
		next_it = swap_pointer->begin() + 1;
		x = 0;
		for (it = swap_pointer->begin(); it < swap_pointer->end(); it++) {
			
			if (next_it >= swap_pointer->end()) {	//this says that if ht next_pointer is equal to 
				break;
			}
			if (*it>*next_it) {
				std::iter_swap(swap_pointer->begin()+ x, swap_pointer->begin()+ x + 1);
				next_it++;
				x++;
			}
			else { next_it++; x++; }
		}
	}

	std::cout << std::endl << std::endl << "\t\t the new sorted vector looks like: [ ";
	for (it = swap_pointer->begin(); it < swap_pointer->end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << " ]" << std::endl << std::endl << "\t\t we have reached the end of practice 5" << std::endl;

	return *swap_pointer;	//this only returns the first element within the vector, i want to return the entire new vector
}




int main() {
	//we start practicing recursions. we start with a simple recursion and learn to progress into different types of recursions
	int sample_number = 9;
	practice1(sample_number);

	std::string sample_string = "Hello there!";
	practice2(sample_string);

	int some_array[5] = { 0,5,9,2,1 };
	practice3(some_array);

	/*int &ptr = some_array[0];
	int &next = some_array[1];*/
	//practice4(some_array, sizeof(some_array), sizeof(some_array)+1, &ptr, &next);	//for practie 4 we want to cover vectors quickly

	std::vector<int> sample_vector;	//initialized the vector to hold integers and be called sample_vector
	sample_vector = practice4(sample_vector);



	//to-do: SUNDAY
		//make recursions for practice 3
		//go over parsing through a file
	//to-do: MONDAY
		//epp practice online
	practice5(sample_vector);
	


	system("pause");
	return 0;
}



// * notes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    *
// * it appears that recursion functions are simply just passing *
// * the function with simple parameters such as				 *
// * function(int num, int num_of_times-1);					     *
// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	     *