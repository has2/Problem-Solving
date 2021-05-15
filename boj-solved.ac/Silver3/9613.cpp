import java.io.BufferedReader
import java.io.InputStreamReader
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
    var t = readLine().toInt()
    val arr = IntArray(101)
    while(t-->0){
        val ip=readLine().split(' ')
        val N=ip[0].toInt()
        for(i in 1..N) arr[i-1]=ip[i].toInt()
        var ans:Long=0
        for(i in 0 until N-1){
            for(j in i+1 until N){
                ans+=gcd(arr[i],arr[j])
            }
        }
        println(ans)
    }
}
