import java.io.BufferedReader
import java.io.InputStreamReader
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var input = readLine().split(' ')
    var n = input[0].toInt()
    var m = input[1].toInt()
    var arr = readLine().split(' ').map{it.toInt()}
    var ans=0
    var sum=0
    var l=0
    for(i in 0..arr.size-1) {
        sum += arr[i]
        if (sum > m) {
            while (l < i && sum > m) sum -= arr[l++]
        }
        if(sum == m) ans++
    }
    println(ans)
}