function processData(input) {
    //Enter your code here
    var In=JSON.parse(input);
    //console.log(j);
    var px1=In['p1']['start'][0];
    var py1=In['p1']['start'][1];
    var px2=In['p2']['start'][0];
    var py2=In['p2']['start'][1];
    //console.log(px1,py1,px2,py2);
    var i;
    var path1=In['p1']['path'];
    var path2=In['p2']['path'];
    l=path1.length
    var ans=0;
    for(i=0;i<l;i++)
        {
            if(px1==px2 && py1==py2)
                break;
            if(path1[i]=='R')
                px1++;
            if(path1[i]=='L')
                px1--;
            if(path1[i]=='U')
                py1++;
            if(path1[i]=='D')
                py1--;
            
            if(path2[i]=='R')
                px2++;
            if(path2[i]=='L')
                px2--;
            if(path2[i]=='U')
                py2++;
            if(path2[i]=='D')
                py2--;
            ans++;
        }
    console.log(''+px1+','+py1+' '+ans)
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
