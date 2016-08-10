function processData(input) {
    //Enter your code here
    var j=JSON.parse(input);
    var s=j['speed'];
    var temps=j['inputs'];
    var init=j['initialTemperature'];
    var endTime=new Date(j['endTime']);
    
    var prevTime=new Date(temps[0]['time']);
    l=temps.length;
    if(l>1)
    {    
        var i;  
        for(i=0;i<l-1;i++)
        {
            var d1= new Date(temps[i]['time']);
            var d2= new Date(temps[i+1]['time']);
            var diff=(d2-d1)/3600000;
            //console.log(diff);
            var tmp=temps[i]['temperature'];
            if(tmp>=init)
                init=Math.min(tmp,init+s*diff);
            else 
                init=Math.Max(tmp,init-s*diff);
        }    
        var d1=new Date(temps[l-1]['time']);
        var tmp=temps[l-1]['temperature'];
        var diff=(endTime-d1)/3600000;
        if(tmp>=init)
            init=Math.min(tmp,init+s*diff);
        else 
            init=Math.Max(tmp,init-s*diff);
        //console.log(diff);

          console.log(init);
    }
    else
        {
            var t1=new Date(endTime);
            var t2=new Date(temps[0]['time']);
            var diff=(t1-t2)/3600000;
            var tmp=temps[0]['temperature'];
            if(tmp>=init)
                init=Math.min(tmp,init+s*diff);
            else
                init=Math.max(tmp,init-s*diff);
                console.log(init);
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
