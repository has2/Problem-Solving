import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val pq = PriorityQueue<Int>{a,b->b.compareTo(a)}
    var N = readLine().toInt()
    repeat(N){
        var v = readLine().toInt()
        when{
            v>0 -> pq.add(v)
            pq.isEmpty() -> println(0)
            else -> println(pq.poll())
        }
    }
}