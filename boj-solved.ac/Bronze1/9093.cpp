import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var n = readLine().toInt()
    while(n-->0){
        var sp = readLine().split(" ");
        for(a in sp){
            print(a.reversed()+' ')
        }
        println()
    }
}