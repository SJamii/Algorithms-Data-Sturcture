#Time Complexity: O(n)
#Space Complexity: O(m)


#include<bits/stdc++.h>
using namespace std;
vector<int> makelps(string pattern)
{
	vector<int>lps(pattern.length());
	int index=0;
	for(int i=1;i<pattern.length();)
	{
		if(pattern[index] == pattern[i])
		{
			lps[i]=index+1;
			index++;
			i++;
		}
		else
		{
			if(index != 0) index = lps[index-1];
			else lps[i] = index,i++;
		}
	}
	return lps;
}
void kmp(string text, string pattern)
{
	vector<int>lps = makelps(pattern);
	int i=0,j=0;
	bool found = false;
	while(i < text.length())
	{
		if(text[i] == pattern[j])
		{
			i++,j++;
		}
		else
		{
			if(j != 0){
				j = lps[j-1];
		    }
		    else i++;
		}
		if(j == pattern.length()) found = true;
	}
	if(found) cout<<"Match Found!!"<<endl;
	else cout<<"Not Found (-_-) "<<endl;
}
int main()
{
	string text; cin>>text;
	string pattern; cin>>pattern;
	
	kmp(text,pattern);
}
