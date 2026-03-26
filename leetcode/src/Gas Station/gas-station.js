/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    

    for (let i = 0; i < gas.length; i++) {
        if (cost[i] > gas[i]) continue;

        let index = i;
        let tank = 0;
        let counter = 0;
        while (counter < gas.length) {
            const dynamicIndex = index < gas.length ? index : index % gas.length;
            tank = tank 
                + gas[dynamicIndex] 
                - cost[dynamicIndex]
            if (tank < 0) break;
            counter++;
            index++;
        }
        if (counter === gas.length && tank >= 0) {
            return i;
        }
    }

    return -1;
};
/**
 * N gas stations
 * circular route
 * begin the journey with an empty tank
 * at one of the gas stations
 * 
 */


console.log(canCompleteCircuit([1, 2, 3, 4, 5], [3, 4, 5, 1, 2]))