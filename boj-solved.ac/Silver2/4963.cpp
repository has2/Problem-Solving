import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
val mxN = 250000
var Primes = Array(mxN+1){true}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    for(i in 2..mxN/2){
        if(!Primes[i]) continue
        for(j in i*2..mxN step i) Primes[j] = false
    }
    while(true){
        var k=readLine().toInt()
        if(k==0) break
        var ans = 0
        for(i in k+1..2*k) if(Primes[i]) ans++
        println(ans)
    }
}