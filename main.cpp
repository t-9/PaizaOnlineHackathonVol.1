#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main() {

	int N, m, D;

	scanf("%d", &N);
	scanf("%d", &D);

	int *p = new int[N];

	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}

	std::sort(p, p + N);

	for (int i = 0; i < D; i++) {
		scanf("%u", &m);


		if (p[0] + p[1] > m) {
			printf("0\n");
		} else {

			int freePrice = 0;

			for(int j = 0; j < N; j++) {

				int *addrPos = std::lower_bound(p + j + 1, p + N, m - p[j]);
				int pos = (int)(addrPos - p);

				if (p[j] + p[pos] == m) {
					freePrice = m;
					break;
				}

				if (pos > j + 1) {
					int sum = p[j] + p[pos - 1];
					if (sum > freePrice) {
						freePrice = sum;
					}
				}
			}
			printf("%d\n", freePrice);
		}
	}

	delete p;

	return 0;
}