
console.log("calcule la suma de los terminos de la serie de FIBONACCI cuyos valores se encuentran entrre 100 y 10,000")
var fibo =[];
var a=0;
var b=1;
var c;
while (true) {
    c=a+b;
    if (c>=100 && c<=10000) {
        fibo.push(c);
    }
    else if (c>100) {
        break;
    }
    a=b;
    b=c;
}


var suma = fibo.reduce(function(acum, num){
    return acum+num
})
console.log("respuesta : "+suma)
