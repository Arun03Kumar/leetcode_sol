/**
 * @param {string[]} words
 * @param {number[][]} queries
 * @return {number[]}
 */

const isVowel = (ch) => 'aeiou'.includes(ch);

var vowelStrings = function(words, queries) {
   let prefix = new Array(words.length + 1).fill(0);

   for(let i = 0; i < words.length; i++) {
        let curr = words[i];
        if(isVowel(curr[0]) && isVowel(curr[curr.length - 1])) {
            prefix[i + 1] += prefix[i] + 1;
        }
        else prefix[i + 1] = prefix[i];
   } 

   const ans = []
   for(const [l, r] of queries) {
        ans.push(prefix[r + 1] - prefix[l])
   }

   return ans;
};