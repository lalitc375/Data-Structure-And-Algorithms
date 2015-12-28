    #include<iostream>
    #include<cstdio>
    #include<stdlib.h>
    #include<new>
    using namespace std;
    struct btrie
    {
        struct btrie * left, *right;
        long index;
    };

    void initialise(struct btrie *root)
    {
        root->index=0;
        root->left=root->right=NULL;
    }

    void addNumber(struct btrie * root,long Index,long element ,int level)
    {
        if(level==-1) { root->index=Index; return;}
        long x=(element>>level)&1;
        if(x==0)
        {
            if(root->left==NULL){
                root->left=(struct btrie *)malloc(sizeof(struct btrie));
                initialise(root->left);
            }
            addNumber(root->left,Index,element,level-1);
        }
        else
        {
            if(root->right==NULL)
            {
                root->right=(struct btrie *)malloc(sizeof(struct btrie));
                initialise(root->right);
            }
            addNumber(root->right,Index,element,level-1);
        }
    }
     long query2(struct btrie * root, long element, long level)  //To get Xored Term
    {
        if(level==-1 )   return root->index;
        long x=(element>>level)&1;
        if(x==0)
        {
            if(root->right==NULL) return query2(root->left,element,level-1);
            else return query2(root->right,element,level-1);
        }
        else
        {
            if(root->left==NULL) return query2(root->right,element,level-1);
            else return query2(root->left,element,level-1);
        }
    }
    struct Pre
    {
        long A,B;
        long max1;
    };
    int comparator(const void *p, const void *q)
    {
    long l = ((struct Pre *)p)->A;
    long r = ((struct Pre *)q)->A;
    return (l - r);

    }
    long T,i,ele;
    int main()
    {
        struct btrie * root =(struct btrie *)malloc(sizeof(struct btrie));

        scanf("%ld",&T);
        struct Pre Array[T+1];

         long max1=0,max2=0;



    {
        long pre[T+1];
        pre[0]=0;
        addNumber(root,0,0,31);
        for(i=0;i<T;++i)
        {
            scanf("%ld",&ele);
            pre[i+1]=ele^pre[i];
            addNumber(root,i+1,pre[i+1],31);
            Array[i].A=query2(root,pre[i+1],31);
            Array[i].B=i;
            Array[i].max1=pre[i+1]^pre[Array[i].A];
        }
    }
        qsort(Array,T,sizeof(struct Pre ),comparator);
        long FromI[T+1],FromE[T+1];
        FromI[0]=0;
        FromE[0]=0;
        for(i=0;i<T;++i)
        {
         FromI[i+1]=max(FromI[i],Array[i].max1);
        FromE[i+1]=0;
        }
        FromE[T-1]=ele;
        for(i=T-1;i>=0;--i)
        {
            max1=max(max1,Array[i].max1);
            FromE[Array[i].A]=max1;
        }
        max2=FromE[T]+FromI[T];
        for(i=T-1;i>=0;--i)
        {
            FromE[i]=max(FromE[i],FromE[i+1]);
            max2=max(max2,FromI[i]+FromE[i]);
        }
        printf("%ld",max2);
        return 0;
    }
