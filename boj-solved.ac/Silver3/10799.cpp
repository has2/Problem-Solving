import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var s = readLine()
    var cnt=0
    var ans=0
    var i=0
    while(i<s.length){
        when(s[i]){
            '('->{
                if(s[i+1]==')') {
                    ans+=cnt
                    i++
                }
                else cnt++
            }
            else->{
                ans++
                cnt--
            }
        }
        i++
    }
    println(ans)
}
