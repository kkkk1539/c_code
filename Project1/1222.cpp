#define _CRT_SECURE_NO_WARNINGS 1

#define N 2

int trun;
bool flag[N];
void process(int i) {
	while (1) {
		flag[i] = true;
		int trun = 1 - i;
		while (flag[1 - i] && trun == 1 - i);
		//critical section;
		flag[i] = false;
		//remainder section;
	}
}