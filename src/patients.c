#include <stdio.h>
struct patient{
	int id;
	char* full_name;
	float weight;
	float height;
	char* disease;
	int floor;
};
void display(struct patient *floor1, struct patient *floor2){
	/* Add your logic here */
	// category names
	printf("ID\t\t Full Name\t Weight\t Height\t Disease\t Floor\n");
	// floor 1
	printf("Floor 1:\n");
	printf("---------------------------------------------------------------\n");
	for (int i = 0; i < 5; i++){
		printf("%d\t%s\t%.1f\t%.1f\t%s\t%d\n", floor1[i].id, floor1[i].full_name, floor1[i].weight, floor1[i].height, floor1[i].disease, floor1[i].floor);
	}
	printf("---------------------------------------------------------------\n");
	// floor 2
	printf("Floor 2:\n");
	printf("---------------------------------------------------------------\n");
	for (int i = 0; i < 5; i++){
		printf("%d\t%s\t%.1f\t%.1f\t%s\t%d\n", floor2[i].id, floor2[i].full_name, floor2[i].weight, floor2[i].height, floor2[i].disease, floor2[i].floor);
	}
	printf("---------------------------------------------------------------\n");
}
void swap(struct patient* floor1, struct patient* floor2){
	/* Add your logic here */
	// create temp value
	struct patient temp;
	// iterate through the struct array and swap floor1 and floor2 contents ....
	// You may do directly floor1[0] = floor2[0] in C. 
	// So you need to do similar step inside the for loop?
	// also note you may set the value directly like below:
	// floor1[0].floor = 1;

}
int main(){
	/* Add your logic here */
	// initialize struct (hard coded)
	struct patient floor1[5];
	struct patient floor2[5];
	// Hard coding values:
	//floor1
	floor1[0].id = 10011001;
	floor1[0].full_name = "Alex Crowe";
	floor1[0].weight = 210.5;
	floor1[0].height = 5.6;
	floor1[0].disease = "Tuberculosis";
	floor1[0].floor = 1;

	/* do the same for other floor1 attributes based on the details provided in the lab sheet....*/
	

	//floor2
	floor2[0].id = 10011006;
	floor2[0].full_name = "Chris Miller";
	floor2[0].weight = 251.3;
	floor2[0].height = 6.4;
	floor2[0].disease = "Asthma";
	floor2[0].floor = 2;

	/* do the same for other floor2 attributes based on the details provided in the lab sheet ....*/
	

	// display orig structs
	display(floor1, floor2);
	//swap struct contents
	swap(floor1, floor2);
	// display swapped structs
	display(floor1, floor2);
	return 0;
}