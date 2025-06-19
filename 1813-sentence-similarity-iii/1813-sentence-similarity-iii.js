/**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */
var areSentencesSimilar = function(sentence1, sentence2) {
    let words1 = sentence1.split(" ")
    let words2 = sentence2.split(" ")

    if(words1.length > words2.length) {
        [words1, words2] = [words2, words1]
    }

    let i = 0;

    while(i < words1.length && i < words2.length && words1[i] == words2[i]) i++;

    let j = words1.length - 1
    let k = words2.length - 1

    while(j >= i && words1[j] == words2[k]) {
        j--;
        k--;
    }

     return j < i;
};