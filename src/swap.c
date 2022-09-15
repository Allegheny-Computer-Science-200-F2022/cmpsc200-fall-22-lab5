#include <stdio.h>
void swap(int *b1, int *b2, int *b3){
	/* add your logic here ....*/
}
void prompt(int *b1, int *b2, int *b3){
	/* add your logic here ....*/
	
}
int main(){
	int b1 = 0, b2 = 0, b3 = 0;
	prompt(&b1, &b2, &b3);
	printf("%d\t%d\t%d\n", b1, b2, b3);
	swap(&b1, &b2, &b3);
	printf("%d\t%d\t%d\n", b1, b2, b3);
	
	return 0;
}