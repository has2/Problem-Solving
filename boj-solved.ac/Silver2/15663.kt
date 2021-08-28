import java.util.*
import kotlin.collections.HashSet
val bw = System.`out`.bufferedWriter()
val st = HashSet<String>()
var N=0;
var M=0
lateinit var arr : List<Int>
lateinit var used : BooleanArray
fun sol(str:String){
    if(str.filter { it=='#' }.length  == M) {
        var ret = str.replace('#', ' ')
        if(!st.contains(ret)) {
            st.add(ret)
            bw.write(ret+'\n')
        }
        return;
    }
    for(i in 0 until N){
        if(!used[i]){
            used[i]=true
            sol(str+arr[i].toString()+"#")
            used[i]=false;
        }
    }
}
fun main() = with(System.`in`.bufferedReader()){
    var ip = readLine().split(' ').map{it.toInt()}
    N=ip[0]; M=ip[1]
    arr = readLine().split(' ').map { it.toInt() }
    used = BooleanArray(N)
    arr = arr.sorted()
    sol("")
    bw.close()
}