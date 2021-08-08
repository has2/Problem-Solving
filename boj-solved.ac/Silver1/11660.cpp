import java.util.*
val bw = System.`out`.bufferedWriter()
var sum = Array(1025){IntArray(1025)}
fun main() = with(System.`in`.bufferedReader()){
    val (N,M) = readLine().split(' ').map{it.toInt()}
    for(i in 1..N){
        val r = readLine().split(' ').map{it.toInt()}
        for(j in 1..N)  sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+r[j-1]
    }
    repeat(M){
        val (y1,x1,y2,x2) = readLine().split(' ').map{it.toInt()}
        val ret = sum[y2][x2]-sum[y1-1][x2]-sum[y2][x1-1]+sum[y1-1][x1-1]
        bw.write(ret.toString()+'\n')
    }
    bw.flush()
}