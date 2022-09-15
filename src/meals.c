#include <stdio.h>
void stats(int h1[], int h2[], int h3[], int h4[], int h5[], int student_count){
	/* add your logic here */
}
void ratings(int h1[], int h2[], int h3[], int h4[], int h5[], int student_count){
	/* add your logic here */
}
int main(){
	int student_count = 0;
	printf("Enter the number of students: ");
	scanf("%d", &student_count);
	int h1[student_count], h2[student_count], h3[student_count], h4[student_count], h5[student_count];
	printf("-----------------------------------\n");
	ratings(h1, h2, h3, h4, h5, student_count);
	printf("-----------------------------------\n");
	stats(h1, h2, h3, h4, h5, student_count);
	printf("-----------------------------------\n");
	return 0;
}