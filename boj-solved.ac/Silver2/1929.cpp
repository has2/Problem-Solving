import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var ip = readLine().split(' ')
    var n=ip[0].toInt()
    var m=ip[1].toInt()
    var notPrime = BooleanArray(1000001)
    notPrime[1]=true
    for(i in 2..m){
        if (notPrime[i]) continue
        var j = i*2
        while(j<=m){
            notPrime[j]=true
            j+=i
        }
    }
    for(i in n..m) if(!notPrime[i]) println(i)
}
