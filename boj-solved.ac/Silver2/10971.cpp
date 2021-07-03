import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.util.*
var N=0
val cost = Array(10,{Array(10){0}})
val visit = Array(10){false}
var ans=987654321
fun sol(start:Int,n:Int,sum:Int,cnt:Int){
    visit[n]=true
    //println("n:${n}, sum:${sum}, cnt:${cnt}")
    if(cnt==N && cost[n][start]>0){
        ans=min(ans,sum+cost[n][start])
    }
    for(i in 0 until N){
        if(cost[n][i]>0 && !visit[i]){
            sol(start,i,sum+cost[n][i],cnt+1)
        }
    }
    visit[n]=false
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    N=readLine().toInt()
    for(i in 0 until N){
        var ip = readLine().split(' ').map{it.toInt()}
        for(j in 0 until N) cost[i][j]=ip[j]
    }
    for(i in 0 until N) {
        sol(i,i, 0, 1)
    }
    println(ans)
}