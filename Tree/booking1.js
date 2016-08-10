function processData(input) {
    var i=0,j=0;
    
    for(i=1;i<10000;i++)
    {
        var flag=1;
        var str=i.toString();
        
        for(var j=0;j<str.length;j++)
        {
            if((str[j]=='4') || (j<str.length-1 && str[j]=='1' && str[j+1]=='3'))
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            ++j;
            if(j==input)
            {

                conole.log(i); 
                break;      
            }
        }
    }
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

