function processData(input) {
    //Enter your code here
    var lis=[];
    var a=input.split('\n');
    for(var i=1;i<a.length;i++)
        {
            var x=a[i].split(': ');
            //console.log(x);
            var t=x[1],c=0;
            for(var j=0;j<t.length;j++)
                if(t[j]=='(')
                    c++;
            t=t.slice(c,t.length)
            if(t==')')
                {
                    lis.push([0,x[0].trim()]);
                    continue;
                }
            t=t.split(')');
            t=t.slice(0,t.length-1);
            l=t.length;
            var arg=[];
            var sum=0;
            for(var j=0;j<l;j++)
                {
                    arg.push(Number(t[j]));
                    sum+=Number(t[j]);
                }
            lis.push([sum,x[0].trim()]);
        }
    for(var i=0;i<lis.length;i++)
        for(var j=i+1;j<lis.length;j++)
            {
                if(lis[i][0]>lis[j][0])
                    {
                        var temp=lis[i];
                        lis[i]=lis[j];
                        lis[j]=temp;
                    }
            }
    for(var i=0;i<lis.length;i++)
        console.log(lis[i][1]+'.');
    
} 

process.stdin.resume();
process.stdin.setEncoding("ascii");
_input = "";
process.stdin.on("data", function (input) {
    _input += input;
});

process.stdin.on("end", function () {
   processData(_input);
});
