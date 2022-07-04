#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T, K;
int sum[501], file[501], dp[501][501];

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> K;

		for (int i = 1; i <= K; i++)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}


		for (int i = 1; i <= K; i++) // i : 범위
		{
			for (int j = 1; j <= K - i; j++) // j : 파일 합칠 때 시작
			{
				dp[j][j + i] = 1000000000;
				for (int k = j; k < j + i; k++) // k : 구해야 하는 범위를 두 부분으로 나누는 기준점
				{
					dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j+ i] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << endl;

	}

}
