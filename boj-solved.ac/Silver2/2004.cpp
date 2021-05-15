import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min
fun get(p:Int,k:Int):Int{
    var cnt=0
    var n=p
    while(n>0){
        n/=k
        cnt+=n
    }
    return cnt
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val ip=readLine().split(' ')
    val N=ip[0].toInt()
    val M=ip[1].toInt()
    val a = get(N,2)-get(N-M,2)-get(M,2)
    val b = get(N,5)-get(N-M,5)-get(M,5)
    println(min(a,b))
}
