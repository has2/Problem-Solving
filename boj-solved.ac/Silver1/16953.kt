import java.util.*
import kotlin.collections.HashSet
val bw = System.`out`.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()){
    var (A,B) = readLine().split(' ').map{it.toLong()}
    var st = HashSet<Long>()
    var q:Queue<Long> = LinkedList<Long>()
    q.add(A)
    st.add(A)
    var ans=0
    while(!q.isEmpty()){
        var sz = q.size
        ans++
        while(sz-->0) {
            var cur = q.poll()
            if(cur==B){
                bw.write("$ans")
                bw.flush()
                return
            }
            if (cur * 2 <= B && !st.contains(cur * 2)) {
                st.add(cur * 2)
                q.add(cur * 2)
            }
            if (cur * 10 + 1 <= B && !st.contains(cur * 10 + 1)) {
                st.add(cur * 10 + 1)
                q.add(cur * 10 + 1)
            }
        }
    }
    bw.write("-1")
    bw.flush()
}