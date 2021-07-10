import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*
import kotlin.collections.HashSet
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var (N,M) = readLine().split(' ').map{it.toInt()}

    var st = HashSet<String>()
    var arr = mutableListOf<String>()
    while(N-->0) st.add(readLine())
    while(M-->0){
        var s = readLine()
        if(st.contains(s)) arr.add(s)
    }
    arr.sort()
    println(arr.size)
    for(a in arr) println(a)
}