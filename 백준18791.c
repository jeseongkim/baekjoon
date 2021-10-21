/*
https://www.secmem.org/blog/2020/03/18/mult-n/
https://www.acmicpc.net/problem/1187
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxN 5000
#define MaxD (2*MaxN-1)
#define MaxW ((MaxN+63)/64)
#define rootMaxN 71
#define Maxa 71
#define Maxb 2500

typedef unsigned long long ull;
ull set[MaxN][MaxW];

int to_front(int datas[], int idx[], bool TF_a[], int a);
void EGZ_comp(int datas[], int a, int b, bool TF[]);
int getPivot(int data[], int idx[], int start, int end);
void quickSort(int data[], int idx[], int start, int end);
void EGZ_prime(int datas[], int N, bool TF[]);
void EGZ(int datas[], int N, bool TF[]);


int main(int argc, char const* argv[])
{
	int N;
	int datas[MaxD];
	scanf("%d",&N);
	for (int i = 0; i < 2*N-1; ++i)
		scanf("%d",datas+i);
	bool TF[MaxD];
	EGZ(datas, N, TF);
	int flag = 0;
	for (int i = 0; i < 2 * N - 1; ++i)
	{
		if (TF[i])
		{
			if (flag){
				printf(" %d", datas[i]);
			}
			else {
				printf("%d", datas[i]);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("-1");
	return 0;
}

void rshiftor(int N, int k, ull* src, ull* dst) {
    int Nq = (N + 63) >> 6, Nr = N % 64;
    int dq = k / 64, dr = k % 64;
    if (dr)
    {
        ull up, down;
        ull mask = ((ull)1 << (64 - dr)) - 1;
        dst[dq] |= (src[0] & (mask)) << dr;
        for (int i = 1; dq + i < Nq; ++i) {
            up = (src[i] & mask) << dr;
            down = (src[i - 1] & (~mask)) >> (64 - dr);
            dst[dq + i] |= (up | down);
        }
    }
    else {
        for (int i = 0; i + dq < Nq; ++i)
            dst[dq + i] |= src[i];
    }
    if (Nr)
    {
        ull mask = ((ull)1 << Nr) - 1;
        dst[Nq - 1] &= (mask);
    }
}

void lshiftor(int N, int k, ull* src, ull* dst) {
    int Nq = (N + 63) >> 6, Nr = N % 64;
    int dq = k / 64, dr = k % 64;
    if (dr) {
        ull mask = ((ull)1 << dr) - 1;
        ull up, down;
        for (int i = 0; dq + i + 1 < Nq; ++i) {
            down = (src[dq + i] & (~mask)) >> dr;
            up = (src[dq + i + 1] & mask) << (64 - dr);
            dst[i] |= (up | down);
        }
        dst[Nq - dq - 1] |= (src[Nq - 1] & (~mask)) >> dr;
    }
    else {
        for (int i = 0; dq + i < Nq; ++i)
            dst[i] |= src[dq + i];
    }
    // if (Nr) {
    //     ull mask = ((ull)(1) << (64 - Nr)) - 1;
    //     dst[Nq - 1] &= (mask);
    // }
}

void set_addeq(ull src[], ull dst[], int d, int N) {
    rshiftor(N, d, src, dst);
    lshiftor(N, N - d, src, dst);
}


int to_front(int datas[], int idx[], bool TF_a[], int a) {
	int cnt = 0, sum = 0, temp;
	for (int i = 0; i < 2*a-1; ++i)
	{
		if (TF_a[i])
		{
			temp = idx[i];
			sum += datas[temp];
			idx[i] = idx[cnt];
			idx[cnt++] = temp;
		}
		if (cnt == a)
			break;
	}
	return sum;
}

void EGZ_comp(int datas[], int a, int b, bool TF[]) {
	// int idx[MaxN];
	int *idx = (int*)malloc(sizeof(int)*(2*a*b-1));
	for (int i = 0; i < 2 * a * b - 1; ++i)
		idx[i] = i;

	// bool TF_a[2 * Maxa - 1];
	// int datas_a[2 * Maxa - 1];
	// bool TF_b[2 * Maxb - 1];
	// int datas_b[2 * Maxb - 1];
	bool *TF_a = (bool*)malloc(sizeof(bool) * (2*a-1));
	int *datas_a = (int*)malloc(sizeof(int) * (2*a-1));
	bool *TF_b = (bool*)malloc(sizeof(bool) * (2*b-1));
	int *datas_b = (int*)malloc(sizeof(int) * (2*b-1));

	for (int i = 0; i < 2 * b - 1; i++)
	{
		for (int j = 0; j < 2 * a - 1; ++j)
			datas_a[j] = datas[idx[i * a + j]] % a;

		EGZ(datas_a, a, TF_a);
		datas_b[i] = (to_front(datas, idx+(i*a), TF_a, a) / a) % b;
	}

	EGZ(datas_b, b, TF_b);

	for (int i = 0; i < 2 * b - 1; ++i)
	{
		if (TF_b[i])
		{
			for (int j = 0; j < a; ++j)
			{
				TF[idx[i * a + j]] = true;
			}
		}
		else {
			for (int j = 0; j < a; ++j)
			{
				TF[idx[i * a + j]] = false;
			}
		}
	}
	for (int i = a * (2 * b - 1); i < 2 * a * b - 1; ++i)
		TF[idx[i]] = false;

	free(idx);
	free(TF_a);
	free(datas_a);
	free(TF_b);
	free(datas_b);
}

int getPivot(int data[], int idx[], int start, int end) {
	int i = start - 1, j, pivot = data[idx[end]], tmp;
	for (j = start; j < end; j++) {
		if (data[idx[j]] <= pivot) {
			tmp = idx[++i];
			idx[i] = idx[j];
			idx[j] = tmp;
		}
	}
	tmp = idx[i + 1];
	idx[i + 1] = idx[end];
	idx[end] = tmp;
	return i + 1;
}
void quickSort(int data[], int idx[], int start, int end) {
	if (start < end) {
		int pivot = getPivot(data, idx, start, end);
		quickSort(data, idx, start, pivot - 1);
		quickSort(data, idx, pivot + 1, end);
	}
}

void EGZ_prime(int datas[], int N, bool TF[]) {
	if (N == 1) {
		TF[0] = true;
		return;
	}

	// int idx[MaxD];
	int *idx = (int*)malloc(sizeof(int)*(2*N-1));
	for (int i = 0; i < 2 * N - 1; ++i)
		idx[i] = i;
	// for (int i = 0; i < 2*N-1; ++i)
	// {
	// 	printf("%d ",datas[idx[i]] );
	// }
	// printf("\n");

	quickSort(datas, idx, 0, 2 * N - 2);
	
	// for (int i = 0; i < 2*N-1; ++i)
	// {
	// 	printf("%d ",datas[idx[i]] );
	// }
	// printf("\n");	
	// for (int i = 0; i < 2*N-1; ++i)
	// {
	// 	printf("%d ",idx[i] );
	// }
	// printf("\n");
	for (int i = 0; i < N; ++i)
	{
		if (datas[idx[i]] == datas[idx[i + N - 1]])
		{
			for (int j = 0; j < i; ++j)
			{
				TF[idx[j]] = false;
			}
			for (int j = i; j < i + N; ++j)
			{
				TF[idx[j]] = true;
			}
			for (int j = i + N; j < 2 * N - 1; ++j)
			{
				TF[idx[j]] = false;
			}

			free(idx);
			return;
		}
	}

	int word = (N + 63) / 64;
	int suma = 0;
	for (int i = 0; i < N; ++i) {
		suma += datas[idx[i]];
		suma %= N;
		TF[idx[i]] = true;
	}
	for (int i = N; i < 2 * N - 1; ++i)
		TF[idx[i]] = false;

	if (suma == 0){
		free(idx);
		return;
	}

	for (int i = 0; i < word; ++i)
		set[0][i] = 0;
	set[0][suma / 64] = (ull)1 << (suma % 64);
	int i;
	for (i = 1; i < N; ++i)
	{
		//a = datas[idx[i]], b = datas[idx[i+N-1]];
		int d = (datas[idx[i + N - 1]] - datas[idx[i]]) >= 0 ? (datas[idx[i + N - 1]] - datas[idx[i]]) : N + (datas[idx[i + N - 1]] - datas[idx[i]]);
		for (int j = 0; j < word; ++j)
			set[i][j] = set[i - 1][j];
		set_addeq(set[i - 1], set[i], d, N);
		if (set[i][0] & 1)
			break;
	}
	int alphasum = 0;
	for (int j = i; j >= 1; --j)
	{
		int d = datas[idx[j + N - 1]] - datas[idx[j]];
		int ncur = (alphasum - d) >= 0 ? alphasum - d : alphasum - d + N;
		// If alphasum from (prev alphasum) + bi - ai
		// <==> ai, bi becomes false, true
		if ((set[j - 1][ncur / 64] >> (ncur % 64)) & 1)
		{
			TF[idx[j]] = false;
			TF[idx[j + N - 1]] = true;
			alphasum = ncur;
		}
	}
	free(idx);
	return;

}

void EGZ(int datas[], int N, bool TF[]) {
	for (int i = 2; i < N; ++i)
	{
		if (N % i == 0)
			return EGZ_comp(datas, i, N / i, TF);
	}
	return EGZ_prime(datas, N, TF);
}