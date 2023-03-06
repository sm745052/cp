    #include<bits/stdc++.h>
    using namespace std;


    char find_char(string st)
    {
        for(int i=0;i<26;i++)
        {
            int flag = 0;
            for(int j=0;j<st.length();j++)
            {
                if(st[j]=='a' + i)
                {
                    flag = 1;
                }
            }
            if(!flag)
            {
                return char('a' + i);
            }
        }
        return '1';
    }





    void solve()
    {
        int n, k;
        cin>>n>>k;
        string st, f_st = "";
        cin>>st;
        map<char, int> g1;
        for(int i=0;i<n;i++)
        {
            g1[st[i]]++;
        }
        int sz = n/k;
        while(k--)
        {
            int p_sz = 0;
            string t_st = "";
            for(auto &i:g1)
            {
                if(i.second>0)
                {
                    i.second--;
                    p_sz++;
                    t_st += i.first;
                    if(p_sz==sz)break;
                }
            }
            // cout<<p_sz<<"?"<<sz<<endl;
            if(p_sz!=sz)
            {
                for (auto i = g1.rbegin(); i != g1.rend(); i++)
                {
                    while(i->second>0)
                    {
                        i->second--;
                        p_sz++;
                        t_st += i->first;
                        if(sz == p_sz)break;
                    }
                    if(sz == p_sz)break;
                }
            }
            // cout<<"tmpst = "<<t_st<<endl;
            f_st += find_char(t_st);
        }
        cout<<f_st<<endl;
    }


    int main()
    {
        int t;
        cin>>t;
        for(int i=0;i<t;i++)
        {
            solve();
        }
        return 0;
    }