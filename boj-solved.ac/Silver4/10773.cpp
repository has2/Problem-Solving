import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var k = readLine().toInt()
    var st = Stack<Int>()
    while(k-->0){
        var ip = readLine().toInt()
        when(ip){
            0 -> st.pop()
            else -> st.push(ip)
        }
    }
    var ans = 0
    while(!st.empty()) ans += st.pop()
    println(ans)
}