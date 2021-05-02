import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) = with(BufferedReader(InputStreamReader(System.`in`))){
    var n = readLine().toInt()
    var s = Stack<Int>()
    while(n-->0){
        var rd = readLine().split(" ")

        val ret = when(rd[0]){
            "push" -> {
                var v = rd[1].toInt()
                s.push(v)
                null
            }
            "pop" -> {
                if(!s.empty()) s.pop()
                else -1
            }
            "top" -> {
                if(!s.empty()) s.peek()
                else -1
            }
            "size" -> s.size
            else -> {
                if(s.empty()) 1
                else 0
            }
        }
        ret?.let{println(ret)}
    }
}