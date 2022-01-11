#include <stdio.h>

typedef struct student{
	char name[21];
	int k, e, m;
}student;

int main(){
	student _class[10];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s %d %d %d", _class[i].name, &_class[i].k, &_class[i].e, &_class[i].m);
	}
	for(int i = 0; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			student s1 = _class[i];
			student s2 = _class[j];
			if(s1.k + s1.e + s1.m < s2.k + s2.e + s2.m){
				_class[i] = s2;
				_class[j] = s1;
			}
		}
	}
	
	for(int i = 0; i < n; ++i){
		student tmp = _class[i];
		printf("%s %d %d %d %d\n", tmp.name, tmp.k, tmp.e, tmp.m, tmp.k + tmp.e + tmp.m);
	}
	return 0;
}
