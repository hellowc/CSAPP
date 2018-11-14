#include <stdio.h>

void good_echo(void) {
	char buf[12];
	while(1) {
		char* p = fgets(buf, 12, stdin);
		if(p == NULL) {
			break;
		} else {
			printf("%s", p);
		}
	}
	return;
}

int main(int argc, char* argv[]) {
	good_echo();
	return 0;
}
