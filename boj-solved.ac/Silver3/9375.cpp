import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var tc = readLine().toInt()
    while(tc-->0) {
        var N = readLine().toInt()
        val mp = HashMap<String, Int>()
        for(i in 0 until N) {
            val a = readLine().split(" ")[1]
            if(mp.containsKey(a)) mp[a] = 1+mp[a]!!
            else mp[a] = 1
        }
        var ans=1
        for(a in mp.values) ans*=(a+1)
        println(ans-1)
    }
}