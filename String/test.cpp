#include <stdio.h>
#include <string.h>
int getindex(char c, char* str)
{
	char *found;
	found = strchr(str,c);
	if(found != NULL)
	{
		return (found - str);
	}
	return -1;
}
int checkstring(char * str, char * t)
{
	int i,len2 = strlen(t),index,temp = -1;
	char c;
	if(strcmp(str,t) == 0) return 1;//if both strings are some
	if(t[0] == "\n") return 1;// if other string is an empty string
	for(i = 0; i < len2; i++)
	{
		c = t[i];
		index = getindex(c,str);//getting the index of char c in str
		if(index == -1) return 0;// if not found
		if(index > temp)//returned
		{
			temp = index;
		}
		else return 0;
	}
	return 1;

}

int main()
{
	int T,q,flag,index = 1,i;
	char c, str[100005],t[205];
	fgets(c,1,stdin);
	while(T--)
	{
		printf("Case %d:\n",index);
		index++;
		fgets(str,100005,stdin);
		//printf("%s",str);
		scanf("%d\n",&q);
		while(q--)
		{
			fgets(t,205,stdin);
			//printf("%s",t);
			flag = s(t,str);
			if(flag == 1) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
