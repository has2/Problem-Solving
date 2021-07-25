import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
var N=0
var M=0
var used = Array<Int>(9){0}
fun sol(n:Int,k:Int){
    if(k==M){
        for(i in 1..N){
            repeat(used[i]){
                print("$i ")
            }
        }
        println()
        return;
    }
    if(n>N) return;
    used[n]++
    sol(n,k+1)
    used[n]--
    sol(n+1,k)
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var ip = readLine().split(' ').map{it.toInt()}
    N=ip[0]
    M=ip[1]
    sol(1,0)
}