import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
const val mxN = 1 shl 31
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val minHeap = PriorityQueue<Int>()
    val maxHeap = PriorityQueue<Int>{a,b->b.compareTo(a)}
    repeat(readLine().toInt()){
        val v = readLine().toInt()
        when{
            v==0->{
                var ret=0
                if(!minHeap.isEmpty() || !maxHeap.isEmpty()){
                    ret = when {
                        minHeap.isEmpty() -> maxHeap.poll()
                        maxHeap.isEmpty() -> minHeap.poll()
                        else -> if(abs(minHeap.peek()) < abs(maxHeap.peek())) minHeap.poll() else maxHeap.poll()
                    }
                }
                println(ret)
            }
            v<0 -> maxHeap.add(v)
            else -> minHeap.add(v)
        }
    }
}