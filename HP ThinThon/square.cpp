
    //by Lalitc375
    #include<bits/stdc++.h>
    using namespace std;
    const int N = 1035;
    int used1[N], used2[N],l[N], r[N], h[N],covered1[N], covered2[N],n;
    int get_area(int x1, int y1, int x2, int y2, int x3, int y3)
    {
    	return (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1);
    }
    int main(){
        int T,i;
        scanf("%d",&T);

    	while(T--)
    	{
    		scanf("%d",&n);
    		for ( i = 0; i < n; i++)
                scanf("%d %d %d",&l[i],&r[i],&h[i]);


    		for (int i = 0; i < n; i++)
    		{
    			for (int j = i + 1; j < n; j++)
    			{
    				if (l[i]>l[j])
    				{
    					swap(l[i], l[j]);
    					swap(r[i], r[j]);
    					swap(h[i], h[j]);
    				}
    			}
    		}
    		for (int i = 0; i < n; i++)
    		{
    			used1[i] = used2[i] = 0;
    			covered1[i] = covered2[i] = 0;
    		}
    		for (int i = 1; i < n; i++)
    		{
    			int ptr = i - 1;
    			for (int j = i - 2; j >= 0; --j)
    			{
    				if (get_area(r[j], h[j], r[ptr], h[ptr], l[i], 0) >= 0)
    					ptr = j;
    			}
    			if (ptr != i - 1)
    			{
    				covered1[i] = 1;
    				used2[ptr] = 1;
    			}
    		}
    		for (int i = 0; i + 1 < n; i++)
    		{
    			int ptr = i + 1;
    			for (int j = i + 2; j < n; j++)
    			{
    				if (get_area(l[j], h[j], l[ptr], h[ptr], r[i], 0) <= 0)
    					ptr = j;
    			}
    			if (ptr != i + 1)
    			{
    				covered2[i] = 1;
    				used1[ptr] = 1;
    			}
    		}
    		for (int i = 0; i+1 < n; i++)
    		{
    			if (covered2[i] && covered1[i + 1])
    				continue;
    			if (used2[i] == 0 && used1[i + 1] == 0)
    			{
    				used2[i] = 1;
    			}
    		}
    		int ans = 2;
    		for (int i = 0; i < n; i++)
    		{
    			ans += used1[i] + used2[i];
    		}
    		printf("%d\n",ans);
    	}
    	return 0;
    }

