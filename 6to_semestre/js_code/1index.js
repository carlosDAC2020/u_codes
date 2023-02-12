//               NOTAS 

// VARAIBLES TIPOS DE DATOS Y OPERDORES -------------------------------
// js tiene los tipos de datos comunes 
// como numero enteros flotantes str buleanos y predefinidos como undefined o null

// js maneja tambien los tipicos operadores tanto aritmeticos como de comparacion y asignacion BUSCAR UNA TABLA 

//                  comparacion 
//  "==": Este operador se utiliza para comparar si dos valores son iguales, realizando una comparación de tipo "coerción" antes de comparar los valores si es necesario.
// "===": Este operador se utiliza para comparar si dos valores son iguales y del mismo tipo, no realizando una comparación de tipo "coerción" antes de comparar los valores.
// "!=": Este operador se utiliza para comparar si dos valores son diferentes, realizando una comparación de tipo "coerción" antes de comparar los valores si es necesario.
// "!==": Este operador se utiliza para comparar si dos valores son diferentes o de distinto tipo, no realizando una comparación de tipo "coerción" antes de comparar los valores.
// ">": Este operador se utiliza para comparar si un valor es mayor que otro.
// "<": Este operador se utiliza para comparar si un valor es menor que otro.
// ">=": Este operador se utiliza para comparar si un valor es mayor o igual que otro.
// "<=": Este operador se utiliza para comparar si un valor es menor o igual que otro.

//              LOGICOS
//  "&&" (and): Este operador evalúa si dos o más expresiones son verdaderas. Devuelve verdadero si ambas expresiones son verdaderas, de lo contrario devuelve falso.
//  "||" (or): Este operador evalúa si al menos una de dos o más expresiones es verdadera. Devuelve verdadero si al menos una expresión es verdadera, de lo contrario devuelve falso.
//  "!" (not): Este operador invierte el valor lógico de una expresión. Devuelve verdadero si la expresión es falsa, de lo contrario devuelve falso.
//  "^": Este operador evalúa si solo una de dos expresiones es verdadera. Devuelve verdadero si solo una expresión es verdadera, de lo contrario devuelve falso.
 
// CONDICIONALES ----------------------------------------------------------------
// en js los condicionales se man ejan de forma similar a python en lo que se refiere al if y else 
// teniendo en cuenta que el elif aca no existe si no que se usa el else if como en c++


//en js existe un tipo de condicional ternario el cual funciona como un if y elese pero en una sola linea por ejemplo 
var n=1;
var resultado = n===1 ? "soy uno":" no soy uno ";

// en js tambien existe el swith como en c++ y se usa de la misma manera a demas de que su sintaxis es similar (SIEMPRE COLOCAR EL BREAK O SI NO SE ENTRARA A CADA CASO )


//  LISTAS -----------------------------------------------------------
// aca tambien usamos las listas o arrays como les dicen 
// los declaramos con corchetes y cada uno de sus elementos los separa mos por comas 

var lista = [1,2,3,"hola","adios",true,false,3.14]

// a demas de que pueden ser manipulados a traves de algunas metodos los cuales son 

// push(): agrega uno o más elementos al final del array.
let frutas = ['manzana', 'platano'];
frutas.push('mango');
console.log(frutas); // ['manzana', 'platano', 'mango']


// pop(): elimina el último elemento del array y lo devuelve.
//let frutas = ['manzana', 'platano', 'mango'];
let ultimaFruta = frutas.pop();
console.log(frutas); // ['manzana', 'platano']
console.log(ultimaFruta); // 'mango'


// shift(): elimina el primer elemento del array y lo devuelve.
//let frutas = ['manzana', 'platano', 'mango'];
let primeraFruta = frutas.shift();
console.log(frutas); // ['platano', 'mango']
console.log(primeraFruta); // 'manzana'


// unshift(): agrega uno o más elementos al principio del array.
//let frutas = ['platano', 'mango'];
frutas.unshift('manzana');
console.log(frutas); // ['manzana', 'platano', 'mango']


// slice(): devuelve una copia de una sección del array.
//let frutas = ['manzana', 'platano', 'mango', 'pera', 'uva'];
let frutasVerdes = frutas.slice(0, 2);
console.log(frutas); // ['manzana', 'platano', 'mango', 'pera', 'uva']
console.log(frutasVerdes); // ['manzana', 'platano']


// splice(): agrega o elimina elementos de un array.
//let frutas = ['manzana', 'platano', 'mango', 'pera', 'uva'];
frutas.splice(1, 2, 'naranja', 'kiwi');
console.log(frutas); // ['manzana', 'naranja', 'kiwi', 'pera', 'uva']


