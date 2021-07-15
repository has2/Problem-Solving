import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val pq = PriorityQueue<Int>()
    var N = readLine().toInt()
    while(N-->0){
        var k = readLine().toInt()
        when(k){
            0 -> {
                var t = 0
                pq.poll()?.let{
                    t+=it
                }
                println(t)
            }
            else -> pq.add(k)
        }
    }
}