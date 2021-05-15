import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.*
fun gcd(n:Int,m:Int):Int{
    var a=n
    var b=m
    if(a>b) a=b.also{b=a}

    while(a>0){
        var c = b%a
        b=a
        a=c
    }
    return b
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val ip = readLine().split(' ')
    val N = ip[0].toInt()
    val S = ip[1].toInt()
    val arr = readLine().split(' ').map { abs(S-it.toInt()) }
    var prev=arr[0]
    for(a in arr) prev=gcd(a,prev)
    println(prev)
}