// concat(): une dos o más arrays y devuelve un nuevo array.
let frutas1 = ['manzana', 'platano', 'mango'];
let frutas2 = ['pera', 'uva'];
let todasFrutas = frutas1.concat(frutas2);
console.log(todasFrutas); // ['manzana', 'platano', 'mango', 'pera', 'uva']


// join(): une todos los elementos de un array en una cadena.
//let frutas = ['manzana', 'platano', 'mango'];
let frutasString = frutas.join(', ');
console.log(frutasString); // "manzana, platano, mango"


// sort(): ordena los elementos de un array.
//let frutas = ['manzana', 'platano', 'mango', 'pera', 'uva'];
frutas.sort();
console.log(frutas); // ['manzana', 'mango', 'pera', 'platano', 'uva']



// reverse(): invierte el orden de los elementos de un array.
//let frutas = ['manzana', 'platano', 'mango', 'pera', 'uva'];
frutas.reverse();
console.log(frutas); // ['uva', 'pera', 'mango', 'platano', 'manzana']


// map(): crea un nuevo array con los resultados de una función aplicada a cada elemento del array origina//l.
let numeros = [1, 2, 3, 4, 5];
let numerosDuplicados = numeros.map(function(numero) {
    return numero * 2;
});
console.log(numerosDuplicados); // [2, 4, 6, 8, 10]


// filter(): crea un nuevo array con los elementos que cumplen una condición específic//a.
//let numeros = [1, 2, 3, 4, 5];
let numerosImpares = numeros.filter(function(numero) {
    return numero % 2 !== 0;
});
console.log(numerosImpares); // [1, 3, 5]

// reduce(): reduce los elementos de un array a un solo valo//r.
//let numeros = [1, 2, 3, 4, 5];
let suma = numeros.reduce(function(acumulador, numero) {
    return acumulador + numero;
}, 0);
console.log(suma); // 15

// forEach(): ejecuta una función para cada elemento de un array.
////let frutas = ['manzana', 'platano', 'mango', 'pera', 'uva'];
frutas.forEach(function(fruta) {
    console.log(fruta);
});
// Output: "manzana" "platano" "mango" "pera" "uva"


// indexOf(): devuelve la posición de la primera aparición de un elemento específico en un array.

// find(): devuelve el primer elemento que cumpla una condición específica.
//let numeros = [1, 2, 3, 4, 5, 6];
let numeroEncontrado = numeros.find(function(numero) {
    return numero > 4;
});
console.log(numeroEncontrado); // 5



// findIndex(): devuelve la posición del primer elemento que cumpla una condición específica.
//let numeros = [1, 2, 3, 4, 5, 6];
let indexNumeroEncontrado = numeros.findIndex(function(numero) {
    return numero > 4;
});
console.log(indexNumeroEncontrado); // 4



// CICLOS LOOPS ------------------------------------------------------------
// en js usamos el for tal como en c++ 
for (let index = 0; index < 5; index++) {
    consol.log(i);
}
// o si recorremos un array a denas de la forma anterior tambien podemos usar 
for (var num of numeros) {
    consol.log(num);
}
// tambien otro ciclo que tenemos a disposicion es el while y es igual que en c++
while (numeros.length>0) {
    console.log(numeros)
    numeros.shift()
}

// OBJECTS -----------------------------------------------------------------
// js tambien maneja objetos los cuales podemo declarar de la siguienete manera 
var persona = {
    nombre:"carlos",
    edad:20,
    cc:1002275199
}
// de esta forma podriamos decir que es lo mismo que un diccionario de python poe majenar clave : valor por cada atributo que tiene 
// a demas de aceder a cada atributo escribiendom el nombre del onbjeto punto y el atributo ejp
console.log(persona.nombre) 
// ademas  podemos declararle metodos ejp
var persona = {
    nombre:"carlos",
    edad:20,
    cc:1002275199,
    saludo: function () {
        console.log(`hola soy ${this.nombre} y tengo  ${this.edad} anios`);
    }
}
person.saludo();

// pero tambien podemos manejarlos como obejetos en c++ creando un contructor para asignar sus atributos a demas de declara sus metodos ejp

function person(nombre, apellido, edad, phone) {
    this.nombre = nombre;
    this.apellido = apellido;
    this.edad = edad;
    this.phone = phone;

    this.saludo = function (){
        console.log(`hola soy ${this.nombre} y tengo  ${this.edad} anios`);
    }
}
var pesona1 = new person("carlos","aagamez",21,3017450991);





// calcule la suma de los terminos de la serie de FIBONACCI
// cuyos valores se encuentran entrre 100 y 10,000 