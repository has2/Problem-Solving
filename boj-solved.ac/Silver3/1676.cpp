import java.io.BufferedReader
import java.io.InputStreamReader
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val N=readLine().toInt()
    var cnt:Int=0
    for(i in 1..N) {
        var j=i
        while(j>0 && j%5==0){
            cnt++
            j/=5
        }
    }
    println(cnt)
}
