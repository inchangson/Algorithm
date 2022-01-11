#include <stdio.h>
typedef struct point{
	int x, y;
}pt;
int main(){
	pt triangle[3];
	int sumX = 0;
	int sumY = 0;
	for(int i = 0; i < 3; ++i){
		scanf("%d %d", &triangle[i].x, &triangle[i].y);
		sumX += triangle[i].x;
		sumY += triangle[i].y;
	}
	printf("(%.1lf, %.1lf)\n", sumX/3.0, sumY/3.0);
	return 0;
}
