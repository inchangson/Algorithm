#include <stdio.h>
typedef struct rect{
	int x1, y1, x2, y2;
}rect;

int getMin(int n1, int n2){
	return (n1 < n2 ? n1 : n2);	
}
int getMax(int n1, int n2){
	return (n1 > n2 ? n1 : n2);	
}
int main(){
	rect r1, r2, r3;
	
	scanf("%d %d %d %d", &r1.x1, &r1.y1, &r1.x2, &r1.y2);
	scanf("%d %d %d %d", &r2.x1, &r2.y1, &r2.x2, &r2.y2);
	
	r3.x1=getMin(r1.x1, r2.x1);
	r3.x2=getMax(r1.x2, r2.x2);
	r3.y1=getMin(r1.y1, r2.y1);
	r3.y2=getMax(r1.y2, r2.y2);
	
	printf("%d %d %d %d\n", r3.x1, r3.y1, r3.x2, r3.y2);
	
	
	return 0;
}
