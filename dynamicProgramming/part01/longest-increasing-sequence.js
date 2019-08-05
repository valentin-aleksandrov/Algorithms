console.log('lis');

const input = '3 14 5 12 15 7 8 9 11 10 1';
const numbers = input
    .split(' ')
    .map((str)=>Number(str));
console.log(numbers);

const lengths = Array
    .from({length: numbers.length})
    .map((_)=>1);
const prevs = Array
    .from({length: numbers.length})
    .map((_)=>-1);
console.log(lengths);
console.log(prevs);

let maxLen = 0;
let lastIndex = -1;
for (let i = 0; i < numbers.length; i++) {
    lengths[i] = 1;
    prevs[i] = -1
    for (let j = 0; j < i; j++) {
        if(numbers[j] < numbers[i]){
            const currentLength = lengths[j]+1;
            const maxsum = Math.max(currentLength,lengths[i]);
            if(maxsum > lengths[i]){
                prevs[i]=j;
                lastIndex = i;
            }
            
            lengths[i] = maxsum;
            maxLen = Math.max(lengths[i],maxLen);
        }
    }
}
console.log(lengths);
console.log(maxLen);
console.log(prevs);
console.log('last index: ',lastIndex);
const sequnce = [];
while(lastIndex != -1){
    sequnce.push(numbers[lastIndex]);
    lastIndex = prevs[lastIndex];
}
console.log(sequnce.reverse());






