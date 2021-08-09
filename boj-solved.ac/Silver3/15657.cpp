import java.util.*
val bw = System.`out`.bufferedWriter()
var N=0
var M=0
lateinit var arr:List<Int>
fun sol(n:Int,s:String){
    if(s.filter { it==' ' }.length==M){
        bw.write(s.trim()+'\n')
        return
    }
        for(i in n until N){
        sol(i, "$s ${arr[i]}")
    }
}
fun main() = with(System.`in`.bufferedReader()){
    val ip = readLine().split(' ').map { it.toInt() }
    N=ip[0]
    M=ip[1]
    arr = readLine().split(' ').map{it.toInt()}
    arr = arr.sortedWith{a,b-> a.compareTo(b)}
    sol(0,"")
    bw.close()
}