/**
  Ivo Karagyozov
 */
#include <iostream>
#define endl '\n'
using namespace std;

char ch;
long long n, perm[105], pos, result, r, p[105];

void init()
{
	for(int i=0; i<n; i++)
	{
		p[i]=i+1;
	}
}
long long codePermutation(int n, long long *perm)
{
	long long *p = new long long[n+1], res = 0, tmp;
	for(int i = 1; i <= n; i++)
		p[i-1] = i;

	for(int pos = 0; pos < n; pos++)
	{
		tmp = 0;
		while(perm[pos] != p[tmp])
			tmp++;
		res = res * (n-pos) + tmp;
		for(int i = tmp + 1; i < n; i++)
			p[i-1] = p[i];
	}

	return res;
}
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ind = 0;
	while(1)
	{
		cin>>perm[ind++];
		cin.get(ch);

		if(ch == '\n') break;
	}
	n = ind + 1;

	cout<<codePermutation(n, perm)<<endl;
}

int main()
{
	input();
	return 0;
}
