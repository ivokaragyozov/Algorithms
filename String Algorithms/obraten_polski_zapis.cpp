/**
Ivo Karagyozov
*/
#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;

string s, num, pols;
stack<char> st1;
stack<int> st2;

int prior(char ch)
{
    if(ch=='+' || ch=='-')return 1;
    else if(ch=='*' || ch=='/')return 2;
    return 0;
}
void make()
{
    bool p=false;

    for(int i=0; i<s.size(); i++)
    {
        while(s[i]>='0' && s[i]<='9')
        {
            num+=s[i];
            i++;
            p=true;
        }
        if(p)
        {
            i--;
            p=false;
            pols=pols+num+',';
            num="";
        }
        else if(s[i]!='(' && s[i]!=')')
        {
            int pr=prior(s[i]);
            while(!st1.empty() && prior(st1.top())>=pr)
            {
                pols=pols+st1.top()+',';
                st1.pop();
            }
            st1.push(s[i]);
        }
        else
        {
            if(s[i]=='(')st1.push(s[i]);
            else
            {
                while(!st1.empty() && st1.top()!='(')
                {
                    pols=pols+st1.top()+',';
                    st1.pop();
                }
                st1.pop();
            }
        }
    }
    while(!st1.empty())
    {
        pols=pols+st1.top();
        st1.pop();
    }
}
void calc()
{
    for(int i=0; i<pols.size(); i++)
    {
        if(pols[i]==',')continue;
        if(pols[i]>='0' && pols[i]<='9')
        {
            int n=0;
            while(pols[i]!=',')
            {
                n=n*10+(pols[i]-'0');
                i++;
            }
            st2.push(n);
        }
        else
        {
            int a, b, c;
            a=st2.top();
            st2.pop();
            b=st2.top();
            st2.pop();
            if(pols[i]=='+')
            {
                c=b+a;
            }
            else if(pols[i]=='-')
            {
                c=b-a;
            }
            else if(pols[i]=='*')
            {
                c=b*a;
            }
            else
            {
                c=b/a;
            }
            st2.push(c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    make();
    calc();

    cout<<st2.top()<<endl;
    return 0;
}
