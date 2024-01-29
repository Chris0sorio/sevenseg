#define MAX_LEN 100
#include<stdio.h>

void horizontal(void){
	
}

void main(void){
	printf("This is a 7-segment display! Press \"Enter\" after providing any number in keyboard.\n");
	int segment_width;//width of horizontal segments in the 7-segment display
	int segment_length; //length of verticle segments in the 7-segment display
	int segment_integer;
	int input_error;//flag to show whether some error is detected in user's input
	char horizontalInput[MAX_LEN + 1];//placeholder to hold user's horizontal input from keyboard
	char verticalInput[MAX_LEN + 1];//placeholder to hold user's vertical input from the keyboard
	char integerInput[MAX_LEN + 1];//placeholder to hold user's positive integer input from the keyboard
	while(1){
		printf("Please enter the width of horizontal segments (from 3 to 40):\n");
		input_error = segment_width = 0;
		for(int i = 0; i < MAX_LEN;i++){
			if(i == 3){//Given input must be a 1 or 2-digit positive integer.
				input_error = 1;
				break;
			}
			horizontalInput[i] = getchar();
			if(horizontalInput[i] == '\n'){//end of user's input
				horizontalInput[i] = '\0';
				break;
			}else if(horizontalInput[i] < '0' || horizontalInput[i] > '9'){//not a digit is given by user
				input_error = 1;
				break;
			}else
				segment_width = 10 * segment_width //accounts for previously entered digits...
					+ (horizontalInput[i] - '0')//converting ASCII code of string[i] to its numerical value...
					;//converting the number entered by user to an integer...
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(segment_width < 3 || segment_width > 40 || input_error)
			printf("The given value is not acceptable!\n");
		else
			break;
			
	}

	while(1){
		printf("Now, enter the length of the vertical segments (from 3 to 40): \n");
		input_error = segment_length = 0;
		
		for(int i = 0; i < MAX_LEN; i++){
			verticalInput[i] = getchar();
			if(verticalInput[i] == '\n'){
				verticalInput[i] = '0';
				break;
			}else if(verticalInput[i] < '0' || verticalInput[i] > '9'){
				input_error = 1;
				break;
			}else{
				segment_length = 10 * segment_length + (verticalInput[i] - '0');
			}
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(segment_length < 3 || segment_length > 40 || input_error || segment_length>(segment_width*2) || segment_length < (.5*segment_width))
			printf("The given value is not acceptable!\n");
		else
			break;

	}

	while(1){
		printf("Enter a positive integer: \n");
		input_error = segment_integer = 0;
		for(int i = 0; i < MAX_LEN; i++){
			integerInput[i] = getchar();
			if (integerInput == '\n'){
				integerInput[i] = '0';
				break;
			}else if (integerInput[i] < '0' || integerInput[i] > '9'){
				input_error = 1;
				break;
			}else{
				segment_integer = 10 * segment_integer + (integerInput[i] - '0');
			}
		}
		if(input_error)//if an error found in user's input
			while(getchar()!= '\n');//gets rid of the remaining of user's input in the same line
		if(input_error || segment_integer < 0)
			printf("The given value is not acceptable, try entering a positive integer!\n");
		else
			break;	
	}
	// char c = getchar();
	// while(c != EOF)
	// 	c = getchar();
	// printf("END");
 
}