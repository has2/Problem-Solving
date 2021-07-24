import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var (N,M) = readLine().split(' ').map{it.toInt()}
    val mp = HashMap<String,String>()
    repeat(N){
        var ip = readLine().split(' ')
        mp[ip[0]]=ip[1]
    }
    repeat(M){
        println(mp[readLine()])
    }
}