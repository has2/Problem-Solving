import java.lang.Integer.min
import java.util.*
const val inf = 20000001
var cost = Array(201){IntArray(201){inf} }
class Solution {
    fun solution(n: Int, s: Int, a: Int, b: Int, fares: Array<IntArray>): Int {
        var answer = inf
        for(v in fares){
            cost[v[0]][v[1]]=v[2]
            cost[v[1]][v[0]]=v[2]
        }
        for(i in 1..n) cost[i][i]=0

        for(k in 1..n){
            for(i in 1..n){
                for(j in 1..n){
                    if(cost[i][j] > cost[i][k]+cost[k][j]){
                        cost[i][j] = cost[i][k]+cost[k][j]
                        cost[j][i] = cost[i][j]
                    }
                }
            }
        }
        for(i in 1..n) answer = min(answer, cost[i][s] + cost[i][a] + cost[i][b])
        
        return answer
    }
}