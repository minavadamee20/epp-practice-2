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
	std::vector<int>* swap_pointer = new std::vector<int>(v2);	//here we've made a pointer to a vector that has been made on the heap

	
	int x = 0;												//this is used to hold the index at a certain given point within the vector. we use this int index for std::iter_swap
	std::vector<int>::iterator it = v2.begin();				//iterator that is assigned to the passed by value vector (v2)
	std::vector<int>::iterator next_it = v2.begin() + 1;	//iterator that is assigned to the passed by value vector (v2)
	std::vector<int>::iterator first_loop = v2.begin();		//iterator that is used to keep track the first loop of the passed by value vector (v2)
	
	

	it = swap_pointer->begin();					//i don't think we need this reassignment since we do it again within the loop function.....i think
	
	for (first_loop = v2.begin(); first_loop < v2.end(); first_loop++) {	//can this be changed so that it's swap_pointer?
		it = swap_pointer->begin();					//we reassign the iterators back to the beginning of the vector because we are using bubble sort 
		next_it = swap_pointer->begin() + 1;		//check bubble sort online to understand more. 
		x = 0;
		for (it = swap_pointer->begin(); it < swap_pointer->end(); it++) {
			
			if (next_it >= swap_pointer->end()) {	//this says that if next_it points to the end or past the end of the swap_pointer vector, we break out of the second encompassed loop and go back to the first outer loop..
				break;
			}
			if (*it>*next_it) {						//dereferencing it and next_it, so we see if next_it is smaller than it. If so, switch them so that the smsaller value is in front
				std::iter_swap(swap_pointer->begin()+ x, swap_pointer->begin()+ x + 1);				//x is the index needed to use the std::iter_swap
				next_it++;
				x++;
			}
			else { next_it++; x++; }
		}
	}

	std::cout << std::endl << std::endl << "\t\t the new sorted vector looks like: [ ";	//display the new sorted vector (least -> greatest)
	for (it = swap_pointer->begin(); it < swap_pointer->end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << " ]" << std::endl << std::endl << "\t\t we have reached the end of practice 5" << std::endl;

	

	return *swap_pointer;	//this only returns the first element within the vector, i want to return the entire new vector
}



/*EPP practice part One: [NUMBER 1]*/
	//Scores should be read into an array, first ask how many numbers of judges and then enter the contestant scores
			//we should use the loop based on the number of judges that are present.
	//findAverageScore should take the array of judges's scores as arguments. then the functions should drop the highest and lowest score and then find the average
	//should return the average of N-2 scores. so we don't have to return the average

//the program will then print the contestant number who scored the highest. 

double findAverageScore(int* sample_ptr) {
	//first let's sort the array to sort the highest number to be in front of the array and then assign that to be 0.
	//then sort the lowest number to be in front of the array and assignment that to be 0. then take the average and return that back to main
	int temp;
	int *ptr = sample_ptr;
	int* next = ptr++;
	double sum = 0;
	for (int x = 0; x < sizeof(sample_ptr); x++) {
		ptr = &sample_ptr[0];
		next = ptr++;
		for (int second_counter = 0; second_counter < sizeof(sample_ptr); second_counter++) {
			if (*ptr>*next){	//next is smaller
				temp = *ptr;
				*ptr = *next;
				*next = temp;
				ptr++; next++;
			}
			else { ptr++; next++; }
		}
	}

	//assigning the first variable (which is the highest number)
	sample_ptr[0] = 0;
	for (int x = 0; x < sizeof(sample_ptr); x++) {
		ptr = &sample_ptr[0];
		next = ptr++;
		for (int second_counter = 0; second_counter < sizeof(sample_ptr); second_counter++) {
			if (*ptr<*next) {	//next is smaller
				temp = *ptr;
				*ptr = *next;
				*next = temp;
				ptr++; next++;
			}
			else { ptr++; next++; }
		}
	}
	sample_ptr[0] = 0;
	
	for (int x = 0; x < sizeof(sample_ptr); x++) {
		sum += sample_ptr[x];
	}
	return (sum / sizeof(sample_ptr) - 2);
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
	sample_vector=practice4(sample_vector);



	//to-do: SUNDAY
		//make recursions for practice 3
		//go over parsing through a file
	//to-do: MONDAY
		//epp practice online
	practice5(sample_vector);
	
	std::cout << std::endl << std::endl << "\t\t\t Input number of judges: ";
	int num_judges;
	std::cin >> num_judges;
	int *ptr_array = new int[num_judges];

	std::cout << std::endl;
	int cont_num;
	std::cin >> cont_num;

	std::cout << "		";
	int values;
	int x = 0;
	
	while (std::cin >> ptr_array[x] && x < num_judges) {
		x++;
	}

	int** double_ptr = &ptr_array;
	double average = findAverageScore(*double_ptr);
	std::cout << std::endl << "\t\t the average is: [ " << average << " ]";
	


	system("pause");
	return 0;
}



// * notes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    *
// * it appears that recursion functions are simply just passing *
// * the function with simple parameters such as				 *
// * function(int num, int num_of_times-1);					     *
// * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	     *