
const { Map } = require('immutable');

console.log('Fibonacci task');

let memory =  Map();
console.log(memory.set(10,100));


const input = 100;
let counter = 0;

const fubinocci = function calculateFibonaci(n) {
    counter++;
    
    if(memory.has(n)){
        return memory.get(n);
    }
    if(n === 0){
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    let prevElement = calculateFibonaci(n - 1);
    if(!memory.has(n-1)) {
        memory = memory.set(n-1,prevElement);
    }
    let prevPrevElement = calculateFibonaci(n-2);
    if(!memory.has(n-2)){
        memory = memory.set(n-2,prevPrevElement);
    }
    return prevElement + prevPrevElement;
}

console.log(fubinocci(input),' counter: ',counter);

