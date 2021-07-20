import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var (N,M) = readLine().split(' ').map{it.toInt()}
    val arr = readLine().split(' ').map{it.toInt()}
    val sum = Array<Int>(N){0}
    sum[0]=arr[0]
    for(i in 1 until N) sum[i] = sum[i-1]+arr[i]
    while(M-->0){
        val ip = readLine().split(' ')
        val i = ip[0].toInt()
        val j = ip[1].toInt()
        println(sum[j-1]-(if(i==1) 0 else sum[i-2]))
    }
}