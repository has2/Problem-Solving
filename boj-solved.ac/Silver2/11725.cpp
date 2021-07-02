import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
var n=0
var adj = Array<ArrayList<Int>>(100001){ArrayList<Int>()}
var visit = Array<Boolean>(100001){false}
var par = Array<Int>(100001){0}
fun dfs(m:Int){
    visit[m]=true
    for(nxt in adj[m]){
        if(!visit[nxt]){
            par[nxt]=m
            dfs(nxt)
        }
    }
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var n = readLine().toInt()
    var a = MutableList<Int>(0){0}
    var k =n-1
    while(k-->0){
        var ip = readLine().split(' ').map{it.toInt()}
        adj[ip[0]].add(ip[1])
        adj[ip[1]].add(ip[0])
    }
    dfs(1)

    for(i in 2..n){
        println(par[i])
    }
}