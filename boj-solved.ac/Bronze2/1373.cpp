import java.io.BufferedReader
import java.io.InputStreamReader
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var n = readLine()
    n = n.reversed()
    val arr = listOf(1,2,4)
    var ans=StringBuilder()
    for(i in n.indices step 3){
        var t=0
        for(j in 0..2){
            if(i+j>=n.length) break
            t+=arr[j]*(n[i+j]-'0')
        }
        ans.append(t.toString())
    }
    println(ans.reverse())
}
