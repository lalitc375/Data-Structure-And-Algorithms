#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l;
    cout<<"Welcome!!\n type 1 for parent \n type 2 for student account \n type zero for exit"<<endl;
    cin>>i;
    while(i)
    {
             if(i==1)
            {
            cout<<"\n\n\n****Welcome Parent \n type 1 to get Notification \n type 2 to view results \n type 0 zero for exit \n\n\n";
            string Notification[]={"xyz","Test","PTM","TEST"};
            string subjects[]={"Math","Physics","Chemistry","Biology"};
            int Marks[]={85,65,86,90};
            cin>>j;
            while(j)
            {
                if(j==1)
                {
                    for(k=0;k<4;++k)
                    {
                        cout<<k+1<<". "<<Notification[k]<<endl;
                    }
                }
                else if(j==2)
                {
                    cout<<"Subject wise Marks"<<endl;
                    for(k=0;k<4;++k)
                    {
                        cout<<subjects[k]<<" "<<Marks[k]<<endl;
                    }
                }
                cout<<"\n\n\n****Welcome Parent \n type 1 to get Notification \n type 2 to view results \n type 0 zero for exit \n\n\n";
                 cin>>j;
            }


            }
            else if(i==2)
            {
                string subjects[]={"Math","Physics","Chemistry","Biology"};
            int Marks[]={85,65,86,90};

                cout<<"Subject wise Marks"<<endl;
                    for(k=0;k<4;++k)
                    {
                        cout<<subjects[k]<<" "<<Marks[k]<<endl;
                    }
            }
            cout<<"\n\n\nWelcome!!\n type 1 for parent \n type 2 for student account \n type zero for exit"<<endl;
            cin>>i;

    }
   return 0;

}
