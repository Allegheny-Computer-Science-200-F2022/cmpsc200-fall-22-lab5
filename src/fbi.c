#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100 // size indicates total number of location numbers. 
void write(char *file){
	// write to file
	FILE *fp = fopen(file, "w+"); // w+ is for write mode for file writing
	int upper = 100000, lower = 10001;
	srand(time(0));
	for (int i = 1; i <= SIZE; i++){
		int location = (rand() / (double)RAND_MAX) * (upper - lower) + lower;
		if (i % 5 == 0 && (i > 1 && i < SIZE))
			fprintf(fp, "%d\n", location);	
		else
			fprintf(fp, "%d\t", location);	
	}
    fclose(fp);
}
void load(char *file, int *arr){
	// load all the locations (lat/long) from the file into the array arr. 
	int c = 0;
	int location = 0;
	int index = 0;
	FILE *fp = fopen(file, "rb"); // rb is for read mode for file reading
	while ((c=fgetc(fp)) != EOF) { // fgetc is for getting characters from file directly than std stream. 
        // develop your logic here to build each location and add it to the array.
 		if (c == '\t' || c == '\n') { /* Check for error in input */
			*(arr + index) = location;
			location = 0;
			index++;
 		}
 		else{
			 int digit = c -'0';
			 location = 10* location + digit;
		}
 	}
}
void transform(int *arr, int *twod, int rows){
	/* add your code here ... */
}
void report1(int *arr){
	/* add your code here ... */
}

void report2(int *twod, int rows){
	/* add your code here ... */
}
void suspect(int *twod, int rows){
	/* add your code here ... */
}
int main(){
	char *file = "data.txt";
	int *arr = (int *) malloc(SIZE*sizeof(int)); //dynamic array
	int states = 9; // number of states, that is number of rows in 2d array ...
	int twod[9][2] = {{1,0},{2,0},{3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, {9,0}}; 
	write(file);
	load(file, arr);
	printf("----------------------------------------------\n");
	report1(&arr[0]);
	printf("----------------------------------------------\n");
	transform(arr, &twod[0][0], states);
	report2(&twod[0][0], states);
	printf("----------------------------------------------\n");
	suspect(&twod[0][0], states);
	return 0;
}