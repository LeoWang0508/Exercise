#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char des[], const char src[]) {
	assert((des!=NULL) && (src!=NULL));
	char *ptr = des;
	while((*des++=*src++)!='\0');
	return ptr;
}

int my_strlen(char des[]) {
	int count = 0;
	while((*des++)!='\0') {
		count++;
	}
	return count;
}

char* my_strcat(char des[], const char src[]) {
	assert((des!=NULL) && (src!=NULL));
	char *ptr = des;
	while(*des != '\0'){
		des++;
	}
	while(*des++ = *src++);
	return ptr;
} 

int my_strcmp(const char *s1, const char *s2) {
	while(*s1==*s2) {
		if (*s1 == '\0') {
			return 0;
		}
		*s1++;
		*s2++;
	}
	return *s1-*s2 > 0 ? 1 : -1;
}
int main() {

	char a[10] = "hello";
	char b[10] = "ok!!!!";
	printf("%d\n", my_strcmp(a,b));
	char *e = my_strcpy(a,b);
	printf("%s %s\n", a, e);
	int d = my_strlen(a);
	printf("%d\n", d);
	char *c = my_strcat(a,b);
	printf("%s %s\n", c, a);
	
	return 0;
}
