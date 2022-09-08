#include <stdio.h>
#include <math.h>
void buildTable(int rows){
	/* complete this method here */
	int cols = ceil(log2(rows));
	for(int i=0; i <rows; i++){
		for (int j = cols-1; j >= 0; j--){
			// add your code here
			
		}
		printf("\n");
	}
}
int main(){
	int prompt = 0;
	while(1){
		printf("Please enter the number of rows, (0) for exit:");
			scanf("%d", &prompt);
			getchar();
	
		if (prompt > 0){
			buildTable(prompt);
		}
		else {
			break;
		}
	}	
	
	return 0;
}



