/**
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
    citations.sort((a, b) => a - b );

    for (let i = citations.length; i > 0; i--) {
        let counter = 0;
        for (let j = 0; j < citations.length; j++) {
            if (citations[j] >= i) {
                counter++;
            }
        }
        if (counter >= i) {
            return i;
        }
    }

    return 0;
    
};

console.log(hIndex([3, 0, 6, 1, 5]))