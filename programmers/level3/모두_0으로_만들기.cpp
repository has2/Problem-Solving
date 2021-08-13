import java.util.*
import kotlin.math.abs
const val mxN = 300000
var adj = Array(mxN){ mutableListOf<Int>()}
var b = LongArray(mxN)
var ans=0L
fun dfs(par:Int,n:Int):Long{
    var ret = b[n]
    for(i in 0..adj[n].size-1){
        if(adj[n][i]!=par) ret+=dfs(n,adj[n][i])
    }
    ans+=abs(ret)
    return ret
}
class Solution {
    fun solution(a: IntArray, edges: Array<IntArray>): Long {
        for(i in a.indices) b[i]=a[i].toLong()
        for((u,v) in edges){
            adj[u].add(v)
            adj[v].add(u)
        }
        if(dfs(-1,0)!=0L) ans=-1
        return ans
    }
}