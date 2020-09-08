#include<stdio.h>
#include<stdlib.h>
#define MAX 20000  // スタックの最大値

typedef struct {
	int top;         // スタックポインタ(一番上の位置)
	int S[MAX];
} Stack;


// スタック st の初期化
void initialize(Stack *st)
{
	st->top = 0;
	st->S[st->top] = 0;
}

// スタック st が空かどうかを確認
int isEmpty(Stack *st)
{
	return st->top == 0;
}

// スタック st が一杯かどうかを確認
int isFull(Stack *st)
{
	return st->top >= MAX - 1;
}

// スタック st に要素 x をプッシュ(一番上に要素を追加)
void push(int x, Stack *st)
{
	if (isFull(st))
		exit(1);

	st->top++;
	st->S[st->top] = x;
}

// スタック st から要素をポップ(一番上の要素を取り出す)
int pop(Stack *st) {
	if (isEmpty(st))
		exit(1);

	st->top--;
	return st->S[st->top+1];
}


int main(void)
{
	Stack st1;     // '\' の開始位置を格納するスタック
	Stack st2_j;   // 各水たまりの最も左の'\' の位置を格納するスタック
	Stack st2_a;   // 各水たまりの水量を格納するスタック

	// スタック初期化
	initialize(&st1);
	initialize(&st2_j);
	initialize(&st2_a);

	char c;
	int sum = 0;  // 水たまりの総水量

	// 地形を読み込み，各水たまりの水量を計算
	for (int i = 0; (c = getchar()) != EOF; i++) {
		if (c == '\\') {                                 // '\' が出た時の処理
			push(i,&st1);	// 位置 i を st1 にプッシュ(write your code)
			
		} else if (!isEmpty(&st1) && c == '/') {          // '/' が出た時の処理
			int j=pop(&st1);
			sum += i-j;
			// 水たまりの総水量 sum を更新(write your code)

			// st2_j と st2_a を用いて水たまりの水量を更新
			int a = i - j;   // 更新する水たまりの水量を a に格納していく
			while (!isEmpty(&st2_j) && st2_j.S[st2_j.top] > j) {  // 最も左の '\' の位置が j よりも大きい場合，以下を繰り返す
				pop(&st2_j);
				a+=pop(&st2_a);	// 水たまりの水量を求めていく (write your code)
			}
			push(a,&st2_a);
			push(j,&st2_j);// 更新した水たまりの「最も左の'\' の位置」および「水量」を更新 (write your code)
		}
	}

	printf("%d\n", sum);       // 水たまりの総水量を出力
	printf("%d", st2_a.top);   // 水たまりの個数を出力

	// 各水たまりの水量を断面図の左から出力(スタックの底から出力)
	for (int i = 1; i <= st2_a.top; i++)
		printf(" %d", st2_a.S[i]);
	printf("\n");

	return 0;
}
