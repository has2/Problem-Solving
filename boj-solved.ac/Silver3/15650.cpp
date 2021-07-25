import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
var N=0
var M=0
var used = Array<Boolean>(9){false}
fun sol(n:Int,k:Int){
    if(k==M){
        for(i in 1..N){
            if(used[i]) print("$i ")
        }
        println()
        return;
    }
    if(n>N) return;
    used[n]=true
    sol(n+1,k+1)
    used[n]=false
    sol(n+1,k)
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var ip = readLine().split(' ').map{it.toInt()}
    N=ip[0]
    M=ip[1]
    sol(1,0)
}