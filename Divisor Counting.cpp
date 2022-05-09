bool marked[100007];
vector<int>v;
int factorize(ll n)
{
    int sq=sqrt(n);
    int res=1;
    for(int i=0;i<v.size()&&v[i]<=sq;i++)
    {
        if(n%v[i]==0)
        {
            int c=0;
            while(n%v[i]==0)
            {
                n/=v[i];
                c++;
            }
            sq=sqrt(n);
            c++;
            res*=c;
        }
    }
    if(n!=1)
    {
        res*=2;
    }
    return res;
 
}
