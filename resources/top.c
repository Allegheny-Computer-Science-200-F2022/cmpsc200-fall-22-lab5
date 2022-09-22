#include <stdio.h>
int main(){
	int arr[] = {1,2,3,4,5,5,4,3,2};
	int times = 0, rindex = 0;
	int max = 0;
	while (times < 3){
		max = arr[0];
		rindex = 0;
		for (int i = 1; i < 9; i++){
			if (max < arr[i]){
				max = arr[i];
				rindex = i;
			}
		}
		arr[rindex] = 0;
		printf("Top element (%d) with a position %d and a value %d\n", times +1, rindex, max);
		times++;
	}
	return 0;
}