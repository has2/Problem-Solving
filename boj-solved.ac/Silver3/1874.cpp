import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    var n = readLine().toInt()
    val st = Stack<Int>()
    val arr = IntArray(n)
    for(i in 0..n-1) arr[i]=readLine().toInt()
    var idx=0;
    var ans=ArrayList<Char>()
    for(i in 1..n){
        st.push(i)
        ans.add('+')
        while(!st.empty() && st.peek()==arr[idx]){
            st.pop()
            ans.add('-')
            idx++
        }
    }
    if(!st.empty()) println("NO")
    else for(c in ans) println(c)
}