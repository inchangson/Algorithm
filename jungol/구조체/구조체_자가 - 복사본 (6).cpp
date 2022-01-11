#include <stdio.h>
#include <string.h>

typedef struct s{
	char name[21];
	int h;
	double w;
}s;
int main(){
	s arr[5];
	
	for(int i = 0; i < 5; ++i){
		scanf("%s %d %lf", arr[i].name, &arr[i].h, &arr[i].w);
	}
	
	printf("name\n");	
	for(int i = 0; i < 4; ++i){
		for(int j = i + 1; j < 5; ++j){
			s a1 = arr[i];
			s a2 = arr[j];
			if(strcmp(a1.name, a2.name) > 0){
				arr[i] = a2;
				arr[j] = a1;
			}
		}
	}
	
	for(int i = 0; i < 5; ++i){
		printf("%s %d %.1lf\n", arr[i].name, arr[i].h, arr[i].w);
	}		
	
	printf("\nweight\n");	
	for(int i = 0; i < 4; ++i){
		for(int j = i + 1; j < 5; ++j){
			s a1 = arr[i];
			s a2 = arr[j];
			if(a1.w < a2.w){
				arr[i] = a2;
				arr[j] = a1;
			}
		}
	}
	
	for(int i = 0; i < 5; ++i){
		printf("%s %d %.1lf\n", arr[i].name, arr[i].h, arr[i].w);
	}
	
	return 0;
}
