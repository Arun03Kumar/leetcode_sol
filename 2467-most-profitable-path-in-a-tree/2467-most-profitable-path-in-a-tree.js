/**
 * @param {number[][]} edges
 * @param {number} bob
 * @param {number[]} amount
 * @return {number}
 */
var mostProfitablePath = function(edges, bob, amount) {
    const n = amount.length;
    const adj = new Array(n).fill(0).map(() => []);
    for(const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const bobMap = new Map();

    function dfsBob(curr, time, visited) {
        visited.add(curr);
        bobMap.set(curr, time);

        if(curr === 0) return true;

        for(const nbr of adj[curr]) {
            if(!visited.has(nbr)) {
                if(dfsBob(nbr, time + 1, visited)) {
                    return true;
                }
            }
        }

        bobMap.delete(curr);
        return false;
    }

    let ans = -Infinity;

    function dfsAlice(curr, time, income, visited) {
        visited.add(curr);

        if(!bobMap.has(curr) || time < bobMap.get(curr)) {
            income += amount[curr];
        }
        else if(time === bobMap.get(curr)) {
            income += amount[curr] / 2;
        }

        if(adj[curr].length === 1 && curr != 0) {
            ans = Math.max(ans, income);
        }

        for(const nbr of adj[curr]) {
            if(!visited.has(nbr)) {
                dfsAlice(nbr, time + 1, income, visited);
            }
        }
    }

    const visitedBob = new Set();
    dfsBob(bob, 0, visitedBob);

    const visitedAlice = new Set();
    dfsAlice(0, 0, 0, visitedAlice);

    return ans;
};