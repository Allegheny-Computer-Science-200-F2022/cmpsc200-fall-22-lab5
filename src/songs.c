#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15 // size indicates total number of songs. 
struct song{
  int s_no;
  int s_count;
  float s_rating;
  float s_duration;
};
void write(char *file){
	// write to file
	FILE *fp = fopen(file, "w+"); // w+ is for write mode for file writing
	int upper = 100, lower = 1;
	float rating = 5.0, duration = 6.5;
	srand(time(0));
	for (int i = 1; i <= SIZE; i++){
		// The following two lines are used to randomly generate the quantity and rating data points. 
		int song_count = (rand() / (double)RAND_MAX) * (upper - lower) + lower;
		float song_rating = (float)rand()/(float)(RAND_MAX/rating);
		float song_duration = (float)rand()/(float)(RAND_MAX/duration);
		fprintf(fp, "%d,%d,%.2f,%.2f\n",i, song_count, song_rating, song_duration);	
	}
    fclose(fp);
}
void load(char *file, struct song* songs){
	// load all the song details from the file and extract song no, count,rating, and duration. 
	int c = 0, index = 0;
	int song_no = 0, song_count = 0;
	float song_rating = 0.0, song_duration = 0.0, multiplier1 = 0.1, multiplier2 = 0.1;
	int f1 = 1, f2 = 0, f3 = 0, f4 = 0;
	FILE *fp = fopen(file, "rb"); // rb is for read mode for file reading
	while ((c=fgetc(fp)) != EOF) { // fgetc is for getting characters from file directly than std stream. 
        // logic here is used to build each song and add it to the struct array.
		if (c == '\n'){ 
			//printf("%d\t%d\t%.2f\t%.2f\n", song_no, song_count, song_rating, song_duration);
			songs[index].s_no = song_no;
			songs[index].s_count = song_count;
			songs[index].s_rating = song_rating;
			songs[index].s_duration = song_duration;
			song_no = 0, song_count = 0, song_rating = 0.0, song_duration = 0.0;
			f1 = 1, f2 = 0, f3 = 0, f4 = 0;
			multiplier1 = 0.1; // reset all the flags and supporting variables ....
			multiplier2 = 0.1; // reset all the flags and supporting variables ....
			index++;

		}
		else{
			if (f1){
				if (c != ','){
					// build song no
					int digit = c - '0';
					song_no = 10*song_no + digit;
				}
				else{
					f2 = 1, f1 = 0;
				}
				
			}
			else if (f2){
				if (c != ','){
					// build the quantity
					int digit = c - '0';
					song_count = 10*song_count + digit;	
				}
				else{
					f2 = 0, f1 = 0, f3 = 1;
				}
				
			}
			else if (f3){
				if (c != ','){
					int digit = c - '0';
					if (f4){
						song_rating = song_rating + digit*multiplier1;	
						multiplier1 /= 10;
					}
					else if (!f4 && c != '.'){
						song_rating = 10*song_rating + digit;	
					}
					if (c == '.')
						f4 = 1;
				}
				else{
					f4 = 0, f3 = 0, f2 = 0, f1 = 0;
				}
			}
			else {
				int digit = c - '0';
				if (f4){
					song_duration = song_duration + digit*multiplier2;	
					multiplier2 /= 10;
				}
				else if (!f4 && c != '.'){
					song_duration = 10*song_duration + digit;	
				}
				if (c == '.')
					f4 = 1;
			}
		}
	}
}
void report(struct song* songs){
	// add your logic here ....
	// produce a report about the songs in the struct array 
	// q1 - find the least played song
	// q2 - find the most played song
	// q3 - find the highly rated song
	// q4 - find the least rated song
	// q5 - find the shortest song
	// q6 - find the longest song
	
	int lps = 0, mps = 0; // least and most played song
	int lrs = 0, mrs = 0; // least and most rated song
	int ss = 0, ls = 0;   // shortest and longest song. 

	for (int i = 0; i < SIZE; i++){
		printf("%d\t%d\t%.2f\t%.2f\n", songs[i].s_no, songs[i].s_count, songs[i].s_rating, songs[i].s_duration);
	}

	// add your logic here to assign the value to the six variables above ... 






	// here we are displaying song id that is why adding 1 ....
	printf("Least played song: %d\n", lps + 1);
	printf("Most played song: %d\n", mps + 1);
	printf("Least ranked song: %d\n", lrs + 1);
	printf("Most ranked song: %d\n", mrs + 1);
	printf("Shortest song: %d\n", ss + 1);
	printf("Longest song: %d\n", ls + 1);
}

int main(){
	char *file = "data.txt";
	struct song* songs;
  	songs = (struct song*)
        malloc(SIZE*sizeof(struct song)); // is this static or dynamic array?
  	write(file);
	load(file, songs);
	report(songs);
	return 0;
}